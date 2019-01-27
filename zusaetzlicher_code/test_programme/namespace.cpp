#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

namespace apple{
  void print(string test_str){
    cout << "this is the apple print: " << test_str << endl;
  }
}


namespace orange{
  void print(string test_str){
    cout << "this is the orange print: " << test_str << endl;
  }
  namespace nested_orange{
    void print(string test_str){
      cout << "this is nested orange: " << test_str << endl;
    }
  }
  int k = 230;
}


int main(int argc, char* argv[]){
  namespace nns = orange::nested_orange;
  if (argc != 2){
    cout << "ERROR: non valid parameters in the execution call!" << endl;
    exit(EXIT_FAILURE);
  }

  orange::print(argv[1]);
  orange::nested_orange::print(argv[1]);
  nns::print(argv[1]);                    // analoger Aufruf zu vorherigen Zeile

  int k = 5;
  cout << "this is k in the main method: " << k << endl;
  cout << "this is k in from namespace orange: " << orange::k << endl; 

  return 0;
}
