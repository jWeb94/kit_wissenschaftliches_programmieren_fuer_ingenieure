#ifndef MYPOLYMORPH_H
#define MYPOLYMORPH_H

// Declarations

class BaseClass {
public:
    //CTOR
    BaseClass();

    // DTOR (ist virtuell um auf der sicheren Seite zu sein)
    virtual ~BaseClass();


    // pure virtual function --> muss in allen
    // abgeleiteten Klassen implementiert werden!
    virtual void some_function() = 0;         // muss ueberladen werden, sonst laesst es sich nicht kompilieren

    // Es ist moeglich, die folgenden in den abgeleiteten
    // Klassen zu implementieren.
    // virtual function:
    virtual void another_function();      // Wenn ueberladen, dann wird die Methode der abgeleiteten Klasse verwendet. Wenn nicht ueberladen die der BaseClass
    void just_a_function();
};

// ------------------------------------------------

class Derived_A : public BaseClass {
public:
    Derived_A();

    ~Derived_A();

    // jetzt mit Implementierung!
    void some_function();
    // damit muss diese implementiert werden
    void another_function();
    //
    void just_a_function();       // Wird nur bei Aufruf mit Objekt der Klasse A aufgerufen. Bei Ansprechen ueber BaseClass wird die Methode der Baseclass aufgerufen
};

// ------------------------------------------------

class Derived_B : public BaseClass {
public:
    Derived_B();

    ~Derived_B();


    // jetzt mit Implementierung!
    void some_function();

};




#endif //MYPOLYMORPH_H
