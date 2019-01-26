#include<iostream>

using namespace std;

int main(){
  int *feld;
  size_t n;


  cout << "please insert the number of elements: " << endl;
  cin >> n;

  feld = new int[n];

  for (size_t i = 0; i<n; i++){
    //*(feld+i) = i+9;
    feld[i]  = i+9;
  }

  for (size_t i = 0; i<n; i++){
    cout << "adress: "  << &feld[i] << " ; Wert: " << feld[i] << endl;
  }

  delete [] feld;

  return 0;
}
