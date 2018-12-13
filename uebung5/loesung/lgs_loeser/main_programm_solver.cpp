#include <iostream>
#include <fstream>

#include "vector_funcs.h"
#include "matrix_funcs.h"
#include "solver_funcs.h"

// my includes
#include <cmath>

using namespace std;


void write_vector_to_file(Vector const &sol,string filename){

  ofstream file(filename.c_str());
  int nsize(sol.size());

  for(int i=0;i<nsize;++i)
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

    (A*x).print("[A*x]");   // Aufruf der Print-Methode des von der Berechnung zurueck gelieferten Vector-Objekts.
    						// Deshalb braucht man die Klammern!

    write_vector_to_file(x,"cg_test.dat");

    // ----------------------------------


    // ----------------------------------
    // 2. LU solver
    // ----------------------------------

    cout << "=== LU solver: ===" << endl;
    
    Matrix A2(A);
    
    Vector x2 = lu_solve(A2,b);
    
    x2.print("x2");
    
    write_vector_to_file(x2,"lu_test.dat");

    
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

    int  M; //Anzahl der Stuetzstellen (Diskretisierung)
    cout<<"Anzahl der Stuetzstellen M: "<<endl;
    cin>>M;

    double const h = L/double(M-1); //Schrittweite

    double const c = h*h/k; //h^2/k -> delta_L^2/k

    //Aufstellen LGS: A_w*x_w = b_w
    //Anlegen (Deklarieren) der notwenigen Vektoren und Matrix

    Vector x_w(M);
    Vector b_w(M);
    Matrix A_w(M, M);

    Vector a_w(M); //Hilfsvariable a_w(i) = i^2*h^2/L^2;

    //TODO: Initialisierung a_w
    for (int i = 0; i < M; i++){ // bis M-1, da wir bei 0 Anfangen und M Stuetzstellen haben
    	// Konventionskoeffizient
    	a_w(i) = (double(i*i)*h*h)/(L*L);
    	//a_w(i) = pow(double(i), 2.0)*pow(h, 2.0)/pow(L, 2.0); // calculation with cmath~pow ist power of 1. Argument zu ^2.Argument
    }

    //TODO: Initialisierung A_w

    A_w.operator =(0.);
    // entspricht A_w = 0;

    // initialisierung mit Operator fuer 'fill with same value' aus der Matrix-Klasse!
    /* Alles mit 0 initialisieren, damit man sich im Anschluss nur noch um die interessanten Matrixelemente
     * kuemmern muss und keine Elemente unbeschrieben sind. Das wuerde zu einem Zugriffsfehler fuerhen! (?)
     * -> TODO: Probiere ohne die 0 initialisierung aus, wenn es laeuft!
     */


    //TODO: Kopplungsterme in Matrix schreiben: nur "innere Knoten werden betrachtet
    for (int j = 1; j < M-1; j++){
    	// j=1, da wir die Nullte Zeile ignorieren. Dort steht in der urspruenglichen Matrix nichts drin!
    	// und j<M-2, da wir unten an der Matrix auch die Randbedingung geltend haben.
    	A_w(j, j+1) = -1.;
    	A_w(j, j) = (2.0 + a_w(j)*c); // Diagonalelemente
    	A_w(j, j-1) = -1.;
    }

    // letztes Element ist eine 1
    A_w(0,0) = 1.;
    A_w(M-1, M-1) = 1.;

    //TODO: Knoten 0 und Knoten M-1 : Randbedingung werden eingebaut

    for (int k = 1; k < M; k++){
    	b_w(k) = a_w(k) * T_e * c;
    	// debug
    	//std::cout << "b_w of k = " << k << " is: " << b_w(k) << std::endl;
    }

    // Durch die Direclet-Randbedingung gegeben
    b_w(0) = T_0;
    b_w(M-1) = T_L;

    //TODO: A_w muss symmetrisch sein: Anpassen der Matrix A_w und rechten Seite b_w

    	/*
    	 * vgl handschriftliche Rechnung. Ich muss die Randbedingungen anpassen, sodass eine symetische Matrix entsteht. Dafuer muessen -1 auf Element [0][1] und [M-1][M-2] der Systemmatrix A_w
    	 */
    A_w(1, 0) = 0.;
    A_w(M-2, M-1) = 0.;
    
    // TODO: Das geht fuer den direkten Loeser (LU-Zerlegung) nicht!)
    b_w(1) = b_w(1) + T_0;			// hier wird entsprechend der Wert aus der vorrangegangenen Iteration des Loesungsvektors verwendet!
    b_w(M-2) = b_w(M-2) + T_L;


    // debug: Check ob die Vektoren richtig aussehen
    std::cout << "A_w: " << std::endl;
    A_w.print();
    std::cout << "b_w: " << std::endl;
    b_w.print();
    std::cout << "a_w: (Hilfsvariable fuer den Konvektionskoeffizienten)" << std::endl;
    a_w.print();

    //TODO: Anfangswerte x_w0 (best guess): z.B. lineare Interpolation

    Vector x_w0(M); // Deklariere Anfangswerte-Vektor fuer den Iterativen Loeser
    // Beschriebe diesen mit Anfangswerten
    for (int l = 0; l < M; l++){
    	x_w0(l) = l*(double(T_L)-double(T_0))/(double(L))+T_0; // Geradengleichung mit Anfangs- und Endpunkt T_0 bzw T_L
    }

    // debug
    std::cout << "Start-Loesungsvektor fuer den Iterativen CG-Solver x_w0: " << std::endl;
    x_w0.print();

    //TODO: Loesung mit CG-Solver

    Vector lsgVectorCG(M);
    lsgVectorCG = cg_solve(x_w0, A_w, b_w);
    lsgVectorCG.print("CG-Loesungsvektor: ");

    write_vector_to_file(lsgVectorCG,"cg_result.dat");

    //TODO: Loesung mit LU-Solver:

    Vector lsgVectorLU(M);
    lsgVectorLU = lu_solve(A_w, b_w);
    lsgVectorLU.print("LU-Loesungsvektor: ");
    write_vector_to_file(lsgVectorLU,"lu_result.dat");


    return 0;
}
