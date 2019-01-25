#include<iostream>
#include<omp.h>

int add_number(int input_val, int num_to_add){
  return input_val+num_to_add;
}

int main(){
  int i = 0;
  std::cout << "this is i: " << i << std::endl;

  for (int j = 0; j < 4; j++){
    i += (i+5)^2;
    //i+=1;
    //add_number(i, 5); // Zuweisungsoperator ist ebenfalls nicht valide fuer atomic operations
  }
  std::cout << "this is i after the non parallel computation: " << i << std::endl;

  // Paralleler Code
  std::cout << "resetting i" << std::endl;
  i = 0;
  std::cout << "this is i: " << i << std::endl;
  std::cout << "number of available threads: " << omp_get_max_threads()  << std::endl;


  #pragma omp parallel
  {
    #pragma omp atomic
        i += (i+5)^2;
        #pragma omp critical
        {
          std::cout << "this is i after the atomic expression: " << i << " in thread number " << omp_get_thread_num() << std::endl;
        }
        //i += 1; // Atomic gilt nur fuer die nachfolgende Zeile! Die zweite Zeile wird wieder beliebig ausgefuehrt!
        // add_number(i, 5); // Zuweisungsoperator ist ebenfalls nicht valide fuer atomic operations

    #pragma omp critical
    {
      std::cout << "this is i=" << i << " in thread number " << omp_get_thread_num() << std::endl;
    }
  }
  std::cout << "this is i at the end: " << i << std::endl;



  return 0;
}
