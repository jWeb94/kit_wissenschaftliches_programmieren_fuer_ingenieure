#include<iostream>


int main(int argc, char * argv[]){

  std::cout << "Have received " << argc << " input arguments: " << std::endl;

  // Das 0te Argument ist der Funktionsaufruf! Deshalb kommen die tatsaechlichen Parameter beim Index 1, ...
  for (int i = 1; i < argc; i ++){
    std::cout << i <<"th argument: " << argv[i] << std::endl;
  }
  return 0;
}
