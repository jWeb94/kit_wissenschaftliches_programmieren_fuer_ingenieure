#include<iostream>
#include<typeinfo>
#include<string>


// Beispiel fuer Funktionen
template<typename T>
void Print(T value){
  std::cout << value << std::endl;
  std::cout << "this is the Type: " << typeid(value).name() << std::endl;
}

// Das ist, was waehrend der Compile-Zeit passiert:
// Der Compiler schreibt die Folgenden Funktionen, basierend auf der Verwendung des Templates
/*

// Es wird fuer jeden verwendeten Datentyp eine Kopie der Template-Funktion erstellt und die entsprechenden Typen/Werte, mit denen das Template aufgerufen wird, eingesetzt!
void Print(float value){
  std::cout << value << std::endl;
  std::cout << "this is the Type: " << typeid(value).name() << std::endl;
}

void Print(string value){
  std::cout << value << std::endl;
  std::cout << "this is the Type: " << typeid(value).name() << std::endl;
}

*/

// Beispiel fuer Klassen

template<typename T, int N>
class Array{
public:
  int get_size() const { return N; }
private:
  T m_Array[N]; // Stack Alloziert -> Muss waehrend der Compile-Zeit bekannte Groesse haben!
};

/*

// Das passiert waehrend der Compile-Time:
// Es wird T und N fuer die Verwendung des Templates eingesetzt
// Anmerkung:
  // Dadurch ist es moeglich, das Array auf dem Stack zu erstellen und trotzem eine dynamische Groesse abzubilden.
  // Denn waehrend der Compile-Zeit wird eine Version mit der fixen Array-Groesse N erzeugt.
  // Es ist zwar immer noch nicht moeglich, ein Array mit dynamischer Groesse mit cin zu erzeugen, aber ich bin wesentlich flexibler und teilweise im Code auch effizienter
  // was die Groesse und dessen Zugriff angeht!

  class Array{
  public:
    int get_size() const { return 5; }
  private:
    float m_Array[5]; // Stack Alloziert -> Muss waehrend der Compile-Zeit bekannte Groesse haben!
  }

  class Array{
  public:
    int get_size() const { return 2; }
  private:
    int m_Array[2]; // Stack Alloziert -> Muss waehrend der Compile-Zeit bekannte Groesse haben!
  }

*/


int  main(){
  //Print(5);
  //Print<int>(6.1);         // Verwende die Printfunktion mit dem Typ T=int -> Dann wird die Zahl implizit gecasted
  Print(5.5);              // Gebe ich keinen Typ explizit an, so wird der Typ bei der Compile-Time deduziert
  Print("Hello World");    // Hier wird ein String/

  std::cout << "here comes the class template" << std::endl;

  Array<float, 5> test_array;
  std::cout << "this is the size of the test_array: " << test_array.get_size() << std::endl;

  Array<int, 2> test_array_2;
  std::cout << "this is the size of the test_array: " << test_array_2.get_size() << std::endl;

  return 0;
}
