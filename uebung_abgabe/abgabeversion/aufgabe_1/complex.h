#ifndef MYCOMPLEXNUM_
#define MYCOMPLEXNUM_

class MyComplex{

public:

  // Konstruktoren
  MyComplex();                                      // Standartkonstruktor
  MyComplex(const double xVal, const double yVal);  // Konstruktor mit direkter Angabe a+ib
  MyComplex(const MyComplex & complexNumber);       // Kopierkonstruktor

  // Destruktoren
  ~MyComplex();

  // Operatoren
  const MyComplex operator+(const MyComplex & additionComplex) const;             	// darf nicht konstant sein, da es in der main_.cpp (z1+z2)+2 aufgerufen wird! Also das enstandene Element noch veraendert wird (+2 genommen) -> const MyComplex operator+(const MyComplex & additionComplex); // geht nicht!
  const MyComplex operator+(const double additionConstant) const;
  const MyComplex operator-(const MyComplex & subtractionComplex) const;
  const MyComplex operator-(const double subtractionConstant) const;
  const MyComplex operator*(const MyComplex & multiplicationComplex) const;
  const MyComplex operator*(const double multiplicationConstant) const;
  MyComplex & operator-();    // unaeres Minus
  	  // Fuer Aufgabe 2
  const MyComplex operator^(const int a);
  const MyComplex operator/(MyComplex & complexDivisionNum) const;
  MyComplex & operator=(const MyComplex & assignmentComplex);


  // Methoden
  	  // Getter-Methoden
  const double norm() const;
  const double real() const;
  const double imag() const;
  	  // setter Methoden fuer definierte Schnittstelle ~ in A2 wichtig, um nicht immer eine neue komplexe Zahl zu deklarieren
  void setRe(double newRe);
  void setIm(double newIm);

  void printComponents(); // zum debuggen

private:
  // Membervaribalen: z = x+iy
  double x;
  double y;
};
#endif
