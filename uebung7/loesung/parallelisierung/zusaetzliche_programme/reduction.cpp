#include<iostream>
#include<omp.h>
#include<stdio.h>


int main(){
  const int n = 1000;
  int sum = 0;

  #pragma omp parallel for reduction(+:sum)
    // For-Loops sind besonders gut parallelisierbar, wenn für die Berechnung das Kommutativgesetz gilt!
    for(int i = 0; i < n; i++){
      sum = sum + i;  // Finde gesamtsumme ueber alle Threads
                      /* Openmp findet behind the scenes eine Möglichkeit, wie keine Racecondition (Rechenfehler durch Zugriff auf Daten
                       * durch mehrere Thread, die das Ergebnis beeinflussen.
                       */

    }
    printf("sum=%d (must be %d)\n", sum, ((n-1)*n/2));

    // Analoge Implementierung - das macht Openmp behind the scenes:

    std::cout << "this is the more detailed code: " << std::endl;
    // Hier beginnt der pragme omp parallel scope:
    sum = 0;
    #pragma omp parallel
    {
      int sum_th = 0;
      #pragma omp for
        for (int i = 0; i < n ; i++)
        {
            sum_th = sum_th +i;
        }
    }
    printf("sum=%d (must be %d)\n", sum, ((n-1)*n/2));

  return 0;
}
