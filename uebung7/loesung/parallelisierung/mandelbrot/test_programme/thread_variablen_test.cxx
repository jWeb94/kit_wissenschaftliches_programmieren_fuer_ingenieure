#include<iostream>
#include<omp.h>


int main(){
  int i = 42;
  int l = 666;

  #pragma omp parallel
  {
    /*
    #pragma omp critical
    {
      std::cout << "this is the variable i in thread " << omp_get_thread_num() << " : " << i << std::endl;
    }
    */
    // das globale i wird stehts in die threads uebernommen
    int n = 5;
    #pragma omp critcial
    {
      std::cout << "this is l in thread " << omp_get_thread_num() << " before calculation: " << l << std::endl;
    }
    l += 10;
    #pragma omp critcial
    {
      std::cout << "this is l in thread " << omp_get_thread_num() << " after calculation: " << l << std::endl;
    }

    /*
    #pragma omp critical
    {
      std::cout << "this is n in thread" << omp_get_thread_num() << " before the loop : " << n <<std::endl;
    }
    */
    for (int k = 0; k < 3; k++){
      n++;
      /*
      #pragma omp critical
      {
        std::cout << "n in the for loop in thread " << omp_get_thread_num() << " in iteration i = " << i << " is: " << n << std::endl;
      } // n ist, sofern im loop selbst deklariert, fuer jeden thread individuell!
      */
    }
  }
  return 0;
}
