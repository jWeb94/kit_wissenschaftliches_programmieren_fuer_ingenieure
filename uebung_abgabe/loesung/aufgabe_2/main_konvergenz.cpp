#include<iostream>
#include<string>
#include<fstream>
#include <stdlib.h>

#include"complex.h" // "", da in aktuellem Working-Directory

int calcNumConvergence(MyComplex z_i_1, MyComplex c, int n, double r_c, size_t n_max);

int main (){

	using namespace std;

	// Variablendeklarationen
	int numIter; 					// Nummer der Iterationsvorschrift
	double x_0, y_0, x_M, y_M;		// Werteberech
	int N_xmax, N_ymax; 			// Unterteilung
	int n; 							// Exponent
	size_t maxIterations; 			// Maximale Anzahl an Iterationen
	double R_c; 					// Konvergenzradius
	string nameResult; 				// Name der Ergebnisdatei
	double reInsert, imInsert;		// Komponeten der komplexen Zahl c_0

	double delta_x, delta_y; 		// Schrittweite

	// einlesen
	cout << "Bitte Nummer der Iteratotionsvorschrift eingeben" << endl;
	cin>>numIter; // das ist nicht ohne Grund gegeben! Mache eine Fallunterscheidung, wie die Eingabeparameter ausgewertet werden sollen!

	cout << "Bitte Wertebereich eingeben" << endl;		// Definiere zulaessigen Bereich in der komplexen Ebene. Das ist ein Quarder, der von x_0 bis x_M auf der Re-Achse und von y_0 bis y_M auf der Im-Achse geht!
	cout << "(x_0, y_0): " << endl;
	cin >> x_0 >> y_0;

	cout << "(x_M, y_M): " << endl;
	cin >> x_M >> y_M;

	cout << "Bitte Unterteilung festlegen (N_xmax, N_ymax): " << endl;
	cin >> N_xmax >> N_ymax;

	cout << "Bitte Exponent eingeben: " << endl;
	cin >> n;

	cout << "Bitte maximale Anzahl an Iterationen eingeben: " << endl;
	cin >> maxIterations;

	cout << "Bitte Konvergenzradius eingeben: " << endl;
	cin >> R_c;

	cout << "Name der Ergebnisdatei eingeben: " << endl;
	cin >> nameResult;

	cout << "Bitte Realanteil und Imaginaeranteil der komplexen Zahl c_0 eingeben: " << endl;
	cin >> reInsert >> imInsert;

	cout << "Vielen Dank fuer die Eingaben. Das Programm startet jetzt!" << endl;


	// Berechnungen vorab
	delta_x = (x_M-x_0)/double(N_xmax);
	delta_y = (y_M-y_0)/double(N_ymax);

	// Resultatvariablen
	int n_iter_temp;
	ofstream resultStream;			// erstelle Stream-Objekt, um in den Cases ein File zu referenzieren und mittels des Stream-Objekts zu beschreiben
	// eine switch-Anweisung eignet sich hier besonders, da ich Fälle mit einer Zahl decodiert im Uebergabefile bekomme und mittels switch nicht extra noch Wahrheitswerte auswerten muss
	switch(numIter){
		case 1:
		{
			// Iterationsvorschrift 1
			MyComplex z_0(x_0, y_0);
			MyComplex c_0(reInsert, imInsert);

			// oeffne Ergebnisdatei
			resultStream.open(nameResult); // benoetigt #include<fstream>
			// Iteriere ueber alle Anfangsbedingungen der Folge
			for (int i = 0; i <= N_xmax; i++){		// Schleife, um alle x-Komponenten durch zu gehen
				for (int j = 0; j <= N_ymax; j++){	// Schleife, um alle y-Komponenten durch zu gehen
						// Berechnnung
					z_0.setRe(x_0+delta_x*double(i));
					z_0.setIm(y_0+delta_y*double(j));

					n_iter_temp = calcNumConvergence(z_0, c_0, n, R_c, maxIterations); // Der wird immer ueberschrieben, deshalb muss ich ihn nicht zurueck setzen!

						// Schreibe in File
							// Sicherheitsabfrage, ob File noch geoeffnet ist:
					if (resultStream.is_open())
					{
						resultStream << i << " " << j << " " << n_iter_temp << endl; // unten an das File anhaengen
					}
					else
					{
						cout << "Es ist ein Fehler aufgetreten. Das Programm wird beendet. Bitte ueberpruefen Sie den Quellcode!" << endl;
						exit(0);
					}
					/*
					 * debug, um nur die ersten Iterationen zu sehen!
					if (j == 3){
						exit(0);
					}
					*/
				}
			}
			resultStream.close(); // Schließe Datei - das Stream-Objekt bleibt erhalten
			break; // damit nicht die nachfolgenden Bloecke ebenfalls danach ausgefuehrt werden und nach diesem case die switch-case abfrage beendet ist
		}
		case 2:
		{
			// Iterationsvorschrift 2
				// Hier wird analog zu Iterationsvorschrit 1 berechnet, nur dass statt z_0, c_0  variiert wird
			MyComplex z_0(reInsert, imInsert); 	// vgl Aufgabenstellung -> man darf die Uebergaben fuer c_0 verwenden!
			MyComplex c_0(x_0, y_0); 			// c liegt im gegebenen Wertebereich -> fange am ll-Ende an!

			resultStream.open(nameResult);
			for (int k = 0; k <= N_xmax; k++){		// Schleife, um alle x-Komponenten durch zu gehen
				for (int l = 0; l <= N_ymax; l++){	// Schleife, um alle y-Komponenten durch zu gehen
						// Berechnnung
					c_0.setRe(x_0+delta_x*double(k));
					c_0.setIm(y_0+delta_y*double(l));
					n_iter_temp = calcNumConvergence(z_0, c_0, n, R_c, maxIterations);
						// Schreibe in File
					if (resultStream.is_open())
					{
						resultStream << k << " " << l << " " << n_iter_temp << endl; // unten an das File anhaengen
					}
					else
					{
						cout << "Es ist ein Fehler aufgetreten. Das Programm wird beendet. Bitte ueberpruefen Sie den Quellcode!" << endl;
						exit(0);
					}
				}
				resultStream << endl; // Leerzeichen zwischen allen spalten
			}
			resultStream.close();
			break;
		}
		case 3:
		{
			// Iterationsvorschrift 3
				// analog zu 2! Nur anderer, UEBERGEBENER Exponent
			MyComplex z_0(reInsert, imInsert); 	// vgl Aufgabenstellung -> man darf die Uebergaben fuer c_0 verwenden!
			MyComplex c_0(x_0, y_0); 			// c liegt im gegebenen Wertebereich -> fange am ll-Ende an!
			resultStream.open(nameResult);
			for (int m = 0; m <= N_xmax; m++){		// Schleife, um alle x-Komponenten durch zu gehen
				for (int n = 0; n <= N_ymax; n++){	// Schleife, um alle y-Komponenten durch zu gehen
						// Berechnnung
					c_0.setRe(x_0+delta_x*double(m));
					c_0.setIm(y_0+delta_y*double(n));
					n_iter_temp = calcNumConvergence(z_0, c_0, n, R_c, maxIterations);
						// Schreibe in File
					if (resultStream.is_open())
					{
						resultStream << m << " " << n << " " << n_iter_temp << endl; // unten an das File anhaengen
					}
					else
					{
						cout << "Es ist ein Fehler aufgetreten. Das Programm wird beendet. Bitte ueberpruefen Sie den Quellcode!" << endl;
						exit(0);
					}
				}
			}
			resultStream.close();
			break;
		}
		default:
		{
			cout << numIter << " ist kein zulaessiger Wert fuer die Iterationsvorschrift! Das Programm wird beendet" << endl;
			exit(0);
		}
	}

};


