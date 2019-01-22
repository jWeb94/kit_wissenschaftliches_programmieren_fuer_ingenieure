#include<iostream>

using namespace std;

int main(){
  int a;
  double b = 8.0;
  double c = 10.0;

  a = c/b;

  cout << "implizite Typenumwandlung:" << endl;
  cout << a << endl; // 1

  cout << "nicht im Wertebereich" << endl;
  short e;
  e = 829*777;       // Geht in die Komplementendarstellung = -11227
  cout << e << endl;

  double testDiv;
  testDiv = 10.0/8;
  cout << "testDiv: " << endl;
  cout << testDiv << endl;

  cout << "test Casting: " << endl;
  double f = 1.8f; // weglassen von f (fuer float) aendert nichts!
  int j = f;      // implizite Typenumwandlung
  int i = (int)f; // explizite Typenumwandlung

  cout << "j: " << j << endl;
  cout << "i: " << i << endl;

  return 0;
}
