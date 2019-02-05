#include<iostream>
#include"myClass.h" // um die Schnittstellen zu includieren!

using namespace std;

int main(){
  // Klasseninstanzierung
  myClass a(4, 6);
  myClass b(8, 3);

  myClass c;    // Erstelle ein myClass Objekt mit dem Standartkonstruktor (ohne Wertzuweisung)
  cout << "this is the adress of c.a before the copy operator: " << c.get_a_ptr() << endl;
  cout << "this is the value of c.a before the copy operator: " << c.get_a() << endl;
  // Man sieht: Ohne Initialisierung durch den Standartkonstruktor wir ein mehr oder weniger zufaelliger Wert initialisiert, also das was zufaellig gerade an der Speicherstelle steht.

  // c = a;        // Kopieroperator mit Objekt der selben Klasse ist per default ueberladen
  c.operator=(a);

  cout << "full assignment of a to c was successful" << endl;

  cout << "adress of a.a is: " << a.get_a_ptr() << endl;
  cout << "the value of a.a is: " << a.get_a() << endl;

  cout << "the adress of c.a is: " << c.get_a_ptr() << endl;
  cout << "the value of c.a is: " << c.get_a() << endl;

  // Test Kopieroperator:
  myClass d;
  d = a;      // Kopieroperator ist per Default ueberladen!

  cout << "full copy of a to d was successful" << endl;

  cout << "adress of a.a is: " << a.get_a_ptr() << endl;
  cout << "the value of a.a is: " << a.get_a() << endl;

  cout << "the adress of d.a is: " << c.get_a_ptr() << endl;
  cout << "the value of d.a is: " << c.get_a() << endl;

  cout << "changeing the value d.a to 42" << endl;
  d.set_a(42);
  cout << "this is the value a.a: " << a.get_a() << endl;
  // Wir sehen, mit dem Kopieroperator wird eine 'full copy' angefertigt!

  // Kopierkonstruktor:
  cout << "tested copy construktor with object w with handed objekt d (42, 4)..." << endl;
  myClass w(d);
  cout << "this is w.a: " << w.get_a() << " with the adress " << w.get_a_ptr() << endl;

  // Rechenoperatoren
  myClass f;
  int zuweisung_f = 666;
  f.operator=(zuweisung_f);
  cout << "here are the component a of f: " << endl;
  cout << "f.a: " << f.get_a() << endl;

  derived my_derived; // Standartkonstruktor von derived wird aufgerufen!

  // f = a + b;
  // f = a*b;
  cout << "END!" << endl;
  return 0;
}
