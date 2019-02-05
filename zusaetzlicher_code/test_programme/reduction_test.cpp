#include<iostream>
#include<omp.h>

using namespace std; 

int main(){
  int i = 10;

  #pragma omp parallel reduction(*:i)
  {
    // i wird mit 1 initialisiert in allen Threads
    i = i + 1; // i lokal hat den Wert 2
    // Bei 4 Threads erwarte ich 2*2*2*2 = 16
    // und dann mit dem urspruenglichen, sequentiellen i verrechnet: 16*10 = 160
  }
  cout << "this is i after the calculation: " << i << endl;
  return 0;
}
