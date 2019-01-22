#include<iostream>

using namespace std;

int main(){
  int MAX_AGE = 90;

  int const * a = new int;

  MAX_AGE = 80;
  // *a = 2; // geht nicht, da const
  a = &MAX_AGE; // &<Variable> als rvalue liefert eine Adresse zurueck, die ich in eine, entsprechend des Datentyps, Pointervariable speichern kann!

  cout << *a << endl;

  cin.get(); // Auf nutzereingabe warten bis Programm weiter geht
  cout << "Kombination: " << endl;

  //const int * const b = new int(); // wird mit 0 initialisiert und bleibt unveraenderlich!
  const int * const b = new int(5);
  cout << *b << endl; // Dereferenz, da b eine Pointervariable ist!
  //b = new int(9); // geht nicht
  //*b = 9; // geht ebenfalls nicht

  return 0;
}
