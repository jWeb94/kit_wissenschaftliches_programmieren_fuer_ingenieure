#include<iostream>

using namespace std;

// Klassendeklaration
// class myClass; // Das geht nicht, da das nur bekannt gibt, dass an dieser Stelle die Klassendefinition aus einem anderen Translation Unit eingefuegt werden muss

// Klassendefinition
class myClass{

public:
  //myClass();                    // Standartkonstruktor
  //myClass(int in_1, int in_2);  // Ueberladener Konstruktor 1
  myClass(int input_val);       // Ueberladener Konstruktor 2

  // Destruktor
  ~myClass();

  void set_a(const int & val_a); // const, da ich den uebergebenen Wert nicht veraendern will. Dieser soll ja genau in die Membervariablen unveraendert geschrieben werden!
  void set_b(const int & val_b);
  int get_a() const;              // nachgestelltes const: Objekt laesst sich spaeter nicht mehr veraendern!
  int get_b() const;

private:
  int a;
  int b;
};

// Beschreibung der Methoden, Operatoren, Destruktoren und Konstruktoren der Klasse
// ACHTUNG: Das MUSS nach der Klassendefinition kommen!
/*
myClass::myClass(){
  cout << "called the standart constructor" << endl;
}

myClass::myClass(int in_1, int in_2){
  cout << "called construktor 1" << endl;
  this->a = in_1;
  this->b = in_2;
  // this: liefert Pointer (!) auf das aufrufende Objekt der Methode/des Konstruktors!
}
*/
myClass::myClass(int input_val){
  cout << "called construktor 2" << endl;
  this->a = input_val;
  this->b = input_val;
}


myClass::~myClass(){
  cout << "called destruktor" << endl;
}

int main(){
  // Klasseninstanzierung
  //myClass a(); // Mit Standartkonstruktor
  //myClass b();
  myClass c(5); // Das ruft den Konstruktor 2 auf
  // myClass d;    // rufe Standartkonstruktor auf ~ geht nicht, wenn ein anderer Konstruktor existiert und der Standartkonstruktor nicht explizit geschrieben wird!




  return 0;
}
