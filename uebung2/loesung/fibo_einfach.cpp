# include <iostream>

int fibo(int n){
  if (n == 0){
    return 1;
  }
  else if (n == 1){
    return 1;
  }
  else{
    return fibo(n-1) + fibo(n-2);
  }

}

int main(){
  for (size_t i = 0; i < 100; i++){
    std::cout << fibo(i)<< std::endl;
  }

}
