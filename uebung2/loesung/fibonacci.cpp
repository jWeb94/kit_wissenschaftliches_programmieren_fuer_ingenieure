#include <iostream>

// global variables
size_t numIter = 1; // mandatory to check if the max iteration is reached in the fibonacci calculation
std::size_t counter = 1;

void inputParserInt(std::string description, size_t & outputArg){
  std::cout<<"Please insert " << description << ": " << std::endl;
  std::cin >>outputArg;
  //if (outputArg <= 1){
  //  Exit(0);
  //}
}


int fiboApprox(double** resultArrayRef, int  f_i, int f_i_m1){
  // calculate the fibonacci values and the golden mean
  int outputVal;
  if (counter == numIter){
      // return outputVal;
      // write results in the result array
      resultArrayRef[counter][0] = counter;                                 // counter
      resultArrayRef[counter][1] = outputVal;                               // current value
      resultArrayRef[counter][2] = outputVal/resultArrayRef[counter - 1][1];   // golden mean

  }
  else{
    outputVal = f_i + f_i_m1;
    std::cout << "The temporary output value of iteration " << counter <<  " is: " << outputVal << std::endl;

    // write results in the result array
    resultArrayRef[counter][0] = counter;                                 // counter
    resultArrayRef[counter][1] = outputVal;                               // current value
    resultArrayRef[counter][2] = outputVal/resultArrayRef[counter - 1][1];   // golden mean

    // counter increment
    counter ++;

    fiboApprox(resultArrayRef, outputVal, f_i);
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

  resultFibo = fiboApprox(feld2d, startValue0, startValue1);

  std::cout << "The result of the fibonaccti calculation is: " << feld2d[numIter][2] << std::endl;
  std::cout << "The golden mean of the fibonaccti calculation is: " << feld2d[numIter][3] << std::endl;

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
