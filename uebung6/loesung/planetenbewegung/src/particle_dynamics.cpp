#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "particle.h"
#include "verlet.h"
using namespace std;

//globale Variablen:

particle *Teilchen; // Zeigervariable auf ein Objekt vom Typ particle (in diesem Fall ein Struct)
                    // Da die Variable global sein soll, muss ich sie nicht loeschen! (Obwohl ich die Speicherverwaltung selbst handhaben muss, wenn ich mit new arbeite!)
                    // Globale Variablen sollen so lange leben wie das Programm selbst!
                    // Variablen auf dem Heap, die nicht geloescht werden, werden am Ende des Programms automatisch wieder freigegeben
size_t ntot;

// Deklarationen:
  /* Damit der Compiler weiss, dass es in der Main Methode diese Funktionen gibt. Beschrieben werden sie weiter unten.
   * Wuerde man das nicht machen, muesste man die Funktionen entweder direkt hier oben beschreiben
   * oder es wuerde ein Compilerfehler entstehen
   */

void init_structure(string);
void force_calculation(particle*const,const int ntot);
void euler_dynamics(particle*const , const int ntot,const double dt);
void ergebnis(const particle*const , const int ntot,const double time,ofstream &);

void energy(const particle * const p, const int nmax, const double time, ofstream & file);


// Hauptprogramm:

int main(){
    string filename;
    string ergfile;
    ofstream ergebnisdatei; // Ergebnis filestream
    ofstream energydatei;
    int nchoice;
    double time,time_max,dt;
    // Eingabe:
    cout<<"Anfangsbedingungen der Teilchen in Datei: "; // Fordere Nutzer zu Eingabe eines config-files auf
    cin >> filename;
    cout<<"Name fuer Ergebnisdatei: ";                  // Fordere Nutzer zur Eingabe eines Namens der Ergebnisdatei auf
    // f�r Ausgabe:
    cin >> ergfile;
    ergebnisdatei.open(ergfile.c_str(),ios::out);       // Erstelle mit filestream object die Ergebnisdatei

    string nameEnergy = "energy_" + ergfile;
    cout << "this is nameEnergy: " << nameEnergy << endl; // debug

    energydatei.open(nameEnergy.c_str(), ios::out);


    // Einlesen der Anfangsstruktur:
    init_structure(filename);

    // Simulationsparameter:
    cout<< "zu simulierende Zeitspanne:";
    cin >> time_max;
    cout<< "Zeitschritt dt:";
    cin >> dt;

    cout<<"Euler (1) oder Verlet (2) Integration: ";
    do{
	cin >>nchoice;
}while(nchoice<1 || nchoice>2); // bleibe in der Schleife bis eine passende Eingabe kommt


    time=0;
    if(nchoice==1) {
	//EULER-Integrationsverfahren:
	while(time<time_max){
	    time+=dt;
	    force_calculation(Teilchen,ntot);
	    euler_dynamics(Teilchen,ntot,dt);
	    ergebnis(Teilchen,ntot,time,ergebnisdatei);
      // Berechnung der Energie und Ausgabe in Datei
      energy(Teilchen,ntot,time,energydatei);
	}
    }
    else if(nchoice==2) {
	//Verlet: Geschwindigkeits-Stoermer-Verlet
	init_verlet(Teilchen,ntot);  // setze alle Kraefte, die auf die Partikel wirken auf 0
	while(time<time_max){
	    time+=dt;
	    update_positions(Teilchen,ntot,dt);
	    force_calculation(Teilchen,ntot);
	    update_velocities(Teilchen,ntot,dt);
	    ergebnis(Teilchen,ntot,time,ergebnisdatei);
      // Berechnung der Energie und Ausgabe in Datei
      energy(Teilchen,ntot,time,energydatei);
	}
    }

    ergebnisdatei.close();
    energydatei.close();
    return 0;
}

// Definition der Funktionen


//Euler Integration:

void euler_dynamics(particle *const p,const int nmax,const double dt){
  // Integration mit euler implizit
  // x_i +/ v_i +  ... wird durch += (Das was auf RHS steht aufaddieren) ersetzt. Es wird also NICHT der Verlauf gespeichert. Nach jedem Rechenschritt ist die aktuelle Position und Geschwindigkeit weg
    for(int i=0;i<nmax;i++){
	// Position:
	for(int n=0;n<dim;n++){
	    p[i].pos[n]+=p[i].vel[n]*dt;       // x_i+1 = x_i + v_i * delta_t
	}
	// Geschwindigkeit:
	for(int n=0;n<dim;n++){
	    p[i].vel[n]+=p[i].f[n]/p[i].m*dt;   // v_i+1 = v_i + a_i * delta_t = v_i + F_i/m * delta_t
                                          // a = F/m (Newtonsches Gesetz)
	}
    }
}

