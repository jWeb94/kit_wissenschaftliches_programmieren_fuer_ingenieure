#include<iostream>

using namespace std;

void myFunction(int * &); // forward declaration

int main(){
  int a = 42;
  int * b = &a; // b ist ein Pointer auf a

  //myFunction(&a); // &a delivers the adress of a - geht nicht, da &a keine Adresse hat!
  myFunction(b);
  
  return 0;
}

void myFunction(int * & myInt){
  cout << "this is the adress of the given integer: " << myInt << " ,with the value: " << *myInt << endl;
}
