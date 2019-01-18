#include <iostream>
#include <stdlib.h>	// exit program bei falscher Eingabe fuer Randbedingungen
#include <fstream>	// filestream object, um Ergebnisse in Datei zu schreiben
// Abhaengigkeiten des eigenen Codes
#include "matrix_funcs.h"
#include "vector_funcs.h"
#include "solver_funcs.h"


using namespace std;


void createMatrix_springmesh(Matrix & matrix_A, size_t & n){
	cout << "creating matrix for the " << n << "x" << n << " equation system" << endl;

	size_t n_matrix = n*n;

	for (int i = 0; i < n_matrix; i++){ 	// <, da n die Dimension des Federgitters angibt (ohne 0tes Element), die Matrix aber mit dem 0ten Element beginnt und somit beim n-1 ten Element aufhoeren muss
		// Alle Zeilen
		for (int j = 0; j < n_matrix; j++){
			// Alle Spalten
			if (i == j){				// Diagonale
				matrix_A(i, j) = 4;
			}
			if (j == i - 1 && j >= 0 && i%n != 0){	// Randbedingung: links daneben
				matrix_A(i, j) = -1;
			}
			if (j == i + 1 && j < n*n && j%n != 0){	// Randbedingung: rechts daneben
				matrix_A(i, j) = -1;
			}
			if (j == i + n && i + n < n*n){	// Randbedingung: selbes Element, nur eine Zeile davor
				matrix_A(i, j) = -1;
			}
			if (j == i - n && i - n >= 0){	// Randbedingung: selbes Element, nur eine Zeile danach
				matrix_A(i, j) = -1;
			}
		}
	}
	cout << "finished matrix creation!" << endl;
}

void createVector_force(Vector & vector_b, double force, size_t & n){
	char mode;
	cout << "creating the displacement vector u" << endl;
	cout << "do you want to apply the force to:" << endl;
	cout << "a: all nodes" << endl;
	cout << "b: choose the nodes that sould have a force" << endl;
	cin >> mode;

	if (mode != 'a' && mode != 'b'){
		cout << "ERROR: wrong input! Please insert 'a' or 'b' to run the program. The execution ends now!" << endl;
		exit(EXIT_FAILURE);
	}

	if (mode != 'b'){
		vector_b = force;
	}


	cout << "finished creating the displacement vector u" << endl;
}

void write_result_to_file(Vector & vector_x, size_t & n){
	ofstream resultStream;
	resultStream.open("ergebnisse.dat");

	int temp_i = -1;
	int temp_j = -1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			resultStream << i << " " << j << " " << vector_x(i*n + j) << endl;
		}
	}
	resultStream.close();
}

int main(){

	// Variablendeklarationen
	size_t n;	// n x n Feld soll aufgebaut werden
	double force;
	char boundaryCond;

	// Systemeingaben
	cout << "please insert the size of the spring field (depht, width)" << endl;
	cin >> n;
	cout << "please insert the force that will displace the nodes: (in Newton)" << endl;
	cin >> force;


	// Erstelle Gleichungssystem A*x = b:
	Matrix matrix_A(n*n, n*n);
	Vector vector_x(n*n); // Zielvektor
	Vector vector_b(n*n);
	Vector vector_x_start(n*n);
	// Ich brauche fuer jedes Element eine Verschiebung -> Fuer ein Federgitter mit nxn brauche ich n*n Vektorelemente
	// Und eine Matrix mit n*n x n*n Eintraegen, da ich fuer jedes Element eine Gleichung brauche!
	// ACHTUNG: Unterscheide Gittergroesse von Matrixgroesse des LGS! Diese sind nicht gleich!

	// Beschreibe Vektor mit den Randbedingungen:
	createVector_force(vector_b, force, n);

	// Beschreibe Matrix:
	createMatrix_springmesh(matrix_A, n); // Matrix ist symetisch!

	// Loese das Gleichungssystem
	vector_x_start = 0; 	// Startloesung fuer den iterativen CG Solver
	vector_x = cg_solve(vector_x_start, matrix_A, vector_b);

	// schreibe das Ergebnis im angegebenen Format in eine Datei
	write_result_to_file(vector_x, n);

  return 0;
}
