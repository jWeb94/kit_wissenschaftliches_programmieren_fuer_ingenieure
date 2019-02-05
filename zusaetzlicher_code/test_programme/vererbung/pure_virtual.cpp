#include<iostream>
#include<string>

class Printable
{
public:
  virtual std::string get_str() = 0; // Definition einer pure virtal Memberfunction
};

class classA : public Printable
{
public:
  classA(std::string inString): internal_string_classA(inString){} // Construktor -> jetzt ist der Standartkonstruktor gesperrt!
  std::string get_str(){
    return this->internal_string_classA;
  }
private:
  std::string internal_string_classA;
};

class classB : public Printable
{
public:
  classB()=default; // Hier existiert auch der Standartkonstruktor, da ich ihn explizit hin schreibe!
  classB(std::string input): internal_string_classB(input){}
  std::string get_str(){
    return this->internal_string_classB;
  }

private:
  std::string internal_string_classB;
};

class classC: public classB
{
public:
  std::string get_str(){
    return additional_string;
  }
private:
  std::string additional_string = "this is the additional string!";
};

void print_name(Printable * print_obj){
  std::cout << print_obj->get_str() << std::endl; // Ansprechen des uebergebenen Objekts als Pointer der Basisklasse
                                                  // Durch virtal wird V-tabel aufgebaut
                                                  // Durch =0 wird die Memberfunction zur pure virtal function, muss also in jeder abgeleiteten Klasse definiert sein
                                                  // Daraus folgt, dass immer die Funktion der jeweils abgeleiteten Klasse verwendet wird!
}

int main(){
  classA * testA = new classA("Test A"); // Das funktioniert nicht, da der Standartkonstruktor nicht existiert, da es einen anderen Konstruktor gibt!
    // ACHTUNG: fuer Polymorphie muss ich mit Pointern arbeiten!
  print_name(testA);

  //classB * testB = new classB(); // Ohne initialisierung von internal_string_classB
  classB * testB = new classB("input B");
  print_name(testB);

  classC * testC = new classC();
  print_name(testC);

  // setze zweiten Pointer auf testC Objekt auf dem Heap mit einem Pointer vom Typ classB:
  classB * secound_ptr_classB = testC;
  print_name(secound_ptr_classB); // Hier kommt nach wie vor "this is the additional string" raus, da im V-tabel durch den virtual befehl die Methode der classC raus gesucht wird!

  return 0;
}
