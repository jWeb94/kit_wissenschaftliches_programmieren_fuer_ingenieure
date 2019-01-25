#include <iostream>
#include <fstream>
#include <omp.h>  // fuer die Zeitmessung des CG Teils benötigt

#include "vector_funcs.h"
#include "matrix_funcs.h"
#include "solver_funcs.h"

using namespace std;


void write_vector_to_file(Vector const &sol,string filename){
  
  ofstream file(filename.c_str());
  auto nsize(sol.size());

  for(auto i=0;i<nsize;++i)
    file<<i<<" "<<sol(i)<<endl;

  file.close();
};




int main(int argc, char* argv[]){

    const int dim = 2;


    // ------- define LGS A*x = b -------
    // hier muessen Sie die Matrix A, sowie die Vektoren b und x erstellen
    // Verwenden Sie die Variable dim, um die Konstruktoren aufzurufen
    // ----------------------------------

    Matrix A(dim,dim);
    A(0,0) = 3.;    A(0,1) = 1.;
    A(1,0) = 1.;    A(1,1) = 6.;
    A.print();
    
    Vector b(dim), x(dim);
    b(0) = +2.;
    b(1) = -8.;
    b.print("b");
    
    // ----------------------------------
    // 1. CG solver
    // ----------------------------------
    cout << "=== CG solver: ===" << endl;
    // definiere Startwert phi0 fuer CG-Iteration
    Vector x0(dim);
    x0(0) = 1.;	x0(1) = 1.;
    // rufe cg_solve auf
    x = cg_solve ( x0, A, b );
    // output: A,b,x
    b.print("b");
    x.print("x:");
    // ueberpruefe die Loesung 

    (A*x).print("[A*x]");
  
    // ----------------------------------


    // ----------------------------------
    // 2. LU solver
    // ----------------------------------

    cout << "=== LU solver: ===" << endl;
    
    // Achtung, lu_solve ueberschreibt die Matrix --> mache backup:
    Matrix A2(A);
    
    Vector x2 = lu_solve(A2,b);
    
    x2.print("x2");
    
    
    // ----------------------------------
    // Aufgabe 3: Waermeleitproblem
    // ----------------------------------

    cout << "=== Waermeleitproblem: ===" << endl;


    double T_0, T_L, T_e, k, L;
    // Dirichlet Randbedingungen am Anfang T_0 und Ende T_L des Stabes
    // diese Knoten müssen später besonders behandelt werden

    cout<<"Eingabe der Temperaturen T_0, T_L und T_e: "<<endl;
    cin>>T_0>>T_L>>T_e;

    cout<<"Waermeleitkoeffizient k: "<<endl;
    cin>>k;

    cout<<"Stablaenge L: "<<endl;
    cin>>L;

    unsigned int  M; //Anzahl der Stuetzstellen (Diskretisierung)
    cout<<"Anzahl der Stuetzstellen M: "<<endl;
    cin>>M;

    double const h = L/double(M-1); //Schrittweite

    double const c = h*h/k; //h^2/k

    //Aufstellen LGS: A_w*x_w = b_w
    //Anlegen der notwendigen Vektoren und Matrix

    Vector x_w(M);
    Vector b_w(M);
    Matrix A_w(M, M);

    Vector a_w(M); //Hilfsvariable a_w(i) = i^2*h^2/L^2;

    //Initialisierung a_w
    for(auto i = 0; i<M; i++)
      a_w(i) = double(i*i)*h*h/(L*L);
    //(a_w(0) und a_w(M-1) werden eigentlich nicht benötigt

    //Initialisierung A_w
    A_w = 0.;

    // Kopplungsterme in Matrix schreiben: nur innere Knoten werden betrachtet
    //
    for (auto i = 1; i<M-1; i++){
      A_w(i,i-1) = -1.;
      A_w(i,i+1) = -1.;
      A_w(i,i) = (2. + a_w(i)*c); //Diagonale
    }
    // Knoten 0 und Knoten M-1 : Randbedingungen werden eingebaut
    // durch Setzen der Diagonalelemente auf 1 und
    // Streichen der Werte in Spalte 0 und M-1
    A_w(0,0)     = 1.;
    A_w(M-1,M-1) = 1.;
    
    //A_w muss symmetrisch sein:  Streichen der Werte in Spalte 0 und M-1
    A_w(1,0)     = 0;
    A_w(M-2,M-1) = 0;

    // die soeben entfernten Kopplungen müssen beim Aufbau der rechten Seite
    // berücksichtigt werden
    // RHS (angepasst, um Symmetrie von A_w sicherzustellen: Forderung des CG,...)
    //
    //Initialisierung b_w 
    b_w(0)   = T_0;   // Randbedingungen
    b_w(M-1) = T_L;
    for(auto i = 1; i<M-1; i++)  // für alle inneren Knoten: rechte Seite
      b_w(i) = a_w(i)*c*T_e;
    // für ersten und m-2 ten Knoten: RB einbauen
    b_w(1)   = b_w(1)  +T_0; // b_w(1)   = b_w(1) - A_w(1,0)*T_0   (a_w Wert : -1)
    b_w(M-2) = b_w(M-2)+T_L; // b_w(M-2) = b_w(M-2) - A_w(M-2,M-1)*T_L (a_w Wert: -1)


    //Anfangswerte x_w0 (best guess): lineare Interpolation
    Vector x_w0(M);
    for(auto i = 0; i<M; i++){
        double frac = double(i)/double(M-1);
        x_w0(i) = (1.-frac)*T_0+frac*T_L;
    }

    //Loesung mit CG-Solver
    {
        double time0 = omp_get_wtime();

        x_w = cg_solve (x_w0, A_w, b_w );

        double dt=omp_get_wtime()-time0;
        cout<<"Anzahl der Threads:"<<omp_get_max_threads()<<endl;
        cout<<"CG Loeser ;  Zeit:"<<dt<<endl;
    }
    // Ausgabe: Format Stützstelle  Wert !!

    write_vector_to_file(x_w,"cg_solution.dat");

    // LU solver:
    Matrix A_LU(A_w);
    Vector Tsol_lu(M);
    {
        double time0 = omp_get_wtime();

        Tsol_lu = lu_solve(A_LU,b_w);
        //Loeser ist nicht parallelisiert; die omp Funktion wird nur zur Zeitmessung verwendet
        double dt=omp_get_wtime()-time0;
        cout<<"LU Loeser Zeit:"<<dt<<endl;
    }
    write_vector_to_file(Tsol_lu,"lu_solution.dat");
    
    return 0;
}
