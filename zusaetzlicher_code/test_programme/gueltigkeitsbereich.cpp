#include<iostream>

using namespace std;

int a = 1, b = 2; // globale Variablen

int main (){
  cout << "globales a=" << a << endl; // 1

  int a = 10;

  cout << "lokales a=" << a << endl;  // 10

  cout << "globales a=" << ::a << endl;   // 1

  {
    // definiere neuen Scope
    int b = 20;
    int c = 30;

    cout << "lokales b=" << b << endl;  // 20

    cout << "lokales c=" << c << endl;     // 30

    cout << "globales b=" << ::b << endl; // 2
  }

  cout << "globaless b wieder sichtbar: b=" << b << endl; // 2

  return 0;
}
