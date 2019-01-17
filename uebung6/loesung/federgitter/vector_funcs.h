/*
 * vector_funcs.h
 *
 *
 *
 */

// TODO: vector_funcs dient nur dem Verständnis, wie Klassen in C++ aufgebaut sind und was 'alles' möglich ist!

#ifndef VECTOR_FUNCS_H_
// Compilerdirektive, um Mehrfacheinbindungen zu vermeiden
#define VECTOR_FUNCS_H_
#include <cstddef>
#include <string>

class Vector { //Beginn der Vector Klasse

public:

    //Constructor
    Vector ( const std::size_t dim );

    //Copy-Constructor
    Vector( const Vector & c );

    //Destructor
    ~Vector ();

    //Return size of Vector
    const std::size_t size() const;

    //Ausgabe aller Einträge
    void print(const std::string title="", const int w=8) const; //const int w=8 default Wert für Abstand. Übergabe bei Aufruf optional
    	// title und w sind hier optinale Parameter, die, wenn nicht bei Methodenaufruf definiert, automatisch auf "", bzw 8 gesetzt werden!

    //Copy Operator
    Vector & operator= ( const Vector & c );
    		// & vor Operator heißt, dass dort eine Referenz auf ein Objekt zurück geliefert wird

    //Initialisierung mit Skalar
    Vector & operator=(const double value);

    //Index Operator Reading
    const double  operator() ( std::size_t n ) const;
    	// const double für constant-correctness!

    //Index Operator Writing
    double & operator() ( std::size_t n );


    //Vektor-Addition
    const Vector operator+ (const Vector & c2) const;
    //Vektor-Subtraktion
    const Vector operator- (const Vector & c2) const;
    //Skalarprodukt
    const double operator* (const Vector & c2) const;
    //Multiplikation mit Skalar
    const Vector operator* ( const double & lambda) const;

private:


    //Default Constructor: Hier PRIVATE um Ausführen des Default Constructor zu unterbinden
    Vector ();
    /*
     * entspricht
     * 	Vector() = delete;
     * ab C++11 ~> verbieten von Standartoperatoren.
     * Dann kann der Befehl auch in Public stehen
     */

    // Membervariablen
    double * dataPtr;  // pointer for data
    std::size_t      N;        	// number of entries in the vector
    							// Entspricht einer Integer-Variable

}; //Ende der Vector Kasse


#endif /* VECTOR_FUNCS_H_ */
