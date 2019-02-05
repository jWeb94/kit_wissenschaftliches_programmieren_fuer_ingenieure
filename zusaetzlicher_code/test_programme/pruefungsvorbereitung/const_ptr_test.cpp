#include<iostream>

using namespace std;

int main(){
  int i = 20;
  int j = 40;

  int * const i_ptr_const = &i;

  const int * i_const_ptr = &i;

  const int * const i_const_const = &i; // Kein anderer Wert und keine andere Adresse!

  //i_ptr_const = &j;
  i_const_ptr = &j;

  * i_ptr_const = 42;
  //* i_const_ptr = 42;


  return 0;
}
