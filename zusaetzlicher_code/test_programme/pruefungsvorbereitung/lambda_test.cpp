#include<iostream>

using namespace std;

int use_function(int i, float(*temp_func)(float)){
  // mit float(*temp_func)(float) wird spezifiziert, welche Art von Funktionspointern an die Funktion uebergeben werden koennen! 
  return float(i)*temp_func(float(i));
}

int main(){

  // Funktionszeiger:
  float (*myLam) (float) = [] (float x) mutable -> float {return x*42.0f;};

  cout << "this is myLam(5): " << myLam(5) << endl;

  cout << "this is use_function(5, myLam)" << use_function(5, myLam) << endl;

  return 0;
}
