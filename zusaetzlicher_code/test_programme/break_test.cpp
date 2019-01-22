#include<iostream>

using namespace std;

int main(){
  int counter = 0;

  while (true){ // quasi eine Endlosschleife
    cout << "while call no.: " << counter << endl;
    counter += 1;
    {
    if (counter == 10){
      cout << "stopped the while loop!" << endl;
      break;
    }
  }
  }
  return 0;
}
