#include<iostream>

using namespace std;

void print_test(int mat[][2], int nx, int ny){
  for (int i = 0; i < nx; i++){
    for (int j = 0; j < ny; j++){
            cout << "print val i=" << i+1 << ", j=" << j+1 << "is value: " << mat[i][j] << endl;
    }
  }
}

int main(){
  int in_mat[2][2] {{4, 5}, {7, 8}};
  print_test(in_mat, 2, 2);

  int a, b;
  cout << "please insert a: " << endl;
  cin >> a;
  cout << "please insert b: "  << endl;
  cin >> b;
  int cin_mat[a][2];
  print_test(cin_mat,a, 2);
  // Wir lernen: Man kann dynamische Arrays in einer Dimension auf dem Stack erstellen

  int g;
  cout << "please insert g for the dimension of vec_test" << endl;
  cin >> g;
  int vec_test[g];
  for(int i = 0; i<g; i++){
    cout << "this is vec_test for i=" << i << " is: " << vec_test[i] << endl; 
  }

  return 0;
}
