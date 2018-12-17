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

const MyComplex MyComplex::operator+(const MyComplex & additionComplex){
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
}

const MyComplex MyComplex::operator-(const MyComplex & subtractionComplex){
	MyComplex resultSubtractionCompl;
	resultSubtractionCompl.x = this->x - subtractionComplex.real();
	resultSubtractionCompl.y = this->y - subtractionComplex.imag();
	return resultSubtractionCompl;
};

const MyComplex MyComplex::operator-(const double subtractionConstant){
	MyComplex resultSubConst(*this); 		// nutze den Kopierkonstruktor -> ich muss this dereferenzieren, damit ich den Inhalt des Objekts, nicht die Adresse, bekomme
	resultSubConst.x = resultSubConst.x + subtractionConstant;
	return resultSubConst;
}

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

const MyComplex MyComplex::operator*(const double multiplicationConstant){
	MyComplex resultMultiplicationConst(*this); // Kopierkonstruktor, vgl weiter oben fuer Details
	resultMultiplicationConst.x = resultMultiplicationConst.x*multiplicationConstant;
	resultMultiplicationConst.y = resultMultiplicationConst.y*multiplicationConstant;
	return resultMultiplicationConst;
};

// TODO: 3*operator/(... ~ wie bei allen anderen auch!)
const MyComplex MyComplex::operator/(MyComplex & complexDivisionNum){
	// TODO: Schreibe das hier um in cmath
	MyComplex divisionResult;
	divisionResult.x = (this->x * complexDivisionNum.x + this->y * complexDivisionNum.y) / (complexDivisionNum.x * complexDivisionNum.x + complexDivisionNum.y * complexDivisionNum.y);
	divisionResult.y = (this->x * complexDivisionNum.x - this->x * complexDivisionNum.y) / (complexDivisionNum.x * complexDivisionNum.x + complexDivisionNum.y * complexDivisionNum.y);
	return divisionResult;
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

// zusaetzliche Operatoren fuer Aufgabe 2
MyComplex MyComplex::operator^(const int a){
  // Den kann ich nicht auf const setzen, da ich das Ergebnis noch weiter verrechnen will in meiner Main Methode!
  // Nur ganzzahlige Exponenten sind hier zulaessig! Fuer eine Fliesskommazahl muesste der Operator nochmal extra ueberladen werden!
	MyComplex resultPow(*this); // Kopierkonstruktor
	if (a > 0){
		// z^3 = z*z*z
		for (int i = 1; i < a; i++){
			resultPow = resultPow * *this; // So muss ich immer maximal 2 komplexe Zahlen miteinander multiplizieren!
		}

	}
	else if (a == 0){
		resultPow.x = 1;
		resultPow.y = 0;
	}
	else{
		// a < 0
		resultPow = resultPow / *this;
	}
	return resultPow; // return const Element -> ich kann es im Nachgang nicht veraendern, was hier raus kommt, nur wenn ich ein neues Objekt erzeuge! ~ Constant Correctness
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

void MyComplex::setRe(double newRe){
	this->x = newRe;
};

void MyComplex::setIm(double newIm){
	this->y = newIm;
};

void MyComplex::printComponents(){
	/**
	 * for debug purpose
	 */
	cout << "x: " << this->x << endl;
	cout << "y: " << this->y << endl;
};
