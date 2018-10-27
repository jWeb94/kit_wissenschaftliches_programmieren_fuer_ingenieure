// includes
#include <iostream>
#include <string> // string is a part of the std:: library
#include <math.h>

// functions
void numberParser(auto &returnValue ,std::string instruction, int minVal, int maxVal){
  // get input values
  std::cout<<"please insert " << instruction << ":"<< std::endl;
  std::cin >> returnValue;

  // validity check
  if (returnValue<minVal || returnValue >maxVal){
      std::cerr << "You entered a value that is not valid for " << instruction << ". Please enter a value between " << minVal << " and " << maxVal << "." << std::endl;
      std::cerr << "Press strg+c to cancel." << std::endl;
      numberParser(returnValue, instruction, minVal, maxVal);
  }
  else if (minVal > maxVal){
      std::cerr << "Min value is greater than max value. Please check the input of the function of numberParser" << std::endl;
  }
  else {
      std::cout << "Entering " << instruction << " successful!" << std::endl;
  }
}

/*
// old code
double  *calculateSinus(double stepSize, int numberOfEvaluationpoints){

  double sinValues[numberOfEvaluationpoints];
  for (int i = 0; i < numberOfEvaluationpoints; i++){
    sinValues[i] = sin(i*stepSize*180/M_PI);
  }
  return sinValues;
}
*/

void calculateSin(double returnArray[], double stepSize, int numberOfEvaluationpoints){
  // calculate the sinus function at the evaluation points

  for (int i = 0; i < numberOfEvaluationpoints; i++){
    returnArray[i] = sin(i*stepSize); //sin(i*stepSize*180/M_PI); // M_PI is a constant of the library <math> and contains the number of pi (3.1415926)
  }
}

// main method
int main (){
  // declarations
  int hw;
  int evalPoints;
  double stepSize;
  double xStep;

  // get x range of the plot, the valid range is 0 to hw*pi. The user should choose a hw
  numberParser(hw, "the number of sinus half-waves", 0, 10);

  // get number of evaluationpoints, the evaluationpoints are aequidistant
  numberParser(evalPoints, "the number of evaluation points for the sinus", 2, 1000000);

  // declarations that depend on the user-input
  double functionValues[evalPoints];

  // initialisations
  stepSize = hw*M_PI/evalPoints;
  xStep = 0;
  // a bit of verbose
  std::cout << "Step-size for the sinus calculation: " << stepSize << std::endl;

  // calculation of the function at the evaluationpoints
  calculateSin(functionValues, stepSize, evalPoints);
  /*
  // debug purpose
  for ( int j = 0 ; j<evalPoints; j++){
      std::cout << "This is functionValues j = " << j << std::endl;
      std::cout << functionValues[j] << std::endl;
  }
  */
  /*
  //old code
  functionValues = calculateSinus(stepSize, evalPoints);
  std::cout << "this is functionValues : " << *(functionValues + 2) << std::endl; // debug purpose
  */

  //print out the result of the calculation

  for (int j = 0 ; j < evalPoints ; j++){ // print all function values to the error-channel
      xStep = xStep + stepSize;
      std::cerr << xStep << " " << functionValues[j] << std::endl; // same functionallity as std::cout, but on another channel. If the user wants to save or repress the output of error messages in the console, the std::cout standart output will still be printed on the screen
  }

}
