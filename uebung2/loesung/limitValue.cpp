#include <iostream>
#include <stdlib.h>
#include <cmath>


// TODO: vary the datatype to analyse the behaviour of the calculation dependend on the datatype
typedef double datatypeTest;
// TODO: Was soll ich jetzt davon ablesen koennen?

bool testHeap = false;

datatypeTest inputParser(std::string description, int min=-1, int max=-1){
  // input argument parser with sanity check
  datatypeTest number; // return value
  std::cout << "please insert " << description << std::endl;
  std::cin >> number;

  // check if a valid number was inserted
  if (number <= 0){
    std::cout << "no negative values are valid!" << std::endl;
    exit(EXIT_FAILURE);
  }

  // check the validity of the number
  if ((max != -1) && (min != -1) && (number < min || number > max || max < min)){
    // if both interval borders are given
    std::cout << "invalid interval for one of the two borders " << description << std::endl;
    exit(EXIT_FAILURE);
  }
  else if (max == -1 && min != -1 && number < min){
    // just the minimum value is given
    std::cout << "invalid interval for min border" << description << std::endl;
    exit(EXIT_FAILURE);
  }
  else if (min == -1 && max != -1  && number > max){
    // just the maximum value is given
    std::cout << "invalid interval for max border " << description << std::endl;
    exit(EXIT_FAILURE);
  }
  else{
      return number; // to test a function with result datatype
  }
}

int intParser(std::string description, int min = -1 , int max = -1){
  int number;
  std::cout << "please insert " << description << std::endl;
  std::cin >> number;
  if (min != -1 && max != -1 && (number > max || number < min)){
    std::cout << "invalid input for " << description << std::endl;
    exit(EXIT_FAILURE);
  }
  else if (min != -1 && max == -1 && number < min ){
    std::cout << "input was less then the minimum value!" << std::endl;
    exit(EXIT_FAILURE);
  }
  else if (min == -1 && max != -1 && number > max){
    std::cout << "input was greater then the maximum value!" << std::endl;
    exit(EXIT_FAILURE);
  }
  else {
    return number;
  }
}

void writeToCerr(datatypeTest ** resultArrayPtr, size_t numIterations){

  if (testHeap){
    // create an object with the same name on the heap that already exists

    /*
    * Das resultArrayHeap wird hier durch den untergeordneten Block ueberschrieben
    * bis zum Ende des Blocks
    */

    datatypeTest **resultArrayHeap;
    resultArrayHeap = new datatypeTest *[4]; // not * [], because we dont want an pointer to an pointer
    resultArrayHeap[0] = new datatypeTest [4*2];

    for (size_t i = 1; i<4; i++ ){
      // link the pointers
      resultArrayHeap[i] = resultArrayHeap[0] + i * 2;
    }

    // should be an error array out of bound
    // std::cout << "test heap is : " << ::resultArrayHeap[5][3] << std::endl; // does not work -> resultArrayHeap is not global
    std::cout << "test heap is : " << resultArrayHeap[5][3] << std::endl;

  }

  for (size_t i = 0; i < numIterations; i++){
      std::cerr << resultArrayPtr[i][0] << " " << resultArrayPtr[i][1] << std::endl; // x-value y-value
  }
}

int main(){

  // variable declarations and initialisation
  std::string inputStringMin = "the minimum x value of the calculation: ";
  std::string inputStringMax = "the maximum x value of the calculation: ";
  std::string inputSteps = "the number of steps (min= 1000): ";
  datatypeTest minVal;
  datatypeTest maxVal;
  datatypeTest range;
  size_t steps;
  double stepSize;
  double tempXVal;

  /*
  * Allgemein finde ich die Loesung mit einer void funktion und dem Rückgabewert als Uebergabeparameter eleganter,da
  * ich dann die Variable nur einmal deklarieren muss!
  * Habe ich einen Rückgabetyp, muss ich im uebergeordneten Scope eine entsprechende Variable
  * deklarieren und die Rückgabe da rein schreiben!
  * Bei den Grunddatentypen ist es egal, ob ich zwei Objekte erstelle (eins im ueber- und eins im untergeordneten Scope)
  * Bei komplexen Objekten ist der Weg ueber eine Referenz als Uebergabeparameter mit wesentlich weniger Overhead belastet!
  */

  // get interval to calculate the function
  minVal = inputParser(inputStringMin);
  maxVal = inputParser(inputStringMax, minVal);
  steps = intParser(inputSteps, 1000);
  std::cout << "steps before casting is: " << steps << std::endl;
  steps = size_t(steps);
  std::cout << "steps after casting is: " << steps << std::endl;

  range = maxVal - minVal;
  stepSize = double(range)/double(steps); // calculate the step size with minimum 1000 points in the inserted interval
  // TODO: here you can vary the step size for the calculation

  // create a result array
  datatypeTest **resultArrayHeap;
  resultArrayHeap = new datatypeTest *[steps]; // not * [], because we dont want an pointer to an pointer
  resultArrayHeap[0] = new datatypeTest [steps*2];

  for (size_t i = 1; i<steps; i++ ){
    // link the pointers
    resultArrayHeap[i] = resultArrayHeap[0] + i * 2;
  }

  std::cout << "steps is : " << steps << std::endl;
  for (size_t i = 0; i < steps; i++){
    // calculate the x value
    tempXVal = double(minVal) + double(i)*stepSize; // x value for the i-th iteration, based on the min value of the interval

    resultArrayHeap[i][0] = tempXVal;                                   // x value in the first column
    resultArrayHeap[i][1] = (sqrt(16 + tempXVal) -double(4))/tempXVal;  // y value in the secound column

    /*
    // test break:
    if (i == 3){
      std::cout << "break was called" << std::endl;
      break; // ends the for loop!
    }
    */

    /*
    // debug
    std::cout << "the value of iteration " << i << " with the x value of " << tempXVal << " is for the formula (sqrt(double(16) + tempXVal) -double(4))/tempXVal: " << (sqrt(double(16) + tempXVal) -double(4))/tempXVal << std::endl;
    std::cout << "the value of iteration " << i << " with the x value of " << tempXVal << " is for the formula (sqrt(16 + tempXVal) -4)/tempXVal: " << (sqrt(16 + tempXVal) -4)/tempXVal << std::endl;
    // the results are the same! no integer calculations in the equation
    */
  }
  // test break & debug
  // std::cout << "finished for loop" << std::endl;

  // print to the error channel to get access to the data
  writeToCerr(resultArrayHeap, steps);

  delete [] resultArrayHeap[0]; // delete the value array
  delete [] resultArrayHeap;    // delete the pointer array
  std::cout << "the memory on the heap was unblocked" << std::endl;
  std::cout << "finished calculation" << std::endl;

}
