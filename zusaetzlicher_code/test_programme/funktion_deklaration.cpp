#include<iostream>


int addiere (int, int);

int main(){
  int c = addiere(5, 4);
  std::cout << "this is c: " << c << std::endl;
  return 0;
}


int addiere(int a, int b){
  return a+b;
}
