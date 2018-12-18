#ifndef MYCOMPLEXNUM_
#define MYCOMPLEXNUM_

class MyComplex{

public:

  // Konstruktoren
  MyComplex();
  MyComplex(const double xVal, const double yVal);
  MyComplex(const MyComplex & complexNumber);

  // Destruktoren
  ~MyComplex();

  // Operatoren
  const MyComplex operator+(const MyComplex & additionComplex) const;
  const MyComplex operator+(const double additionConstant) const;
  const MyComplex operator-(const MyComplex & subtractionComplex) const;
  const MyComplex operator-(const double subtractionConstant) const;
  const MyComplex operator*(const MyComplex & multiplicationComplex) const;
  const MyComplex operator*(const double multiplicationConstant) const;
  MyComplex & operator-();
  	  // Fuer Aufgabe 2
  const MyComplex operator^(const int a);
  const MyComplex operator/(MyComplex & complexDivisionNum) const;
  MyComplex & operator=(const MyComplex & assignmentComplex);


  // Methoden
  	  // Getter-Methoden
  const double norm() const;
  const double real() const;
  const double imag() const;
  	  // Setter-Methoden
  void setRe(double newRe);
  void setIm(double newIm);

  void printComponents(); // zum debuggen

private:
  // Membervaribalen: z = x+iy
  double x;
  double y;
};
#endif
