#include<iostream>

enum test {var1, var2, var3};

using namespace std;

int main(){

  test instanz1, instanz2;

  instanz1 = var1;
  instanz2 = var3;

  cout << instanz1 << " " << instanz2 << endl;


  return 0;
}
