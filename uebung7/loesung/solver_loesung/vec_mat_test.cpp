/*
 * vec_mat_test.cpp
 *
 *
 *
 */

#include <iostream>
#include <cstdio>

#include "vector_funcs.h"
#include "matrix_funcs.h"


int main(){

  Matrix A(3,5);
  A = 5.;

  const Matrix B = A;
  
  Vector v1(5) ;
  
  v1(0) = 1;
  v1(1) = 2.;
  v1(2) = 3.;
  v1(3) = 4.;
  v1(4) = 5;
  //  v1(5) =-8.;
  
  
  v1.print();
  
  Vector v2 = B*v1;

  v2.print();
  
  cout << "Matrix A: " << endl;
  A.print();
  cout << "Matrix B: " << endl;
  B.print();

  A(2,2) = 3;
  cout << "Matrix A: " << endl;
  A.print();

  cout << "Matrix A(2,2): " << A(2,2) << endl;

  Vector v3=A*v1;
  v3.print();

  Matrix A0=A;
  cout<<A0.rows()<<","<<A0.cols()<<endl;
  Matrix bb(3,3);
  bb=-7;

  //A=bb;
  
  for(auto i=0;i<A.rows();i++)
    for(auto j=0;j<A.cols();j++)
      A(i,j)=i*10+j;

  A.print();
  cout<<"========"<<endl;
  A0=A;

  A0.print();
  v3=A*v1;
  v3.print();
  cout<<A0.rows()<<","<<A0.cols()<<endl;
  cout<<bb.rows()<<","<<bb.cols()<<endl;
  
  
}
