#include<iostream>

#include "complex.h"

using namespace std; // kein std:: verwenden, um auf Methoden der std-library zugreifen zu koennen

/*
 * Construktoren
 */
MyComplex::MyComplex(){
  // Standartkonstruktor
};

MyComplex::MyComplex(const double xVal, const double yVal){
  this->x = xVal;
  this->y = yVal;
};

MyComplex::MyComplex(const MyComplex & complexNumber){
  this->x = complexNumber.x;
  this->y = complexNumber.y;
};

/*
 * Destruktoren
 */

MyComplex::~MyComplex(){
  // Leerer Destruktor!
};


/*
 * Operatoren
 */

MyComplex MyComplex::operator+(const MyComplex & additionComplex){

};

const MyComplex MyComplex::operator+(const double additionConstant){

};

const MyComplex MyComplex::operator-(const MyComplex & subtractionComplex){

};

const MyComplex MyComplex::operator*(const MyComplex & multiplicationComplex){

};

MyComplex MyComplex::operator*(const double multiplicationConstant){

};

MyComplex & MyComplex::operator=(const MyComplex & assignmentComplex){

};


MyComplex & MyComplex::operator-(){

};


/*
 * Methoden
 */

const double MyComplex::norm() const{
  double resultNorm = -1;
  // TODO: here comes some cool code

  return resultNorm;
};

const double MyComplex::real() const{
  double resultRe = -1;
  // TODO: here comes some cool Code

  return resultRe;
};

const double MyComplex::imag() const{
  double resultImag = -1;
  // TODO: here comes some cool code

  return resultImag;
};
