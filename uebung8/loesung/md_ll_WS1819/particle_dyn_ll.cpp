#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "particle.h"
#include "verlet.h"
#include "linked_list.h"
#include "interaction_lj.h"
using namespace std;

//globale Variablen:

particle * Teilchen;      // Erstelle Teilchen Array Pointer -> wird in init_structure mit Referenz versehen!
unsigned int ntot;        // Anzahl an Teilchen

// Deklarationen: Routinen in dieser Datei - um in main-Methode drauf zugreifen zu koennen, ohne die definition komplett hin schreiben zu muessen!
void init_structure(const string &);
void force_calculation(particle * const ,const unsigned int  ntot,void force(particle*const ,particle*const));
void euler_dynamics(particle*const, const unsigned int ntot,const double dt);
void write_structure(particle *p,const unsigned int nmax,const unsigned int nstep);

// Hauptprogramm:
//  ! length in units of [sigma]
//  ! energy in units of [eps]
//  ! force in units of [eps/sigma]
//  ! mass in units if [m]
//  ! time in units of [sigma sqrt(m/eps)]
//  ! velocity in units of [sqrt(sigma/m)]

int main(){
    string filename;
    unsigned int nchoice;
    unsigned int nstep;
    //Zeitintervall:
    double time,time_max,dt;
    // Groesse des Simulationsgebietsx, Shift und Gitterkonstante:
    double L[dim],XOFF[dim],gitter_konstante;

    // Abschneideradius fuer  LJ - Potenzial
    double rcut;


    // Eingabe:
    cout<<"Anfangsbedingungen der Teilchen in Datei: ";
    cin >> filename;
    cout<<"Box: Lx,Ly Einheit[a] (a: Gittekonstante)"<<endl;
    cin>>L[0]>>L[1];
    cout<<"Offset:";
    cin>>XOFF[0]>>XOFF[1];
    cout<<"Gitterkonstante a [sigma]:";
    cin>>gitter_konstante;
    cout<<"Abschneideradius [sigma]:";
    cin>>rcut;

    // Einlesen der Anfangsstruktur:
    init_structure(filename);

    // Simulationsparameter:
    cout<< "zu simulierende Zeitspanne:";
    cin >> time_max;
    cout<< "Zeitschritt dt:";
    cin >> dt;

    // Skalierung der Geometrie mit Gitterkonstanten:
    for(auto i=0;i<ntot;i++){
        for(auto j=0;j<dim;j++){
            Teilchen[i].pos[j]+=XOFF[j];
            Teilchen[i].pos[j]*=gitter_konstante;
        }
    }
    L[0]*=gitter_konstante;
    L[1]*=gitter_konstante;

    // Vorbereitung: Nachbarschaftsliste:
    init_linked_list(L,rcut,ntot);          // Erstellt ll und lc und initialisiert mit -1
    print_neighour_list();
    setup_neighbour_list(Teilchen,ntot);    // Erstellt die tatsaechlichen ll und lc fuer die Anfangskonfiguration
    print_neighour_list();

    cout<<"1: Euler (1)"<<endl;
    cout<<"2: Verlet/einfach:"<<endl;
    cout<<"3: Verlet/linked list:"<<endl;

    do{
        cin >>nchoice;
    }while(nchoice<1 || nchoice>3);

    // Hauptteil:

    time=0;
    nstep=0;

    if(nchoice==3) {
        // Verlet Verfahren mit Nachbarschaftslisten
        init_verlet(Teilchen,ntot);
        while(time<time_max){
            setup_neighbour_list(Teilchen,ntot);                    // Update der ll und lc: Hier werden die ll und lc geschrieben, basierend auf dem Array 'Teilchen', welches alle Atome beinhaltet
            time+=dt;
            update_positions(Teilchen,ntot,dt);                     // Berechne neue Geschwindigkeiten und neue Positionen
            force_calculation_neighbour(Teilchen,ntot,force_lj);    // Berechne Kraft auf Teilchen -> hier kommt ll und lc ins Spiel!
            update_velocities(Teilchen,ntot,dt);                    // Normaler Verlet zur Berechnung von v
            write_structure(Teilchen,ntot,nstep);                   // Schreibe die berechneten Werte in eine Datei
            nstep++;
        }
    } // REST fuer andere Verfahren
    else if(nchoice==1) {
        //EULER:
        while(time<time_max){
            time+=dt;
            force_calculation(Teilchen,ntot,force_lj);
            euler_dynamics(Teilchen,ntot,dt);
            update_velocities(Teilchen,ntot,dt);
            write_structure(Teilchen,ntot,nstep);
            nstep++;
        }
    }
    else if(nchoice==2) {
        //Verlet: Geschwindigkeits-St�rmer-Verlet
        init_verlet(Teilchen,ntot);
        while(time<time_max){
            time+=dt;
            update_positions(Teilchen,ntot,dt);
            force_calculation(Teilchen,ntot,force_lj);
            update_velocities(Teilchen,ntot,dt);
            write_structure(Teilchen,ntot,nstep);
            nstep++;
        }
    }

    return 0;
}

