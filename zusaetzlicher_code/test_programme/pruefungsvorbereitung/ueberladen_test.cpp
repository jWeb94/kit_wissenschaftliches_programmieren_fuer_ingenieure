#include<iostream>

using namespace std;

void function_1 (int i){
  cout << "this is i: " << i << endl;
}

int function_1 (int i){
  cout << "this is i: " << i << " ; give back i!" << endl;
}


int main(){

  int a = 20;

  function_1(a);
  int b = function_1(a); 


  return 0;
}
