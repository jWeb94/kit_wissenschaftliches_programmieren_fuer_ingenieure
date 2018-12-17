#include<iostream>
#include"complex.h"


int main(){

  using namespace std;

  // Test der Berechnung
  MyComplex z_1(2, 3);
  MyComplex c(-0.75, 0.1);
  MyComplex z_result;

  z_result = (z_1^2).operator+(c);

  cout << "this is z_result = z_1^2 + c: " << endl;
  z_result.printComponents();


  // Test der Setter-Methoden
  MyComplex testSetter(-1, -1);
  testSetter.setRe(testSetter.real() + 3);
  cout << "this is testSetter after setting the real-component to 3: " << endl;
  testSetter.printComponents();

  return 0;
}
