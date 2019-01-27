#include<iostream>


int main(){
  const int a_c = 5;
  const int b_c = 2;
  int c = 3;

  //constexpr double res_c = a_c^b_c;
  constexpr double res_c = a_c^c;

  std::cout << "this is the res_c as a constexpr: " << res_c << std::endl;

  return 0;
}
