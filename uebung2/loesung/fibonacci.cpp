#include <iostream>

// global variables
size_t numIter = 1; // mandatory to check if the max iteration is reached in the fibonacci calculation
std::size_t counter = 0;

void inputParserInt(std::string description, size_t & outputArg){
  std::cout<<"Please insert " << description << ": " << std::endl;
  std::cin >>outputArg;
  //if (outputArg <= 1){
  //  Exit(0);
  //}
}


void fiboApprox(double** resultArrayRef, int  f_i, int f_i_m1){
  // calculate the fibonacci values and the golden mean
  int outputVal;
  if (counter == numIter){
      std::cout << "finished calculating" << std::endl;
      std::cout << "the number of iterations is: " << resultArrayRef[numIter -1][0] << std::endl;
      std::cout << "the fibonacci value is: " << resultArrayRef[numIter - 1][1] << std::endl;
      std::cout << "the golden mean is: " << resultArrayRef[numIter - 1][2] << std::endl;
  }
  else{
    outputVal = f_i + f_i_m1;
    std::cout << "The temporary output value of iteration " << counter <<  " is: " << outputVal << std::endl;

    // write results in the result array
    resultArrayRef[counter][0] = counter;                                 // counter
    resultArrayRef[counter][1] = outputVal;                               // current value
    if (counter == 0){
        resultArrayRef[counter][2] = outputVal/outputVal; // in the first iteration we just have the initial value to calculate the golden mean
    }
    else{
        resultArrayRef[counter][2] = outputVal/resultArrayRef[counter - 1][1];   // golden mean
    }
    // counter increment
    counter ++;

    fiboApprox(resultArrayRef, outputVal, f_i);
  }
}

void writeToErrorChannel(double ** results){
  // there is no function to get the size of the array if you did not use a library, so we have to hard code it!
  for (int i = 0; i < numIter; i++){
    std::cerr << results[i][0] << " " << results[i][1] << " " << results[i][2] << std::endl;
  }
}


int main(){

  // TODO: Warum geht das nur bis 46? 

  // variable declarations
  std::string inputArgDescipt = "number of fibonacci iterations";
  int startValue0 = 0;
  int startValue1 = 1;
  double resultFibo;
  double goldenValue;

  // get the number of iterations
  inputParserInt(inputArgDescipt, numIter);

  // create result array on the heap
    // cohesive memory
  double ** feld2d;                          // we want an pointer to an pointer
    // every new delivers an adress and creates a field on the heap
  feld2d = new double *[numIter];            // rows -> create an pointer to an array with numIter elements of the type int
    // write an adress/pointer-array of the size numIter
  feld2d[0] = new double [numIter*3];        // columns -> pointer to the first element of the array with numIter elements, that includes an pointer to a 3 element array
    // hier wird der Zeilenvektor im Speicher erstellt
  for (size_t i = 1; i < numIter; i++){
    feld2d[i] = feld2d[0] + i * 3; // i th row with 3 elements
    // hier werden die Zeiger auf die Positionen im Speicher verlinkt!
    // die Idee ist: Im 0ten Element steht ein Zeilenvektor im Speicher und in allen anderen numIter Elementen stehen nur Adressen (vgl Z 56), die auf die Elemente im 0ten Element stehen!

    // Ursprungsadresse + i entspricht dem i*3 tem Zeilenelement
    // i*3 beschreibt die Stelle im Speicher
    // Ich baue einen Zeilenvektor im Speicher auf, der numIter*3 Elemente hat.
    // Jedes i*3 te Element entspricht der Spalte
  }

  fiboApprox(feld2d, startValue0, startValue1);

  std::cout << "The result of the fibonaccti calculation is: " << feld2d[numIter-1][2] << std::endl;        // -1 due to the begin of the iteration at the 0th element
  std::cout << "The golden mean of the fibonaccti calculation is: " << feld2d[numIter-1][3] << std::endl;

  writeToErrorChannel(feld2d);

  // delete the result array to avoid an dangeling pointer
  delete[] feld2d[0]; // delete the value array
  delete[] feld2d;    // delete the adress array

  std::cout << "Finished with the calculation" << std::endl;

  /*
   * const int numIterConst = numIter; // to use a variable for initializing an array, the variable must be an Integral Constant Expression (ICE)! It must be computable by compile time
   *
   *std::array<std::array<double, 3>, numIter> resultArray; // numIterConst must be an constant expression, due to the fixed size of the array-if numIter would change it implies that the array changes size, which is not possible
   *std::cout << resultArray.size()<< std::endl; // debug
   * // This does not work, due to the array-condition of an ICE
   *
   * resultFibo = fiboApprox(resultArray, startValue0, startValue1);
   */
}
