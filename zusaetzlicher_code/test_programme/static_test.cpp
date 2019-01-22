#include<iostream>

using namespace std;

int static_test(int a);
// int static_test(int & a); // Geht nicht, da ich, wenn ich static_test(3) aufrufen will, das nicht geht!
// Wenn ich eine Referenz uebergebe, muss ich mit einer Variablen arbeiten, da wenn ich direkt den Wert rein schreibe
// nichts referenziert werden kann!

int main(){
  int calls;
  int input = 1;
  calls = static_test(input);
  calls = static_test(2);
  calls = static_test(3);
  calls = static_test(4);
  calls = static_test(5);
  cout << calls << endl;
  // cout << b << endl; // geht nicht, da keine globale Sichtbarkeit
  //return 0; // Weglassen fuehrt zum automatischen anhaengen im Compilierungsprozess!
}

int static_test(int a){
  static int b = 0;
  cout << a << endl;
  b = b + 1;
  return b;
}
