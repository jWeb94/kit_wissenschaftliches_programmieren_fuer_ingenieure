#include <iostream>


int main (){

  // create field
  int * a;
  a = new int[10]; // elements with index 0 to 9

  // see what a actually is
  std::cout << "this is saved in a: " << a << std::endl;
  std::cout << "this is the value saved in a: " << *a << std::endl; // * is the dereference operator

  // write first value to make the calculation in the for-loop possible
  a[0] = 0;

  for (int i = 1; i <= 9; i++){
    a[i] = a[i-1] + 1;
    // output to see what happens
    std::cout << "Element i = " << i << " is: " << a [i] << std::endl;
  }

  a[1] = 42;
  std::cout << "a[1] saved the Value " << a[1] << std::endl;

  int * b;
  b = a + 1;
  std::cout << "this is the pointer/place in memory, where a[1] is located: " << b << std::endl; 

  std::cout << "this is the Value of the object of the pointer a+1: " << *(a+1) << std::endl;

  // free the memory that is allocated by a
  delete [] a;

  return 0;
}