// Definition der Funktionen


//Euler Integration:

void euler_dynamics(particle *const p,const unsigned int nmax,const double dt){
    for(auto i=0;i<nmax;i++){
        // Position:
        for(auto n=0;n<dim;n++){
            p[i].pos[n]+=p[i].vel[n]*dt;
        }
        // Geschwindigkeit:
        for(auto n=0;n<dim;n++){
            p[i].vel[n]+=p[i].f[n]/p[i].m*dt;
        }
    }
}


// Kraftberechnung: einfachste Methode Ausfuehren einer Doppelsumme
// unter Berueksichtigung von actio=reaktio

void force_calculation(particle *const Teilchen,const unsigned int nmax,
                       void force_p1p2(particle *const p1,particle *const p2)){
    double f[dim];

    // setze alle Kraefte auf Null:
    for(auto i=0;i<nmax;i++)
        for(auto n=0;n<dim;n++)
            Teilchen[i].f[n]=0.;

    for(auto i=0;i<nmax-1;i++){
        for(auto j=i+1; j<nmax;j++){
            // actio=reactio miteingebaut:
            // d.h. nur die Haelfte der Indexpaare (i,j)
            // muss beruecksichtihgt werden.
            force_p1p2(&Teilchen[i],&Teilchen[j]);
        }
    }
}

// Einlesen der Startstruktur mit Anfangsbedingungen
// (Geschwindigkeit)

void init_structure(const string &filename){
    ifstream Datei;

    Datei.open(filename.c_str(),ios::in);

    if(Datei) {
        unsigned int n {0};
        Datei >> ntot;
        cout<<ntot<<endl;
        Teilchen = new particle[ntot];
        while(n<ntot){
            // Struktur einlesen: fuet dim=2 geschrieben
            // (Verallgemeinerung: Uebung)
            Datei >>Teilchen[n].m
                  >>Teilchen[n].pos[0] >> Teilchen[n].pos[1]
                  >>Teilchen[n].vel[0] >> Teilchen[n].vel[1];
            n++;
        }
    }

    Datei.close();

}

void write_structure(particle *const p,const unsigned int nmax,const unsigned int nstep){
    char Dateiname[256];

    ofstream Datei;

    // C Style: Dateinamen zusammensetzen
    sprintf(Dateiname,"lattice%d.dat",nstep);

    // oeffnen der Datei:
    Datei.open(Dateiname);

    // Teilcheninformationen in Datei schreiben:
    for (auto i=0;i<ntot; i++){
        Datei<< 1.<<" "; // Einheitsmasse
        Datei <<p[i].pos[0] <<" "<<p[i].pos[1]<<" "
              <<p[i].vel[0] <<" "<<p[i].vel[1]<<endl;
    }

    Datei.close(); // Datei schliessen


}
