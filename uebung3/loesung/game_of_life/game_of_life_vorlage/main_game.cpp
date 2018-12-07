#include <iostream>
#include "functions_game.h" // Includiere alle Separat geschrieben funktionen über die Schnittstellen der Header Datei
using namespace std;		// kein std:: schreiben. Alle std-Library Funktionen sind in dieser Datei direkt verfügbar, ohne auf den Namespace mit :: zugreifen zu müssen

// debug includes
#include <stdlib.h>


void plot_field(unsigned char * const * const field2d, unsigned int nZeile , unsigned int nSpalte);
							// Deklariere Funktion -> wird weiter unten beschrieben!

int main(){

  unsigned int nZeile,nSpalte,nstep,nplot;
  double frac;


  cout<<" Einlesen der Systemgroesse nZeile,nSpalte: " << endl;
  cin >>nZeile>>nSpalte;
  cout << " " << endl;

  cout<<"Anteil besetzt :" << endl;
  cin >> frac;
  cout << " " << endl;

  cout<<"Wieviele Zeitschritte: " << endl;
  cin >> nstep;
  cout << " " << endl;

  cout<<"Ausgabe jedes n ten Schrittes: n= " << endl;
  cin >> nplot;
  cout << " " << endl;


  // 2d Matrix erzeugen

  MatrixXi field2d, field2d_tmp;

  field2d = create_field2d(nZeile,nSpalte);
  field2d_tmp = create_field2d(nZeile,nSpalte);

  // 2d Feld initialisieren

  init_field2d(field2d,frac);


  field2d_tmp = field2d;

  plot_field(field2d,0); // initiales Feld plotten

  // führe nstep Zeitschritte durch:
  int count = 0;
  for(unsigned int i = 0;i < nstep; i++){
    cout<<" nstep: "<<i<<" (max nstep: "<<nstep<<")"<<endl;

    make_step(field2d, field2d_tmp);



    if (i%nplot==0){
      count ++;
      plot_field(field2d,count);
    }
  };

  return(0);
}



void plot_field(unsigned char * const * const field2d, unsigned int nZeile , unsigned int nSpalte){
	// TODO: here comes some cool code
	/**
	 * Wofür ist diese Funktion?! plot_field existiert in functions_game.h und wird auch nur mit diesen
	 * Übergabeparametern aufgerufen -> überladene Funktion. Aber warum steht die hier?
	 */


	cout << "writing field in step.dat successful" << endl;

	// debug
	cout << "temp exit" << endl;
	exit(0);
}

