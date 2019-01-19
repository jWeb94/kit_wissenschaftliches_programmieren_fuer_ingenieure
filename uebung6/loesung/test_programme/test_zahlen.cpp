#include<iostream>

using namespace std;

int main(){
  double test15 = 1.e15;
  double test16 = 1.e16;

  cout << fixed << "test15: " << test15 << endl;
  cout << "test16: " << test16 << endl;

  test15 += 1;
  test16 += 1;

  cout << "test15 + 1: " << test15 << endl;
  cout << "test16 + 1: " << test16 << endl;

  test16 = 1.e16;
  cout << "new test 16: " << test16 << endl;
  test16 -= 11;
  cout << "test16 add on: " << test16 << endl;

  return 0;
}
