#include<iostream>

using namespace std;

int main(){
  int inputVar;
  cin >> inputVar;

  switch(inputVar){
    case(1):
      cout << "case 1" << endl;
      // ohne break wird einfach weiter ausgefuehrt!
    case(2):
      cout << "case 2" << endl;
      break;
    case(3):
      cout << "case 3" << endl;
      break;
    default:
      cout << "default was called" << endl;
  }

  return 0;
}
