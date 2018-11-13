#include <iostream>

using namespace std;

/* Hier sollen zunächst nur die Argumente (siehe Aufgabenstellung) in den Deklarationen der Funktionen ergänzt werden.
   Die Implementierung der Funktionen erfolgt nach der main() Funktion.
 */

void fall_1( );  // Übergabe per Wert
void fall_2( ); // Übergabe per Referenz
void fall_3_1( ); // const Zeiger auf Objekt vom Type double
void fall_3_2( ); // const Zeiger auf const Objekt vom Type double
void fall_3_3( ); // zeiger auf Objekt om Typ double

int main(){
  
  double v;

  v=100;

  /* Hier sollen die Funtionen fall_1, fal_2, etc. aufgerufen werden. 
     Achten Sie darauf, ob der Wert der Variablen v selbst oder ihre Speicheradresse übergeben werden soll (siehe Aufgabe).
     Überprüfen Sie, wie die Variable v durch die aufgerufenen Funktionen verändert wird.
   */
  
  fall_1( );
  cout<<"fall 1: v: "<<v<<endl;
  fall_2( );
  cout<<"fall 2: v: "<<v<<endl;
  fall_3_1( );
  cout<<"fall 3_1: v: "<<v<<endl;
  fall_3_2( );
  cout<<"fall 3_2: v: "<<v<<endl;
  fall_3_3( );
  cout<<"fall 3_3: v: "<<v<<endl;
  
}


/* Hier sollen die Funktionen implementiert werden. 
   Verwenden Sie die richtigen Argumente. 
 */

void fall_1( )  // Übergabe per Wert
{
  value ++;
  cout<<"value (fall_1): "<<value<<endl;
}
void fall_2( ) // Übergabe per Referenz
{
  value ++;
  cout<<"value (fall_2): "<<value<<endl;
}
void fall_3_1( ) // const Zeiger auf Objekt vom Type double :: Adresse wird kopiert!
{
  cout<<"adresse: (fall_3_1): "<<ptr<<endl;
  (*ptr)++;
  cout<<"value (fall_3_1): "<<*ptr<<endl;
  
}
void fall_3_2( ) // const Zeiger auf const Objekt vom Type double :: Adresse wird kopiert!
{
  cout<<"adresse: (fall_3_2): "<<ptr<<endl;
  cout<<"value (fall_3_2): "<<*ptr<<endl;
  
}
void fall_3_3( ) // Zeiger auf Objekt om Typ double :: Adresse wird kopiert!
{
  cout<<"adresse: (fall_3_3): "<<ptr<<endl;
  (*ptr)++;
  cout<<"value (fall_3_3): "<<*ptr<<endl;

}

// 8tung: in den Fällen 3_1,3_2,3_3 ist der Wert des Zeiger eine Adresse, die per Kopie an die Unterroutine
// übergeben wird (eine Veränderung des Wertes in der Unterroutine -- sofern erlaubt -- wird nicht zurückgegeben)


