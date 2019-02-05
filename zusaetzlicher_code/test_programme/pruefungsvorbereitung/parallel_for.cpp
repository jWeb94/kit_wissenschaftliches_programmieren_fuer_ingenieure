#include<iostream>
#include<omp.h>

using namespace std;

int main(){
  int result = 0;

  #pragma omp parallel for
  for(int i = 0; i < 10; i++){
    #pragma omp critical
    {
      cout << "this is i=" << i << " in thread " << omp_get_thread_num() << endl;
    }
  }


  return 0;
}
