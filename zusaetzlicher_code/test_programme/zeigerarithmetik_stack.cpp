#include<iostream>

using namespace std;

int main(){

  // create an Array with two Dimensions:
  //int mat[3][2];
  //int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int mat[6] = {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < 6; i++){
    cout << "this is the Adress mat + i: " << mat+i << " with value: " << *(mat+i) << endl;
  }
  // Das ist ein zusammenhaengendes Feld im Speicher!

  int mat_2d[2][3] = {{1, 2, 3}, {4, 5, 6}};

  cout << "adress: " << mat_2d+1 << " " << *(mat_2d+1) << " value: " << *(*(mat_2d+1)+0) << endl;

  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 3; j++){
        cout << "this is the adress of i = " << i << " and j = " << j << " : " << *(mat_2d+i)+j << " with the value: " << *(*(mat_2d+i)+j) << endl;
    }
  }

  /*
  for (int i = 0; i < 3; i++ ){
    for(int j = 0; j < 2; j++){
      cout << "this is the adress of mat i=" << i << " and j=" << j << " : " << endl;
      cout << *(mat[i][j]) << endl;
    }
  }
  */
  return 0;
}
