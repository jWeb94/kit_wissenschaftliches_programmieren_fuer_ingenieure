#include"myClass.h"  // Stellt die Abhaenigkeit her, damit ich in der Implementierung auch alle anderen Methoden, Variablen und Funktionen verwenden kann. Ohne das wuerde this->x nicht funktionieren!

using namespace std;


myClass::myClass(){
  cout << "called the standart constructor" << endl;
  //this->a = -1;
  //this->b = -1;
}


myClass::myClass(int in_1, int in_2){
  cout << "called construktor 1" << endl;
  this->a = in_1;
  this->b = in_2;
  // this: liefert Pointer (!) auf das aufrufende Objekt der Methode/des Konstruktors!
}

myClass::myClass(int input_val){
  cout << "called construktor 2" << endl;
  this->a = input_val;
  this->b = input_val;
}

/*
// Kopierkonsruktor - wenn nicht implementiert wird dieser implizit erzeugt!
myClass::myClass(const myClass & handed_object){
  cout << "COPY CONSTRUCTOR" << endl;
  this->a = handed_object.a;
  this->b = handed_object.b;
}
*/

myClass::~myClass(){
  cout << "called destruktor" << endl;
}

// Operatoren
myClass & myClass::operator=(int x){
  cout << "called assignment operator" << endl;
  this->a = x;
  this->b = x;
  return *this;
}

myClass & myClass::operator=(const myClass & input_objekt){
  cout << "called copy '=' operator!" << endl;
  this->a = input_objekt.a; // hier kann ich mit . drauf zugreifen, da ich auf das uebergebene Objekt, nicht auf das aufrufende Objekt zugreifen will!
  this->b = input_objekt.b;
  return *this; // Das ist quasi RHS - also liefert * die Adresse des aufrufenden Objekts!
}



// Methoden
int * myClass::get_a_ptr() {
  return &this->a; // dereferenziere das was in der Membervariable steht und liefere eine (temporaere Kopie zurueck)
}

int myClass::get_a(){
  return this->a;
}

void myClass::set_a(const int & val_a){
  this->a = val_a;
}


derived::derived()//:myClass(-1, -1), r(-1)
{
  cout << "Standartkonstruktor derived was called!" << endl;
  
}
