#include "functions_game.h"

MatrixXi create_field2d(unsigned int nx,unsigned int ny){
	return MatrixXi(nx, ny); // erzeuge temporäres Objekt, dass durch den (überladenen) Zuweisungsoperator kopiert wird
}

void init_field2d(MatrixXi &field, const double frac){
	/**
	 * zufällige Initialisierung der Felder mit 0 oder 1 der uebergebenen Matrix
	 * bis der Anteil der besetzten Felder (mit Wert 1) dem übergebenen Anteil frac
	 * entspricht
	 *
	 * kein Rueckgabetyp, da ich die zu initialisierende Matrix als Referenz (&field) uebergebe
	 */

	int numOfFields = field.rows()*field.cols();
	int numberOfOnes = 0;
	double currentFrac = 0;
	int randRow;
	int randCol;


	while (currentFrac < frac){
		// geht auch mit for -> dann muss ich int numOfIterations = frac*numOfFields;
		randRow = rand() % (field.rows());
		randCol = rand() % (field.cols());

		field(randRow, randCol) = 1;
		numberOfOnes ++;

		currentFrac = double(numberOfOnes)/double(numOfFields);

		// debug
		//cout << "currentFrag at numberOfOnes of" << numberOfOnes <<   "is: " << currentFrac << endl;

	}

	// debug
	// cout << "field is: " << endl;
	// cout << field << endl;

	/*
	cout << "field.rows() is: " << field.rows() << endl;
	cout << "field.cols() is: " << field.cols() << endl;

	int tempValue;
	for(int i = 0; i < field.rows(); i ++ ){
		for (int j = 0  ; j < field.cols(); j ++){
			field(i, j) = rand() % 2; // values between 0 and 1 with cmath
		}
	}
	*/

	/*
	MatrixXd test = MatrixXd::Random(3, 3);
	test = test.cwiseAbs(); // elementwise Betrag
	MatrixXi randomMatrix = test.cast<int>(); // casten ist keine gute Idee, da cast von double zu int nur die Nachkommastellen abschneidet!
	// eine round Funktion gibt es in Eigen3 nicht!
	cout << randomMatrix << endl;
	*/

}
void make_step(MatrixXi & field,MatrixXi  & field_tmp){
	/*
	 * Wird in jedem Zeitschritt ausgewertet!
	 *
	 * Werten Sie je Zelle 8 Nachbarn aus. Verwenden Sie dafür periodische Randbedingungen
	 *
	 * Nutzen Sie ein temporäres Feld zum Zwischenspeichern der aktualisierten Werte
	 *		Ist als Referenz übergeben worden!
	 *
	 * Aktualisieren Sie zum Schluss das alte Feld
	 *		zuweisung am Ende der Funktion
	 */

	/*
	// debug test Modulo - Randbedingungen
	for (int k = 0; k < field.cols(); k ++){

		cout << "modulo fuer k = " << k << " ist: " << (k-1+2)%2 << endl;
	}
	*/

	/*
	// debug
	cout << "this is the field matrix: " << endl;
	cout << field << endl;
	*/

	Matrix3i tempNeighbors = Matrix3i::Constant(3,3,0); // 3x3 Matrix mit allen Elementen = 0

	// TODO: Checke, ob die Werte an den Rändern passen!

	// Werte alle Zellen der Matrix aus -> Zeilen- & Spaltenweise
	for (int i = 0; i < field.rows(); i ++ ){					// nur <, da 0 auch schon zählt!
			for (int j = 0  ; j < field.cols(); j ++){
				// für jede Zelle (field(i, j)) müssen alle Regeln ausgewertet werden!

				// Ecken
				if ((i == 0) && (j == 0)){
					// Sonderfall links oben -> hier starten auch die Randbedingungen

					cout << "links oben" << endl;
						// periodische Randbedingungen
					tempNeighbors.row(0) << 1, 0, 1;
					tempNeighbors.col(0) << 1, 0, 1; // Element (0, 0) wird quasi überschrieben
						// Werte übernehmen
					tempNeighbors(1, 1) = field(i, j); // mittleres Element, dass es auszuwerten gilt!
					tempNeighbors(1, 2) = field(i, j+1);
					tempNeighbors(2, 1) = field(i+1, j);
					tempNeighbors(2, 2) = field(i+1, j+1);
				}
				else if (i == 0 && j == (field.cols()-1)){
					// Sonderfall rechts oben

					cout << "rechts oben" << endl;
					if (field.cols()%2 == 1){
						// bei ungerader Anzahl an Spalten ist die rechte Ecke eine 0
						tempNeighbors.row(0) << 0, 1, 0;
						tempNeighbors.col(2) << 0, 1, 0;
						tempNeighbors(1, 1) = field(i, j); // auszuwertendes Element
						tempNeighbors(1, 0) = field(i, j-1);
						tempNeighbors(2, 1) = field(i+1, j);
						tempNeighbors(2, 0) = field(i+1, j-1);
					}
					else{
						tempNeighbors.row(0) << 1, 0, 1;
						tempNeighbors.col(2) << 1, 0, 1;
						tempNeighbors(1, 1) = field(i, j); // auszuwertendes Element
						tempNeighbors(1, 0) = field(i, j-1);
						tempNeighbors(2, 1) = field(i+1, j);
						tempNeighbors(2, 0) = field(i+1, j-1);
					}

				}
				else if (i == (field.rows()-1) && j == 0){
					// Sonderfall links unten

					cout << "links unten" << endl;
					if (field.rows()%2 == 1){
						// bei ungerader Anzahl an Zeilen ist die rechte Ecke eine 0
						tempNeighbors.row(2) << 0, 1, 0; 	// unten
						tempNeighbors.col(0) << 0, 1, 0;	// links
						tempNeighbors(1, 1) = field(i, j); 	// auszuwertendes Element
						tempNeighbors(1, 2) = field(i, j+1);
						tempNeighbors(0, 1) = field(i-1, j);
						tempNeighbors(0, 2) = field(i-1, j+1);
					}
					else{
						tempNeighbors.row(2) << 1, 0, 1; 	// unten
						tempNeighbors.col(0) << 1, 0, 1;	// links
						tempNeighbors(1, 1) = field(i, j); 	// auszuwertendes Element
						tempNeighbors(1, 2) = field(i, j+1);
						tempNeighbors(0, 1) = field(i-1, j);
						tempNeighbors(0, 2) = field(i-1, j+1);
					}
				}
				else if (i == (field.rows()-1) && j == (field.cols()-1)){
					// Sonderfall rechts unten

					cout << "rechts unten" << endl;
						// die Randbedingungen
					if (field.rows()%2 == 1){
						// bei ungerader Anzahl an Zeilen ist die rechte Ecke eine 0
						tempNeighbors.col(2) << 0, 1, 0;
					}
					else{
						tempNeighbors.col(2) << 1, 0, 1;
					}

					if (field.cols()%2 == 1){
						// bei ungerader Anzahl an Spalten ist die rechte Spalte am Ende 0
						tempNeighbors.col(2) << 0, 1, 0;
					}
					else{
						tempNeighbors.col(2) << 1, 0, 1;
					}
						// Werte übernehmen
					tempNeighbors(1, 1) = field(i, j); 	// auszuwertendes Element
					tempNeighbors(1, 0) = field(i, j-1);
					tempNeighbors(0, 1) = field(i-1, j);
					tempNeighbors(0, 0) = field(i-1, j-1);
				}

				// Rand
					/*
					 * Nutze Modulo-Periodizität
					 * (i-1+nx)%nx -> Werte zwischen 0 und nx-1
					 *
					 * (i-1+2)%2 -> nx = 2 für periodische Werte zwischen 0 und 1
					 * , wobei i die Anzahl an Zeilen/Spalten ist
					 *
					 * für i = 0 ist der Modulo 1
					 */


				else if (i == 0 && (j != 0 || j != (field.cols()-1))){
					// Sonderfall erste Zeile

					cout << "erste Zeile" << endl;
						// Rand
					tempNeighbors(0, 0) = ((j-1)-1+2)%2;
					tempNeighbors(0, 1) = (j-1+2)%2;
					tempNeighbors(0, 2) = ((j+1)-1+2)%2;

						// Übernahme
							// mittlere Zeile
					tempNeighbors(1, 0) = field(i, j-1);
					tempNeighbors(1, 1) = field(i, j);
					tempNeighbors(1, 2) = field(i, j+1);
							// untere Zeile
					tempNeighbors(2, 0) = field(i+1, j-1);
					tempNeighbors(2, 1) = field(i+1, j);
					tempNeighbors(2, 2) = field(i+1, j+1);
				}
				else if (i == (field.cols()-1) && (j != 0 || j != (field.cols()-1))){
					// Sonderfall letzte Zeile

					cout << "letzte Zeile" << endl;
					// Rand (untere Zeile)
					tempNeighbors(2, 0) = ((j-1)-1+2)%2;
					tempNeighbors(2, 1) = (j-1+2)%2;
					tempNeighbors(2, 2) = ((j+1)-1+2)%2;

					// Übernahme
					// mittlere Zeile
					tempNeighbors(1, 0) = field(i, j-1);
					tempNeighbors(1, 1) = field(i, j);
					tempNeighbors(1, 2) = field(i, j+1);
					// obere Zeile
					tempNeighbors(0, 0) = field(i-1, j-1);
					tempNeighbors(0, 1) = field(i-1, j);
					tempNeighbors(0, 2) = field(i-1, j+1);

				}
				else if ((i != 0 || i != (field.rows()-1)) && j == 0){
					// Sonderfall erste Spalte

					cout << "erste Spalte" << endl;
					// linke Spalte
					tempNeighbors(0, 0) = ((i-1)-1+2)%2;
					tempNeighbors(1, 0) = (i-1+2)%2;
					tempNeighbors(2, 0) = ((i+1)-1+2)%2;

					// Übernahme
					// mittlere Spalte
					tempNeighbors(0, 1) = field(i-1, j);
					tempNeighbors(1, 1) = field(i, j);
					tempNeighbors(2, 1) = field(i+1, j);
					// rechte Spalte
					tempNeighbors(0, 2) = field(i-1, j+1);
					tempNeighbors(1, 2) = field(i, j+1);
					tempNeighbors(2, 2) = field(i+1, j+1);

				}
				else if ((i != 0 || i != (field.rows()-1)) && j == (field.cols()-1)){
					// Sonderfall letzte Spalte
					cout << "letzte Spalte" << endl;
					// rechte Spalte
					tempNeighbors(2, 0) = ((i-1)-1+2)%2;
					tempNeighbors(2, 1) = (i-1+2)%2;
					tempNeighbors(2, 2) = ((i+1)-1+2)%2;

					// Übernahme
					// mittlere Spalte
					tempNeighbors(0, 1) = field(i-1, j);
					tempNeighbors(1, 1) = field(i, j);
					tempNeighbors(2, 1) = field(i+1, j);
					// linke Spalte
					tempNeighbors(0, 0) = field(i-1, j-1);
					tempNeighbors(1, 0) = field(i, j-1);
					tempNeighbors(2, 0) = field(i+1, j-1);
				}

				// Zelle in der Mitte des Feldes
				else{
					// Zelle mit 8 Nachbarn

					cout << "kopieren" << endl;
						// copy the block
					tempNeighbors = field.block(i-1, j-1, 3, 3); // get 3x3 block with the start indices i-1 and j-1
				}

			// Check the Rules
			int tempResult = checkRules(tempNeighbors);

			// debug
			//cout << "this is tempResult: " << tempResult << endl;

			field_tmp(i, j) = tempResult;


			/*
			// debug
			cout << "tempNeighbors of i = " << i << " and j = " << j << " is: " << endl;
			cout << tempNeighbors << endl;
			*/

		}		// end of for j
	} 			// end of for i

	/*
	// debug
	cout << "this is the field_tmp: " << endl;
	cout << field_tmp << endl;
	*/
	field = field_tmp;
}

