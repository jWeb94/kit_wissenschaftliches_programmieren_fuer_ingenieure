#include<iostream>

using namespace std;


class baseClass
{
public:
  baseClass(): a(-1), b(-1){std::cout << "Standartconstructor baseClass was called" << std::endl;}
  baseClass(const int initVal)
  {
    this->a = initVal;
    this->b = initVal;
  }
  baseClass(int a_value, int b_value): a(a_value), b(b_value){std::cout << "the init a, b constructor of baseClass was called!" << std::endl; }

  int get_a(){
    return this->a;
  }

  int get_b(){
    return this->b;
  }


private:
  int a;
  int b;
  friend class setterClass;



protected:
  void set_a(int a_handed){
    this->a;
  }
  void set_b(int b_handed){
    this->b;
  }
  void print_test(){
    std::cout << "this is a test for publishing protected methods with using" << std::endl;
  }
};

class derivedClass: public baseClass
{
public:
  derivedClass(): c(-1){}
  derivedClass(int a_val, int b_val, int c_val): baseClass(a_val, b_val), c(c_val){}
  /*
  derivedClass(int initValue){
    // Hier wird zuerst der Standartkonstruktor von baseClass aufgerufen und dann dieser Konstruktor (vgl Ausgabe, wenn einkommentiert)
    std::cout << "called the initValue constructor of the derivedClass" << std::endl;
    this->set_a(initValue);     // Auch in erbenden Klassen kann ich nicht auf private Elemente der baseClasszugreifen!
    this->set_b(initValue);     // Daher muss ich das mit Funktionen machen. Wenn diese nach ausserhalb der Klasse hin nicht sichtbar sein sollen, muessen die setter protected sein!
    this->c = initValue;
  }
  */
  derivedClass(int initValue): baseClass(initValue, initValue), c(initValue){}

private:
  int c;
};

class setterClass
{
public:
  void set_a(int a_set, baseClass & class_input){
    class_input.a = a_set;
  }
  void set_b(int b_set, baseClass & class_input){
    class_input.b = b_set;
  }
};


int main(){
  derivedClass testInstance_1;
  derivedClass testInstance_2(5);
  derivedClass * derivedClass_ptr = &testInstance_2;

  setterClass set_obj;
  set_obj.set_a(22, testInstance_2);
  cout << "this is testInstance_2.a: " << derivedClass_ptr->get_a() << endl;

  return 0;
}
