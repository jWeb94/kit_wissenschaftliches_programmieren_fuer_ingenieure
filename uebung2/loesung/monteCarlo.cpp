#include <iostream>
#include <cstdlib>

void stepParser(std::string& description, size_t& maxSteps){
  std::cout << "please insert " << description << std::endl;
  std::cin >> maxSteps;
  if (maxSteps < 0){
      std::cout << "invalid number for " << description << std::endl;
      exit(EXIT_FAILURE);
  }
}

void calculateArea(double& result, double& radius, size_t& N){
  // declaration of the necessary local variables -> live only until the end of this scope!
  int M = 0;
  double randX;   // must be an double, due to the result of the double division
  double randY;   // if you declare it as a integer, the double division is casted to an int!
  double x;
  double y;
  double statusCalculation = 0.0/double(N);

  std::cout << "calculating, please wait..." << std::endl;
  for (size_t i = 0; i < N; i++){
    // status bar of the calculation
    std::cout << "\r Processing " << statusCalculation*100 << "%";
    statusCalculation = double(i)/double(N);

    // get normalized random numbers
    randY = double(rand())/double(RAND_MAX);
    randX = double(rand())/double(RAND_MAX);
    /*
     * double() to avoid integer division
     * /RAND_MAX to normalize the random values to 1
     * rand() creates integer random values between 0 and RAND_MAX: RAND_MAX-value is library-dependent, but is guaranteed to be at least 32767 on any standard library implementation
     */

     /*  documentation of the rand() function of the stdlib package:
      *  v1 = rand() % 100;         // v1 in the range 0 to 99
      *  v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
      *  v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
      */

     // calculate the x and y coordinate out of the quader-area (x_1-x_0)*(y_1-y_0)
     x = randX*radius - radius;
     y = randY*radius - radius;

     // check if the random coordinates are within the circle that we want to calculate and if they are, increment M
    if(x*x+y*y<=radius*radius) {
      M++;
    }
  }

  // calculate the area by the monte carlo proportion
  result = double(M)/double(N)*(radius*radius);
  //result = double(M)/double(N)*double(4)*(radius*radius); // TODO: why *4?

  std::cout << "" << std::endl;
  std::cout << "the number of points within the circle is " << M << " based on " << N << " iterations." << std::endl;
}

int main(){
  // variable declaration and initialisation
  size_t N;
  double r = 5; // Einheitskreis
  double area;
  std::string stepsDesc = "the number of iterations for the monte carlo simuliátion";

  // parse the number of iterations
  stepParser(stepsDesc, N);
  std::cout << "calculating the area of the circle with radius " << r << " by the monte carlo algorithm with " << N << " iterations." << std::endl;

  // calculate with the monte carlo algorithm
  calculateArea(area, r, N);
  // print the calculation result on the screen
  std::cout << "the area of the circle with radius " << r << " is: " << area << std::endl;

  return 0;
}
