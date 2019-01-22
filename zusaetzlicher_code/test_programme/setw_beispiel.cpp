#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  cout << setw(5);
  cout << 77 << endl;

  cout << setw(5) << "test" << endl;
  cout << setw(5) << 123456 << endl;
  return 0;
}
