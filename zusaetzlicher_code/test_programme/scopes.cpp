#include<iostream>

using namespace std;

int i = -1;

int main(){
  int i = 10;

  {
    int i = 20;

    {
      int i = 30;
      cout << "this is i in the third scope: " << i << endl;
      cout << "this is ::i in the thrid scope: " << ::i << endl;
    }

    cout << "this is i in the secound scope: " << i << endl;
    cout << "this is ::i in the secound scope: " << ::i << endl;
    ::i = i;
    cout << "assigned the local i to the gloal i!" << endl;
  }

  cout << "this is i in the thirst scope: " << i << endl;
  cout << "this is ::i in the thirst scope: " << ::i << endl; 

  return 0;
}
