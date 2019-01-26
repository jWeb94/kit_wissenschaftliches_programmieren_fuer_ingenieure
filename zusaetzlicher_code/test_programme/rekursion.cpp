#include<iostream>


int fakultaet(int);

int main(){
  // entrance point ist die main Methode beim Compilieren
  int i;
  std::cout << "Please insert the number of which you want to calculate the fakultaet: " << std::endl;
  std::cin >> i;
  cout << "Fakultaet of " << i << " is: " << fakultaet(i) << std::endl;
  return 0; // sage dem OS, dass das Programm durchgelaufen ist!
}


int fakultaet(int a){
  return (a == 0) ? 1 : a*fakultaet(a-1);
  /*
   * ? ist der sogenannte 'Ternäre Operator'.
   * Ist der logische Ausdruck vor dem ? true, so wird die Links Seite vom : ausgefuehrt.
   * Ist der Ausdruck False, so wird die Rechte Seite vom : ausgefuehrt!
   */
}