// Kraftberechnung zwischen zwei Teilchen: actio-reactio ber�cksichtigen
// Potenzial: -m1*m2*r_i/r3
void force_p1p2(particle *const p1, particle *const p2){
    double r[dim],f[dim];
    double r2;
    double fs;

    for(int i=0;i<dim;i++)
	r[i]=p2->pos[i]-p1->pos[i];

    //Abstandsquadrat:
    r2=0.;
    for(int i=0;i<dim;i++)
	r2+=r[i]*r[i];

    //force: skalarer Anteil:
    fs=p1->m*p2->m/(sqrt(r2)*r2); // vgl newtonsches Gravitationsgesaetz: G*m1*m2/(r^2), wobei r der Abstand zwischen den zwei Massenpunkten ist
                                  // hier ist r2 = r^2! -> sqrt(r2)*r2 = r^3
                                  // und Dann ergibt sich die vektorielle Gleichung gemaess:
                                  // F_vek = G*m1*m2*r_vek/abs(r_vek)^3 (vgl Wikipedia 'Newtonsches Gravitationsgesetz')
    //Vektorieller Anteil
    for(int i=0;i<dim;i++){
	f[i]=fs*r[i];
	p1->f[i]+=f[i];
	p2->f[i]-=f[i];
    }
}

// Kraftberechnung: einfachste Methode Ausfuehren einer Doppelsumme
// unter Beruecksichtigung von actio=reaktio

void force_calculation(particle *const Teilchen,const int nmax){

    // setze alle Kraefte auf Null:
    for(int i=0;i<nmax;i++)
	for(int n=0;n<dim;n++)
	    Teilchen[i].f[n]=0.;

  for(int i=0;i<nmax-1;i++){
    // fixes Partikel
	   for(int j=i+1; j<nmax;j++){
       // alle anderen Partikel werden auf das fixe Partikel i bezogen

      // actio=reactio miteingebaut:
            // d.h. nur die Haelfte der Indexpaare (i,j)
	    // muss beruecksichtihgt werden.
	    force_p1p2(&Teilchen[i],&Teilchen[j]);
	   }
   }
}

// Einlesen der Startstruktur mit Anfangsbedingungen
// (Geschwindigkeit)

void init_structure(string filename){
    size_t n;
    ifstream Datei; // Filestream, um Dateien auszulesen != ofstream, der zum schreiben von Dateien ist

    Datei.open(filename.c_str(),ios::in);

    if(Datei) { // Sicherheitsabfrage, ob die Datei geoeffnet werden konnte
	n=0;
	Datei >> ntot; // Lese erste Zeile aus - ntot steht fuer Gesamtanzahl an Teilchen
	cout<<ntot<<endl;
	Teilchen = new particle[ntot];   // Erstelle Array (auf Heap - somit wird es auch nicht geloescht sobald es out of scope geht)
                                   // Teilchen ist eine globale (Zeiger-) Variable, und geht deshalb nicht verloren
  while(n<ntot){                   // Lese die Eigenschaften aus Datei ein, die fuer die erstellten Partikel gelten sollen
	    // Struktur einlesen: f�r dim=2 geschrieben
	    // (Verallgemeinerung: �bung)
	    Datei >>Teilchen[n].m >> Teilchen[n].pos[0]
		  >>Teilchen[n].pos[1]>>Teilchen[n].vel[0]
		  >>Teilchen[n].vel[1];
	    n++;
	}
    }
    Datei.close();

}



// OUTPUT Datei:

void ergebnis(const particle *const p,const int nmax,const double time,
	      ofstream &OUT){
          // Schreibe die Ergebnisse in die Ausgabedatei
    OUT<<time<<" ";
    for(int i=0;i<nmax;i++){
	for(int n=0;n<dim;n++)
	    OUT<<p[i].pos[n]<<" "; // Schreibe Position
	for(int n=0;n<dim;n++)
	    OUT<<p[i].vel[n]<<" "; // Schreibe Geschwindigkeit (Velocity)
    }
    OUT<<endl;
}



// Berechnung der Energie:
void energy(const particle * const p, const int nmax, const double time, ofstream & file)
{
    // Berechnen und Schreiben der berechneten Gesamtenergie eines Parikels
    file<<time<<" ";    // Schreibe Zeitstempel in file
    double e=0.;

    for(int i=0;i<nmax;i++)           // Iteriere ueber alle Planeten
    {
        double e_kinetic = 0.;
        double e_potenzial = 0.;
        double v2 = 0.;
        double r2 = 0.;
        for(int n=0;n<dim;n++)
        {
            v2 += p[i].vel[n]*p[i].vel[n];  // v^2 - Geschwindigkeit zum quadrat
        }
        e_kinetic = 0.5*p[i].m*v2;          // Berechnung der kinetischen Energie - 1/2*m*v^2
        for(int j=0;j<nmax;j++)
        {
            if(j==i) continue;              // Kein delta_h fuer Planet mit sich selbst
            r2 = 0.;
            for(int n=0;n<dim;n++)
            {
                r2 += (p[i].pos[n]-p[j].pos[n])*(p[i].pos[n]-p[j].pos[n]);    // delta_h^2
            }
            e_potenzial -= p[i].m*p[j].m/sqrt(r2);                            // Berechnung der potentiellen Energie nach - -(m1*m2/delta_h)
                                                                              // vgl https://de.wikipedia.org/wiki/Potentielle_Energie - Abschnitt: 'Potentielle Energie auf einer Planetenoberfläche'
        }
        e = e_potenzial + e_kinetic;
        file<<i<<" "<<e_kinetic<<" "<<e_potenzial<<" "<<e;
    }
    file<<endl; // time, [i, e_kin, e_pot, e_ges] -> der Teil in [] fuer jedes Partikel separat bevor Zeile umgebrochen wird
                // Zum Plotten muss man sich die entsprechenden Spalten raus suchen
}
