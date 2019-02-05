#include<iostream>

class baseClass{
public:
  //baseClass(){}//=default; // Wenn ich den Standart-Konstruktor nicht explizit schreibe, wenn andere Konstruktoren existieren, wird dieser NICHT automatisch implizit erstellt!
  baseClass()=default;        // Ich kann default schreiben fuer den impliziten Standart-Konstruktor, oder ich mache die {} fuer einen 'selbst geschriebenen Standart-Konstruktor' (das macht der Compiler sonst implizit wenn ich default schreibe!)
  baseClass(int initVal): a(initVal), b(initVal){}
  baseClass(int a_val, int b_val): a(a_val), b(b_val){}
  virtual void print_all_members(){
    std::cout << "this is a: " << this->a << " and this is b: " << this->b << std::endl;
  }
  void print_all_members_twice(){
    std::cout << "this is a: " << this->a << " " <<  this->a << " and this is b: " << this->b << " " << this->b << std::endl;
  }

private:
  int a;
  int b;

protected:
  int get_a(){
    return this->a;
  }
  int get_b(){
    return this->b;
  }
};


class derivedClass: public baseClass{
public:
  derivedClass()=default;
  derivedClass(int initVal): baseClass(initVal), c(initVal){}
  /*
  // Wenn die virtual methode nicht in der abgeleiteten Klasse implementiert wird, wird einfach die methode der Basisklasse verwendet!
  void print_all_members(){
    std::cout << "this is a: " << this->get_a() << " and this is b: " << this->get_b() << " and this is c: " << this->c << std::endl;
  }
  */
  void print_all_members(){
    std::cout << "this is a: " << this->get_a() << " and this is b: " << this->get_b() << " and this is c: " << this->c << std::endl;
  }

  void print_all_members_twice(){
    std::cout << "this is a: " << this->get_a() << " " <<  this->get_a() << " and this is b: " << this->get_b() << " " << this->get_b() << " and this is c: " << this->c << " " << this->c << std::endl;
  }


private:
  int c;
};







int main(){
  derivedClass test_1;          // call implicit standart constructor
  test_1.print_all_members();   // Ohne initialisierung werden zufaellige Werte, die noch im Speicher standen ausgegeben!

  // Erstelle ein Objekt der abgeleiteten Klasse, mit zwei Pointern auf das Objekt gerichtet
  derivedClass * test_2 = new derivedClass(5);  // Erstelle neues Objekt auf dem Heap
  baseClass * base_ptr_to_test_2 = test_2;      // Lasse zweiten Pointer auf das Objekt auf dem Heap zeigen, wobei dieser Pointer vom Typ der Basisklasse ist. (=Polymorphie)

  std::cout << "this is the print_all_members method with test_2 (pointer of the derived class): " << std::endl;
  test_2->print_all_members();
  std::cout << "this is the print_all_members method with base_ptr_to_test_2 (pointer of the base class): " << std::endl;
  base_ptr_to_test_2->print_all_members();
  std::cout << "we see: the executable chooses always the correct method for the most derived object!" << std::endl;

  std::cout << "this is the non virtal print_all_members_twice method with the derived class pointer test_2: "  << std::endl;
  test_2->print_all_members_twice();
  std::cout << "this is the non virtual print_all_members_twice method with the base class pointer base_ptr_to_test_2: " << std::endl;
  base_ptr_to_test_2->print_all_members_twice();
  std::cout << "we see: the executable chooses the method of the corresponding pointer type!" << std::endl;

  


  delete test_2; // free memory
  /*
  std::cout << "this is the base class pointer after delete test_2: " << std::endl;
  base_ptr_to_test_2->print_all_members();
  // Das erzeugt einen runtime error - 'Speicherzugriffsfehler'!
  */

  return 0;
}
