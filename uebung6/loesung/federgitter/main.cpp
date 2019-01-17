#include <iostream>
#include <stdlib.h>

#include "matrix_funcs.h"
#include "vector_funcs.h"
#include "solver_funcs.h"


using namespace std;

int main(){

	// temporaer zum Anfangen
	Matrix testMatrix(3, 3);
	Vector testVector(5);
	cout << "main method was called!" << endl;

	// Variablendeklarationen
	size_t n;	// n x n Feld soll aufgebaut werden
	char boundaryCond;

	// Systemeingaben
	cout << "please insert the size of the spring field (depht, width)" << endl;
	cin >> n;
	cout << "please insert the type of boundary condition: " << endl;
	cout << "a: same force on all nodes" << endl;
	cout << "b: force on every secound node on the boundary" << endl;
	cin >> boundaryCond;
	// checke, ob eine valide Eingabe stattgefunden hat
	if (boundaryCond != 'a' && boundaryCond != 'b'){
    cout << "ERROR: wrong input, please insert a or b the next time. The executable terminates now!" << endl;
    exit(EXIT_FAILURE);
	}

	// TODO: Hier kommt der Code, um die Berechnung durchzufuehren und in eine Ausgabedatei zu schreiben


  return 0;
}