void plot_field(MatrixXi const & field, const unsigned int nstep){
  char Dateiname[256];
  ofstream Datei;

  const unsigned int nx = field.rows();
  const unsigned int ny = field.cols();


  sprintf(Dateiname,"field%d.dat",nstep);
  Datei.open(Dateiname);
  for(int i = 0;i<nx;i++){
    for(int j=0;j<ny;j++){
      Datei<<i<<" "<<j<<" "<<field(i,j)<<endl;
    }
    Datei<<endl;
  }
  Datei.close();
}


int checkRules (Matrix3i & neighborhoodMatrix){
	// checking the 4 Rules for the neighborhood
	int existance = neighborhoodMatrix(1, 1); // per default take the central value
	int neighborCounter = 0;
	// TODO: Implementiere das Regeln checken
	for (int i = 0; i < neighborhoodMatrix.rows(); i++){
		for (int j = 0; j < neighborhoodMatrix.cols(); j++){
			if (i != 1 && j != 1){ // ignore the central object that is evaluated
				if(neighborhoodMatrix(i, j)==1){
					// wenn die Zelle belegt ist, zähle den Counter eins hoch
					neighborCounter ++;
					//cout << "incremented neighborCounter" << endl;
				}

			}
		}
	}

	if (neighborCounter == 0 || neighborCounter == 1){
		existance = 0; // Object dies
		cout << "lonelyness" << endl;
	}
	else if (neighborCounter == 2 || neighborCounter == 3){

		if (neighborhoodMatrix(1, 1) == 0 && neighborCounter == 3){
			existance = 1;
			cout << "birth" << endl;
		}
		else{
			existance = neighborhoodMatrix(1, 1); // remain 0 or just 2 neighbors
			cout << "remaining" << endl;
		}
	}
	else if (neighborCounter >= 4 && neighborCounter <= 8){
		existance = 0;
		cout << "overcrownding" << endl;
	}
	else if (neighborCounter == 3){
		existance = 1;
	}
	else {
		cout << "ERROR: No valid neighborhood! Exiting the program!" << endl;
		existance = -1;
		exit(0);
	}

	return existance;
}


