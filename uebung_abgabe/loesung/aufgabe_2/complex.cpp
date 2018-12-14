#include<iostream>
#include<cmath>

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
	// Addition/Subtraktion erfolgt komponentenweise -> z_1+z_2 = (Re(z_1)+Re(z_2))+i(Im(z_1)+Im(z_2))
	MyComplex resultAdditionCompl;
	resultAdditionCompl.x = this->x + additionComplex.real();
	resultAdditionCompl.y = this->y + additionComplex.imag();
	/*
	 * Anmerkung:
	 *
	 * da ich hier innerhalb der Klassenimplementierung bin, kann ich auf die privaten Membervariablen an dieser Stelle mit dem Zugriffsoperator zugreifen.
	 * Außerhalb der Klassendefinition ist das nicht moeglich!
	 */
	return resultAdditionCompl;
};

const MyComplex MyComplex::operator+(const double additionConstant){
	MyComplex resultAddConst(*this); 		// nutze den Kopierkonstruktor -> ich muss this dereferenzieren, damit ich den Inhalt des Objekts, nicht die Adresse, bekomme
	resultAddConst.x = resultAddConst.x + additionConstant;
	return resultAddConst;
};

const MyComplex MyComplex::operator-(const MyComplex & subtractionComplex){
	MyComplex resultSubtractionCompl;
	resultSubtractionCompl.x = this->x - subtractionComplex.real();
	resultSubtractionCompl.y = this->y - subtractionComplex.imag();
	return resultSubtractionCompl;
};

const MyComplex MyComplex::operator*(const MyComplex & multiplicationComplex){
	/*
	 * (a1+ib1)*(a2+ib2) 	= 	a1*a2+a1*ib2+ib1*a2+i^2*b1*b2
	 * 						=	(a1*a2-b1*b2)+i*(a1*b2+a2*b1)
	 */
	MyComplex resultMultiplCompl;
	resultMultiplCompl.x = this->x*multiplicationComplex.real()-this->y*multiplicationComplex.imag();
	resultMultiplCompl.y = this->x*multiplicationComplex.imag()+multiplicationComplex.real()*this->y;
	return resultMultiplCompl;
};

MyComplex MyComplex::operator*(const double multiplicationConstant){
	MyComplex resultMultiplicationConst(*this); // Kopierkonstruktor, vgl weiter oben fuer Details
	resultMultiplicationConst.x = resultMultiplicationConst.x*multiplicationConstant;
	resultMultiplicationConst.y = resultMultiplicationConst.y*multiplicationConstant;
	return resultMultiplicationConst;
};

MyComplex & MyComplex::operator=(const MyComplex & assignmentComplex){
	this->x = assignmentComplex.real();
	this->y = assignmentComplex.imag();
	return *this;
};


MyComplex & MyComplex::operator-(){
	// TODO: Checke, ob das so richtig funktioniert!
	this->x = -this->x;
	this->y = -this->y;
	return *this;
};


/*
 * Methoden
 */

const double MyComplex::norm() const{
	// |z|=sqrt(x^2+y^2)
	return sqrt(pow(this->x, 2.)+pow(this->y, 2.));
};

const double MyComplex::real() const{
  // Realanteil von z=x+iy ist x
  return this->x;
};

const double MyComplex::imag() const{
  // Imaginäranteil von z=x+iy ist y
  return this->y;
};

void MyComplex::printComponents(){
	/**
	 * for debug purpose
	 */
	cout << "x: " << this->x << endl;
	cout << "y: " << this->y << endl;
};
