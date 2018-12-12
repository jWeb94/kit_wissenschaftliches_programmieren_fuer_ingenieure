#include <iostream>


int main(){

  // create 2 dimensional array with 3x5 Elements
  int ** b; // NULL-pointer;

  std::cout << "This is stored in b (created by int ** b) ~ pointer to a pointer. " << b << std::endl;

  b = new int*[3]; // write an Pointer in b that points to an integer-pointer-object
  std::cout << "this is b after assigning a pointer to an pointer: " << b << std::endl;
  // in b steht ein pointer auf ein Objekt vom Typ Integer-Pointer-Array

  b[0] = new int[3*5]; /* in die Adresse des nullten Elements des Integer-Pointer-Arrays wird die Adresse eines
                        * Integer-Arrays mit NxM Elementen (hier 3x5=15) angelegt
                        * so entsteht ein entsprechendes Objekt im Speicher, dessen Speicherort in b[0] steht!
                        *
                        * Effektiv entsteht so eine serielle Anordnung von Objekten im Speicher, die
                        * im Code nur zu einer Matrix abstrahiert wird!
                        */

  // go throu all elements of the ptr and assign adresses to them
  for (int i = 1; i < 3; i++){
    b[i] = b[0] + i*5; // setze die Adressen der 3 Pointer auf die entsprechenden Orte im Speicher
    // so entsteht die Abstraktion auf ein 2-dimensionales Objekt!
  }

  /*
  * Beim Zugriff auf b[1][3] wird auf das zweite Element des Integer-Arrays, das sich im Integer-Pointer-Array auf der 2ten Position befindet, zugegriffen
  *
  *
  */

  delete [] b[0]; // lösche das NxM Integer-Array
  delete [] b;    // lösche das Pointer-Array
   // [] sagt, dass wir Feld löschen. er schaut dann nach, wo und wie die Felddefiniton war und löscht das ganze Element, dass sich dahinter versteckt.
   // ohne die [] wird nur das erste Feld gelöscht, auf den der Ptr zeigt! ~> wäre hier fehlerhaft!

  return 0;
}
