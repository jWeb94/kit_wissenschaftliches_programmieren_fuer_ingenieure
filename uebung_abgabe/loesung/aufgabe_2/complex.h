// Compiler-Direktive, um Mehrfacheinbindung zu verhindern
#ifndef MYCOMPLEXNUM_
#define MYCOMPLEXNUM_


class MyComplex{

public:

  // Konstruktoren
  MyComplex();                                      // Standartkonstruktor
  MyComplex(const double xVal, const double yVal);  // Konstruktor mit direkter Angabe a+ib
  MyComplex(const MyComplex & complexNumber);       // Kopierkonstruktor

  // Destruktoren
  ~MyComplex(); 									// man koennte auch den Default-Destruktor generisch vom Compiler erstellen lassen, da in dieser Klasse nur Standartdatentypen vorkommen und daher der Speicher nicht selbst verwaltet werden muss!

  // Operatoren
    // Rechenoperatoren
  MyComplex operator+(const MyComplex & additionComplex);             	// darf nicht konstant sein, da es in der main_.cpp (z1+z2)+2 aufgerufen wird! Also das enstandene Element noch veraendert wird (+2 genommen) -> const MyComplex operator+(const MyComplex & additionComplex); // geht nicht!
  const MyComplex operator+(const double additionConstant);
  const MyComplex operator-(const MyComplex & subtractionComplex);
  const MyComplex operator*(const MyComplex & multiplicationComplex);
  MyComplex operator*(const double multiplicationConstant);           	// darf ebenfalls nicht const sein, selber Grund wie +-Operator
  MyComplex & operator-();                                            	// unaeres Minus. Rueckgabe als Referenz, da das Objekt selbst veraendert wird! veraendert wird!
    // Zuweisungsoperatoren
  MyComplex & operator=(const MyComplex & assignmentComplex);  			// Entspricht Kopieroperator

  	  // zusaetzliche Rechenoperatoren fuer Aufgabe 2
  MyComplex operator^(const int a);

  // Methoden
  	  // Getter-Methoden
  const double norm() const;
  const double real() const;
  const double imag() const;
  	  // setter Methoden fuer definierte Schnittstelle ~ in A2 wichtig, um nicht immer eine neue komplexe Zahl zu deklarieren
  void setRe(double newRe);
  void setIm(double newIm);

  void printComponents(); // debug purpose
    //Setter-Methoden

private:

  // Membervaribalen
  double x;
  double y;
    // z = x+iy


};
#endif
