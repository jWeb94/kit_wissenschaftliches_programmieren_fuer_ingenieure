#include<iostream>
#include<vector>
#include<algorithm>

void print_vector(std::vector<int> vector_to_print){
  for(auto vec_element : vector_to_print){
    std::cout << vec_element << std::endl;
  }
}

int main(){
  std::vector<int> vec_to_sort {3, 5, 1, 4, 2};
  print_vector(vec_to_sort);

  std::sort(vec_to_sort.begin(), vec_to_sort.end(), [](int a, int b){
    // wenn true: a vor b
    // wenn false: b vor a 
    if(a == 1){
      return false;
    }
    if(b == 1){
      return true;
    };
    return a<b;
  });

  std::cout << "the vector was sorted to: " << std::endl;
  print_vector(vec_to_sort);

  return 0;
}
