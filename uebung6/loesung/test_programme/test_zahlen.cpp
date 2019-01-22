#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  double test15 = 1.e15;
  double test16 = 1.e16;

  //cout << fixed << "test15: " << test15 << endl;
  cout << "test15: " << test15 << endl;
  //setprecision(16);
  cout << setprecision(6) << "test16: " << 1234567.1234567 << endl;
  cout << 12345678 << endl;

  test15 += 1;
  test16 += 1;

  cout << "test15 + 1: " << test15 << endl;
  cout << "test16 + 1: " << test16 << endl;

  test16 = 1.e16;
  cout << fixed << setprecision(6) << "1/3: " << 1./3. << endl;
  test16 -= 11;
  cout << "test16 add on: " << test16 << endl;

  return 0;
}
