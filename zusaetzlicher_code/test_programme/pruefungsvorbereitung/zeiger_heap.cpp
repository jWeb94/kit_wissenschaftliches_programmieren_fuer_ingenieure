#include<iostream>

using namespace std;

int main (){
  size_t nx, ny;



  cout << "please insert the dimensions of the array nx x ny:" << endl;
  cin >> nx;
  cout << endl;
  cin >> ny;

  // Feld 1D:
  int * i_ptr_array;
  i_ptr_array = new int[nx];
  for (int i = 0; i < nx; i++){
    i_ptr_array[i] = i + 1;
    cout << "i = " << i << " : " << i_ptr_array[i] << endl;
  }
  i_ptr_array[nx-1] = 10; // nx-1 ist das letzte Element des Arrays, dass mit nx initialisiert wurde!
  for (int i = 0; i < nx; i++){
    cout << "i = " << i << " : " << i_ptr_array[i] << endl;
  }
  cout << i_ptr_array[nx] << endl; // Zeigt ins Nirvana

  delete i_ptr_array;



  int ** feld2d; // Zeiger auf einen Zeiger

  feld2d = new int * [nx]; // Speichere Zeiger-Array in dem Zeiger auf einen Zeiger


  // Zusammenhaengender Speicher auf dem Heap
  feld2d[0] = new int [nx*ny]; // Erstelle fuer den Zeiger des 0ten Elements des Zeigerarrays ein neues Integer Array auf dem Heap
  for(size_t i = 1; i < nx; i++){
    feld2d[i] = feld2d[0] + i*ny;     // Verlinke die Zeiger des Zeigerarrays auf die jeweiligen Elemente des Arrays
  }
  // Zugriff:
  feld2d[1][2] = 10;              // Greife auf die 1te Adresse (angefangen bei 0) des Zeigerarrays zu und addiere darauf 2 integer Adressen weiter
  cout << "this is feld2d[1][2]: " << feld2d[1][2] << endl;
  cout << "alternativer Zugriff - Adresse: " << (feld2d[1]+2) << " ;Wert: " << *(feld2d[1]+2) << endl;

  // Zugriff auf Element ausserhalb des Arrays:
  cout << feld2d[nx-1][ny+1] << endl; // Das geht, fuehrt nur zum falschen Wert, da auf ein Array-Element aus der naechsten "Zeile" zugegriffen wird!

  // Speicher frei geben:
  delete [] feld2d[0];     // Loesche Integer Array
  delete [] feld2d;     // Loesche Zeigerarray


  // Zeilenweise zusammenhaengender Speicher:
  int ** feld2d_2;
  feld2d_2 = new int * [nx];
  for(size_t i = 0; i < nx; i++){
    feld2d_2[i] = new int [ny]; // Erstelle fuer jede Adresse des Zeiger-Arrays ein neues Array
  }
  cout << "this is feld2d_2[1][2] - adress: " << *(feld2d_2+1)+2 << " with the value: " << *(*(feld2d_2+1)+2) << endl;

  cout << "adresse des Zeiger-Arrays feld2d_2[1]: " << feld2d_2+1 << endl;
  cout << "adresse des integerarrays, auf das feld2d_2[1] zeigt: " << *(feld2d_2+1) << endl;
  cout << "wert, der hinter dem Element des Integerarrays liegt: " << **(feld2d_2+1) << endl;

  feld2d_2[1][0] = 42;

  // Zugriff auf Element ausserhalb des Arrays:
  cout << feld2d[nx-1][ny+1] << endl; // Der zeigt irgendwo hin!

  for( size_t i = 0; i < nx; i++){
    delete [] feld2d_2[i];          // Loesche hinter dem Zeiger-Array stehende Integer Arrays
  }

  delete [] feld2d_2;               // Loesche Zeiger Array

  cout << "this is the value feld2d_2[1][0] after deleting the content of the pointer: " << feld2d_2[1][0] << endl; // Dangeling Pointer -> Zeigt ins Nirvana!


  return 0;
}
