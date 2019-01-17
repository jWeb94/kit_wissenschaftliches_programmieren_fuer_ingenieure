/*
 * matrix_funcs.cpp
 *
 *
 *
 */

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <iomanip>

#include "matrix_funcs.h"

//Constructor TODO: Selber machen
Matrix::Matrix ( std::size_t const rows, const std::size_t cols ){
	/*
	 * Erklaerung findet sich in .../zusaetzlicher_code_zum_ausprobieren/test_2d_array.cpp
	 */

	// TODO: Achtung~es müssen immer alle Klassenvariablen, die irgendwo verwendet werden können mit dem Konstruktor beschrieben werden. Ansonsten funktioniert der Code während der Laufzeit nicht richrig!
	// 		 hier war bspw _rows und _cols nicht beschrieben und ich konnte die Dimensionen deshalb nicht abfragen und das Programm ist abgestürzt
	// 		 Allgemein sollte Eclipse nicht mäckern, damit der Code richtig funktioniert!
	this->_rows = rows;
	this->_cols = cols;

	this->dataPtr = new double*[rows];

	this->dataPtr[0] = new double[rows*cols];

	for (int i = 0; i < rows; i++){
		this->dataPtr[i] = this->dataPtr[0] + i*cols;
	}
}
//Copy Constructor TODO: Selber machen
Matrix::Matrix (const Matrix & m){
	/*
	 * Code aus Referenz aus vector_funcs.cppp
	 */
	this-> _rows = m._rows;
	this-> _cols = m._cols;

	// das dynamische Array muss auch hier initialisiert werden, da ein neues Objekt mit dem copy-KONSTRUKTOR erstellt wird!
	// bis hier hin weiß das Objekt nur, dass es als Attribut ein double** hat, aber nicht wo dieser hin zeigen soll!
	this->dataPtr = new double*[m._rows];
	this->dataPtr[0] = new double[m._rows*m._cols];

	for (int k = 0; k < m._rows; k++){
		this->dataPtr[k] = this->dataPtr[0] + k*m._cols;
	}

	// hier werden dann die Werte in das neu angelegte Objekt kopiert
	for (int i = 0; i < m._rows; i++){
		for (int j = 0; j < m._cols; j++){
			this->dataPtr[i][j] = m.dataPtr[i][j];
		}
	}
}

//Destructor TODO: Selber machen
Matrix::~Matrix ()
{
	/*
	 * gib den allozierten Speicher wieder frei!
	 */
	delete[] this-> dataPtr[0]; // loesche das Daten-Array im Speicher
	delete[] this-> dataPtr;	// loesche das Pointer-Array zum Daten-Array
}
//Copy Operator
Matrix & Matrix::operator= (const Matrix & m){
  // der Test auf Selbszuweisung kann auch entfallen: normalerweise kommt er nicht vor und wenn dann wird halt kopiert
  //if (this == &m ) return *this;  //!!!Untersuchung auf Gleichheit!!! Selbstzuweisung unnoetig: mache nichts
  
  // Loeschen/Neuanlegen nur nötig, wenn Format nicht passt
  // auch das ist Luxus....
  if(this->_rows != m._rows  ||  this->_cols != m._cols) {
    
    delete[] this->dataPtr[0];
    delete[] this->dataPtr;

    this->dataPtr    = new double*[this->_rows];
    this->dataPtr[0] = new double [this->_rows*this->_cols];
    for (auto i=1; i<this->_rows; i++)
      this->dataPtr[i] = this->dataPtr[0]+i*this->_cols;
  }
  
  for(std::size_t i=0; i<this->_rows; ++i)
    for(std::size_t j=0; j<this->_cols; ++j)
      this->dataPtr[i][j] = m.dataPtr[i][j];
  
  return *this;
}

Matrix & Matrix::operator= (const double val){

  for(auto  i=0; i<this->_rows; ++i)
    for(auto j=0; j<this->_cols; ++j)
      this->dataPtr[i][j] = val;

  return *this;

}

//Index Operator Reading
const double Matrix::operator() ( const std::size_t nx, const std::size_t ny ) const{

  assert(nx<this->_rows && ny<this->_cols); //this-> ist für Aufruf von Klassenvariablen nicht zwingend notwendig
  return this->dataPtr[nx][ny];
};

//Index Operator Writing
double & Matrix::operator() ( const std::size_t nx, const std::size_t ny ){

  assert(nx<this->_rows && ny<this->_cols); //this-> ist für Aufruf von Klassenvariablen nicht zwingend notwendig
  return this->dataPtr[nx][ny];

};

//Matrix-Vector Produkt
const Vector Matrix::operator* ( const Vector & b ) const{

  auto nmax = b.size();
  assert( this->_cols==nmax );

  Vector tmp( this->_rows ); // Ergebnisvektor erg(n) = A(n,m)*b(m)


  for (auto i=0; i<this->_rows; i++) {
    tmp(i)=0.;
    for (auto j=0; j<this->_cols; j++)
      tmp(i) += this->dataPtr[i][j]*b(j);
  }
  return tmp;

};

//Matrix Addition TODO: Selber machen
const Matrix Matrix::operator+ ( const Matrix & A) const{

	Matrix tempMatrix(A._rows, A._cols); // create

	for (int i = 0; i<A._rows; i++){
		for (int j = 0; j<A._cols; j++){
			tempMatrix.dataPtr[i][j] = this->dataPtr[i][j] + A.dataPtr[i][j];
		}
	}
	return tempMatrix;
};


const std::size_t Matrix::rows() const { return _rows; }
const std::size_t Matrix::cols() const { return _cols; }

//Ausgabe Matrix
void Matrix::print(const int w) const
{
  for(auto i=0; i<this->_rows; ++i)
    {
      for(auto j=0; j<this->_cols; ++j)
	cout << setw(w) << this->dataPtr[i][j] << "  ";
      cout << endl;
    }
}

