#include<iostream>
#include<string>

int main (){
  using namespace std;

  double a, b;
  cout << "please insert a and b: " << endl;
  cin >> a >> b;
  cout << "this is a and b: " << a << ", " << b << endl;

  string testString;
  cout << "please insert the test string" << endl;
  cin >> testString;

  cout << "this is the testString: " << endl;
  cout << testString << endl;

  return 0;
}
