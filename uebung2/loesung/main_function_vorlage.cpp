#include <iostream>

using namespace std;

/* Hier sollen zunächst nur die Argumente (siehe Aufgabenstellung) in den Deklarationen der Funktionen ergänzt werden.
   Die Implementierung der Funktionen erfolgt nach der main() Funktion.
 */

void fall_1( double value );  // Übergabe per Wert
void fall_2( double & value ); // Übergabe per Referenz
void fall_3_1( double * const ptr); // const Zeiger auf Objekt vom Type double
void fall_3_2( const double * const ptr); // const Zeiger auf const Objekt vom Type double
  // von rechts nach links lesen, um den Typ zu erkennen!
  /* const double const funktioniert nicht, da const double oder double const beides ein Objekt vom Typ double als constante variable erstellt.
   * Wird jetzt aber const double const geschrieben, denkt der Compiler, dass sich beide const auf double beziehen. Deshalb erst Pointer und dann const
   */
void fall_3_3( double * ptr); // zeiger auf Objekt vom Typ double

int main(){

  double v;

  v=100;

  /* Hier sollen die Funtionen fall_1, fal_2, etc. aufgerufen werden.
     Achten Sie darauf, ob der Wert der Variablen v selbst oder ihre Speicheradresse übergeben werden soll (siehe Aufgabe).
     Überprüfen Sie, wie die Variable v durch die aufgerufenen Funktionen verändert wird.
   */

  fall_1( v );
  cout<<"fall 1: v: "<<v<<endl;
  fall_2( v );
  cout<<"fall 2: v: "<<v<<endl;
  fall_3_1( &v ); // v&, damit ich die Adresse uebergebe
  cout<<"fall 3_1: v: "<<v<<endl;
  fall_3_2( &v);
  cout<<"fall 3_2: v: "<<v<<endl;
  fall_3_3( &v );
  cout<<"fall 3_3: v: "<<v<<endl;

}


/* Hier sollen die Funktionen implementiert werden.
   Verwenden Sie die richtigen Argumente.
 */

void fall_1( double value )  // Übergabe per Wert
{
  value ++;
  cout<<"value (fall_1): "<<value<<endl;
}
void fall_2( double & value ) // Übergabe per Referenz
{
  value ++;
  cout<<"value (fall_2): "<<value<<endl;
}
void fall_3_1( double * const ptr ) // const Zeiger auf Objekt vom Type double :: Adresse wird kopiert!
{
  cout<<"adresse: (fall_3_1): "<<ptr<<endl;
  (*ptr)++;
  cout<<"value (fall_3_1): "<<*ptr<<endl;

}
void fall_3_2( const double * const ptr ) // const Zeiger auf const Objekt vom Type double :: Adresse wird kopiert!
{
  cout<<"adresse: (fall_3_2): "<<ptr<<endl;
  cout<<"value (fall_3_2): "<<*ptr<<endl;

}
void fall_3_3( double * ptr ) // Zeiger auf Objekt om Typ double :: Adresse wird kopiert!
{
  cout<<"adresse: (fall_3_3): "<<ptr<<endl;
  (*ptr)++;
  cout<<"value (fall_3_3): "<<*ptr<<endl;

}

// 8tung: in den Fällen 3_1,3_2,3_3 ist der Wert des Zeiger eine Adresse, die per Kopie an die Unterroutine
// übergeben wird (eine Veränderung des Wertes in der Unterroutine -- sofern erlaubt -- wird nicht zurückgegeben)
