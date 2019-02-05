#include<iostream>
#include<omp.h>

using namespace std;

int main(){

  int i = 10;
  int j = 20;

  #pragma omp parallel shared(j)
  {
    j += 1;
    i += 1;
    #pragma omp critical
    {
      cout << "this is j: " << j << " in thread " << omp_get_thread_num() << endl;
    }
    #pragma omp critical
    {
      cout << "this is i: " << i << " in thread " << omp_get_thread_num() << endl;
    }
  }

  cout << "this is j after the parallel section: " << j << endl;
  cout << "this is i after the parallel section: " << i << endl; 

  return 0;
}
