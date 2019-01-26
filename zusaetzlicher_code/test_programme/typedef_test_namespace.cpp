#include<iostream>
#include <typeinfo>


namespace test_namespace{
  typedef float GleitZahl;

  GleitZahl test_zahl = 5.5;


}


int main(){
  {
  // Scope 1
  typedef double GleitZahl;

  std::cout << "this is test_zahl from namespace test_namespace: " << test_namespace::test_zahl << " of the type: " << typeid(test_namespace::test_zahl).name() << std::endl;
  {
  // Unterlagerter Scope 1.1
  GleitZahl b = 3.3;  
  std::cout << "this is b: " << b << " of the datatype " << typeid(b).name() << std::endl;
  }
  }

  /*
  {
  // Scope 2
  GleitZahl c = 8.8; // Typedef gilt hier nicht, da es ein unabhaengiger Scope vom Scope 1 ist!
  std::cout << "this is c: " << c << " of the datatype " << typeid(c).name() << std::endl;


  }
  */
  return 0;
}
