#include <iostream>
#include <array>

// global variables
int numIter = 1; // mandatory to check if the max iteration is reached in the fibonacci calculation
std::size_t counter;

void inputParserInt(std::string description, int & outputArg){
  std::cout<<"Please insert " << description << ": " << std::endl;
  std::cin >>outputArg;
}


int fiboApprox(int  f_i, int f_i_m1){
  /*
  // debug
  std::cout << "counter is: " << counter << std::endl;
  std::cout << "numIter is: " << numIter << std::endl;
  */

  // TODO: Musterloesung ist goldener Schnitt: 1.6...
  //      Fibonaccizahl
  // Versuche die Zahlen in ein 2d array abzuspreichern. Dieses in Datei schreiben und einmal über array iterieren und über errorchannel ausgeben

  int outputVal;
  if (counter == numIter){
      return outputVal;
  }
  else{
    outputVal = f_i + f_i_m1;
    std::cout << "The temporary output value of iteration " << counter <<  " is: " << outputVal << std::endl;
    counter ++;
    fiboApprox(outputVal, f_i);
  }
}


int main(){
  // variable declarations
  std::string inputArgDescipt = "number of fibonacci iterations";
  int startValue0 = 0;
  int startValue1 = 1;
  double resultFibo;
  double goldenValue;

  // get the number of iterations
  inputParserInt(inputArgDescipt, numIter);

  // const int numIterConst = numIter; // to use a variable for initializing an array, the variable must be an Integral Constant Expression (ICE)! It must be computable by compile time
  //const std::vector<int> numIterConst = numIter;
  const int numIterConst = numIter;

// TODO: vector of vector to solve the problem
// oder mit EIGEN3
  //create result array based on the number of iterations
  std::array<std::array<double, 3>, numIter> resultArray; // numIterConst must be an constant expression, due to the fixed size of the array-if numIter would change it implies that the array changes size, which is not possible
  std::cout << resultArray.size()<< std::endl; // debug

  resultFibo = fiboApprox(startValue0, startValue1);


  std::cout << "The result of the fibonaccti calculation is: " << resultFibo << std::endl;




}
