#include<iostream>

using namespace std;

int main(){
  int test = 6;
  int counter = 0;
  for (int i = 0; i < 10; i++){
    if(i == 2){
      cout << "here comes continue" << endl;
      continue;
    }
    counter += 1;
    cout << "for counter: " << counter << endl;
    cout << "i of counter " << counter << " is: " << i << endl;
  }
  cout << "end of the program" << endl;
  return 0;
}
