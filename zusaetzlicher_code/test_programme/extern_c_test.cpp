#include<iostream>
// #include<cmath.h>  // das ist die math Bibliothek aus C, eingebunden in den std Namespace von C++; im Hintergrund wird im std Namespace extern "C"{#include<math.h>} aufgerufen
                      // Um mit diesem include Funktionen aus math.h der C Bibliothek aufzurufen, muss der Zugriff auf die Funktionen ueber den Namespace std erfolgen
extern "C"{
    #include<math.h>      //includiere die C Bibliothek in mein aktuelles Programm (C kennt keine Namespaces!)
}
// #include<math.h> // mit g++ geht das auch ohne extern "C", da g++ den C-Syntax erkennt. Das muss nicht bei allen Compilern so sein!


int main(){
  int a = 8;
  int b = 10;

  // Berechnung mit math-Bibliothek
  int c = pow(b, a);
  //int d = std::pow(b, a); // Aufruf mit cmath

  return 0;
}
