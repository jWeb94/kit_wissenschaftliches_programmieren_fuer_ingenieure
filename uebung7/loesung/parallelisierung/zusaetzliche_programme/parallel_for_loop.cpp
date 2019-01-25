#include<iostream>
#include<omp.h>



int main(){
  const int n = 10;

  #pragma omp parallel
  {
    // Oeffne die Threads und initialisiere die private Variable in jedem Thread
    int priv_number = 0;

    #pragma omp for schedule(dynamic, 4) // KEIN (!) parallel-Statement, da wir schon im parallelen Teil sind!
      for (int i = 0; i < n; i++){
        printf("Iteration %d is processed by thread %d \n", i , omp_get_thread_num());
      }

  }

  std::cout << "the same code with one pragma statement" << std::endl;
  #pragma omp parallel for // Parallelisierung gilt nur fuer die nachfolgende for-Schleife!
  // printf("Test"); // Ich muss nach dem Aufruf von pragma parallel for eine For-Schleife eroeffnen, ansonsten maeckert der Compiler! Die Parallelitaet gilt nur fuer die nachfolgende For-Schleife!  
  for (int i = 0; i < n ; i++){
    printf("Iteration %d is processed by thread %d \n", i , omp_get_thread_num());
  }
  return 0;
}