int calcNumConvergence(MyComplex z_i_1, MyComplex c, int n, double r_c, size_t n_max){

	using namespace std;

	// Bestimme die Anzahl an Iterationen, bis der Konvergenzradius verlassen wird, oder n_max fuer den Fall, dass die uebergebene Folge konvergiert
	MyComplex resultIteration_i = z_i_1;

	/*
	//debug
	cout << "n is: " << endl;
	cout << n << endl;

	cout << "z_0 is: " << endl;
	resultIteration_i.printComponents();

	cout << "r is: " << r_c << endl;

	cout << "c is: " << endl;
	c.printComponents();
	*/

	for (size_t i = 0; i < n_max; i++){
		// c stimmt, Berechnung stimmt!
		resultIteration_i = (resultIteration_i^n) + c; // verrechnen der komplexen Zahlen -> ACHTUNG: der ^-Operator musste fuer diese Aufgabe noch ueberladen werden!
		/*
		cout << "z_temp is: " << endl;
		resultIteration_i.printComponents();

		cout << "norm is: " << resultIteration_i.norm() << endl;
		*/

		//resultIteration_i.printComponents();
		if (resultIteration_i.norm() >= r_c ){
			return i; // Abbruchbedingung ~ wenn die Komplexe Zahl außerhalb des Konvergenzradius liegt, dann konvergiert die Folge nicht!
			//cout << "Abbruchbedinung erreicht" <<endl;
		}
	}
	return n_max;
};



