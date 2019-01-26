#include<iostream>

#define QUADRAT(x) (x)*(x)
#define FALSCHES_QUADRAT(x) x*x


int main(){
  int a = QUADRAT(4);
  int b = FALSCHES_QUADRAT(4);

  std::cout << "this is a: (QUADRAT(4)) " << a << std::endl;
  std::cout << "this is b: (FALSCHES_QUADRAT(4))" << b << std::endl;


  int c = 3;
  int d = 4;

  int erg_normal = QUADRAT(c + d); // (3+4)*(3+4) Richtiges Ergebnis nach binomischer Formel!
  int erg_falsch = FALSCHES_QUADRAT(c + d); // = 3+4*3+4

  std::cout << "This is erg_normal(c+d): " << erg_normal << std::endl;
  std::cout << "This is erg_falsch(c+d): " << erg_falsch << std::endl;


  return 0;
}
