#include<iostream>

using namespace std;

int main(){
  int **feld2d;
  size_t n;
  size_t m;

  cout << "please insert rows: " << endl;
  cin >> n;
  cout << "please insert cols: " << endl;
  cin >> m;

  feld2d = new int * [n];

  // Zusammenhaengender Speicher
  feld2d[0] = new int [m*n];
  for (size_t i = 1; i<n; i++){
    feld2d[i] = feld2d[0] + i*m; // Verlinke die Zugriffsadressen fuer die Zeilen des dynamischen Arrays
  }



  for (size_t i = 0; i<n; i++){
    for (size_t j = 0; j < m; j++){
        cout << "adress of index i=" << i << ", j=" << j << " is: "  << &feld2d[i][j] << " ; value: " << feld2d[i][j] << endl;
        /*
         * Adressen sind zusammenhaengend, da ich in Zeile 18 zusammengehoerigen Speicher definiere!
         */
    }
  }

  delete [] feld2d[0];  // Loesche int Array n x m
  delete [] feld2d;     // Loesche Pointer-Array

  int **feld2d_nz;
  feld2d_nz = new int * [n];

  for (int i = 0; i < n; i++){
    feld2d_nz[i] = new int [m]; // Der Speicher haengt zusammen!
  }

  for (size_t i = 0; i<n; i++){
    for (size_t j = 0; j < m; j++){
        cout << "adress of feld2d_nz index i=" << i << ", j=" << j << " is: "  << &feld2d_nz[i][j] << " ; value: " << feld2d[i][j] << endl;
        /*
         *  Zusammenhaengender Speicher nur fuer die Zeilen
         */
    }
  }

  for (int i = 0; i < n; i++){
    delete [] feld2d_nz[i]; // loesche die int arrays
  }
  delete [] feld2d_nz;      // Loesche das Pointer-Array

  return 0;
}
