#include<iostream>


int main(){

  const int * ip;
  // int const * ip; // aequivalente Darstellung
  int test = 5;
  ip = &test;
  std::cout << "this is the adress of test: " << ip << std::endl;
  test = 6;
  //*ip = 6; // const bezieht sich darauf, dass die im ptr gespeicherte Variable durch den Ptr nicht veraendert werden kann!


  int test2 = 42;
  int * const ip2 = & test2;

  // ip2 = & test; // Geht nicht, da ip2 ein constanter Pointer ist. Er zeigt IMMER auf das Objekt, mit dem er initialisiert wurde!
  std::cout << "this is the adress of ip2: " << ip2 << std::endl;
  // Man muss einem * const Pointer immer eine Adresse bei der Deklaration zuweisen, ansonsten kann ich den Pointer spaeter nicht mehr veraendern und er bleibt immer leer!
  // Wenn ich ihm nichts zuweise, maeckert der Compiler auch!
  *ip2 = 666; // Wertzuweisung geht ohne Probleme!
  std::cout << "this is the last value that is saved in the adress ip2 = " << ip2 << " : " << *ip2 << std::endl;

  // Beides geht auch kombiniert:
  int combined_int = 1000;
  const int * const ip3 = & combined_int; // Das ist ein fester Pointer im Speicher, der das Objekt nicht veraendern kann!
  // *ip3 = 999; // Geht nicht, da das erste const aussagt, dass der im Ptr verstecke Wert nicht ueber den Ptr veraendert werden darf! 

  std::cout << "this is ip3 = " << ip3 << " with the fixed value: " << *ip3 << std::endl;


  return 0;
}
