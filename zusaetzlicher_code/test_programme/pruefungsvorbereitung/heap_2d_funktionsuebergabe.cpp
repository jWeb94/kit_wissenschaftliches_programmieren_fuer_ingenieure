#include<iostream>

using namespace std;

typedef double datatype_array;

datatype_array ** create_2d_array(int nx, int ny){
  // int als Uebergabeparameter, da ich nur ganzzahlige Dimensionen eines Arrays haben kann!
  datatype_array ** new_array;
  new_array = new datatype_array * [nx];
  new_array[0] = new datatype_array [nx*ny];

  for (size_t i = 1; i < nx; i++){
    new_array[i] = new_array[0] + i*ny;
  }
  return new_array;
}

template<typename T>
void delete_array(T ** array){
//void delete_array(T array){ // Deduziert er die ** selbst?
  delete [] array[0];
  delete [] array;
}


int main(){
  size_t rows, cols;
  cout << "please insert rows: " << endl;
  cin >> rows;
  cout << "please insert cols: " << endl;
  cin >> cols;

  datatype_array ** arr_2d;
  arr_2d = create_2d_array(rows, cols);

  arr_2d[1][1] = 42;

  cout << "this is the adress of the value i, j = 1, 1: " << *(arr_2d + 1)+1 << " and this is the value behind it: " << *(*(arr_2d + 1) + 1) << endl;
  cout << "and this is the adress of the adress of the beginning of the row of this value: " << arr_2d + 1 << endl;

  delete_array(arr_2d); // free the memory

  return 0;
}
