#ifndef _MYCLASS  // include guard - wegen der one definition rule
#define _MYCLASS  // include guard hier nicht notwendig aber der vollstaendigkeit halber trotzem implementiert!

// Unabhaengig von der zugehoerigen cpp, da hier nur die Schnittstelle definiert wird. Header sind auch KEINE Translation Units, dienen also nur die Bekanntgabe von Komponenten in anderen (und der eigenen) Translation Unit!
class myClass{
  // Klassendefinition
public:
  //myClass() = default;        // Sagen Compiler, dass keine eigene Implementierung der vom Compiler implizit erstellten Funktion existieren darf. Bzw 'verwende die Standartimplementierung in jedem Fall' (wenn eine andere Implementierung vorliegt: Compilerfehler)
  //myClass();                    // Standartkonstruktor
  myClass(int in_1, int in_2);  // Ueberladener Konstruktor 1
  myClass(int input_val);       // Ueberladener Konstruktor 2
  //myClass(const myClass &);     // Kopierkonstruktor
  //myClass(const myClass &)=delete; // Verbiete Kopierkonstruktor - ich kann keine Objekte vom Typ der Klasse an meinen Konstruktor zur Initialisierung uebergeben!

  // Destruktor
  ~myClass();
  // Operatoren
  myClass & operator=(int x);
  myClass & operator=(const myClass & input_objekt); // Kopieroperator - wird normalerweise implizit erstellt. Ich moechte ihn aber selbst schreiben, also muss ich ihn hier auffuehren!

  void set_a(const int & val_a); // const, da ich den uebergebenen Wert nicht veraendern will. Dieser soll ja genau in die Membervariablen unveraendert geschrieben werden!
  void set_b(const int & val_b);
  int * get_a_ptr() ;              // nachgestelltes const: Objekt laesst sich spaeter nicht mehr veraendern!
  int get_a();
  int get_b() const;

private:
  int a;
  int b;
  myClass();
};

#endif // _MYCLASS
