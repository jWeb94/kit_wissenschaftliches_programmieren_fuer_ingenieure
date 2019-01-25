#include<iostream>
#include<vector>

struct test_datatype{
  int a;
  double b;
  std::vector<int> vec;
};

void print_std_vector(std::vector<int> & vector_int){
  for (int i = 0; i < vector_int.size(); i++){
    std::cout << "vectorelement " << i << " is: " << vector_int.at(i) << std::endl;
  }
};


int main(){

  test_datatype new_struct1;
  new_struct1.a = 5;
  new_struct1.b = 3.5;
  //new_struct1.vec = std::vector<int>(3, 10);        // 1x3 Vector mit allen Eintraegen 10, vgl Konstruktor aus STL
  new_struct1.vec = std::vector<int>{11, 12, 13};     // direkte Wertinitialisierung
                                                      // Anmerkung: {} ruft auch einen Konstruktor mit den entsprechenden Uebergabeparametern auf! Ist also quasi aequivalent zu std::vector<int>(5, 5, 5)
  std::cout << "this is new_struct1.a: " << new_struct1.a << std::endl;
  std::cout << "this is new_struct1.b: " << new_struct1.b << std::endl;
  std::cout << "this is new_struct1.vec: " << std::endl;
  print_std_vector(new_struct1.vec);

  // Andere Moeglichkeit zur Initialisierung:
  std::cout << "here comes new_struct2:" << std::endl;
  test_datatype new_struct2 = {5, 6, std::vector<int>(3, 15)};

  std::cout << "this is new_struct2.a: " << new_struct2.a << std::endl;
  std::cout << "this is new_struct2.b: " << new_struct2.b << std::endl;
  std::cout << "this is new_struct2.vec: " << std::endl;
  print_std_vector(new_struct2.vec);

  // Structs als Pointervariablen
  std::cout << "test_ptr as struct pointer: " << std::endl;
  test_datatype * test_ptr;
  test_ptr = new test_datatype{9, 8.2, std::vector<int>(3, 11)}; // neues Element auf dem Heap

  std::cout << "this is test_ptr.a: " << test_ptr->a << std::endl; // Bei Pointern brauche ich den Memberzugriffsoperator fuer Pointer/Referenzen '->', nicht den normalen Memberzugriffsoperator '.' wie bei normalen Variablen
  std::cout << "this is test_ptr.b: " << test_ptr->b << std::endl;
  std::cout << "this is test_ptr.vec: " << std::endl;
  print_std_vector(test_ptr->vec);

  delete test_ptr; // Gib Speicher wieder frei

  return 0;
}
