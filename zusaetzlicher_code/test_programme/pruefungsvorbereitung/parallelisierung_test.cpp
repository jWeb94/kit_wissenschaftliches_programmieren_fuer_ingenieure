#include<iostream>
#include<omp.h>

using namespace std;

int main(){
  int i = 42;

  #pragma omp parallel reduction(+:i)//firstprivate(i)
  {
    // Mit firstprivate wird i mit dem uebergeordneten i initialisiert, ist aber eine private variable fuer jeden Thread. Hat also keine Auswirkung auf i im uebergeordneten Thread
    // Laesst man private-anweisung weg, wird i aus dem uebergeordneten Scope an die Threads als gemeinsame Variable jeweils weiter gegeben und kann somit auch im uebergeordneten Scope danach veraendert sein!
    #pragma omp critical
    {
      cout << "this is i=" << i << " in thread no: " << omp_get_thread_num() << endl;
    }
    i += 1;
  }

  cout << "this is i after the parallel region: " << i << endl;

}
