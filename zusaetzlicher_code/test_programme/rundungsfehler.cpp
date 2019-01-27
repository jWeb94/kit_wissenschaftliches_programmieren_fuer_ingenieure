#include<iostream>
#include<iomanip>

using namespace std;

typedef float gleit_zahl;

int main(){
  gleit_zahl val1 = 1.4142135623730951e+000;
  gleit_zahl val2 = 1.4142135623730954e+000;
  gleit_zahl val3 = 1.4142135623730953e-015;

  gleit_zahl erg1 = (val1-val2)-val3;
  gleit_zahl erg2 = (val1-val3)-val2;


  cout << "erg1: " << setprecision(16) << erg1 << endl;
  cout << "erg2: " << setprecision(16) << erg2 << endl;

  cout << "absoluter Fehler: " << abs(erg1-erg2) << endl;
  cout << "relativer Fehler: " << abs(erg1-erg2)/abs(erg1) << endl;
  return 0;
}
