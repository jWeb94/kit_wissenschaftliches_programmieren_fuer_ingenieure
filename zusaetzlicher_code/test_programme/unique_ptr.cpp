#include<iostream>
#include<vector>
#include<memory>

using namespace std;

unique_ptr<float> give_back_new_float(const float & value){
  return unique_ptr<float> {new float(value)}; // Erstellt neuen unique_ptr, der auf ein Objekt im Heap zeigt, dass mit dem Wert value initialisiert wurde!
}

/*

int main(){

  //unique_ptr erstellen, Werte zuweisen und Compilerfehler durch mehrere Pointer auf ein Objekt provozieren

  int nmax = 5;
  vector<unique_ptr<float>> vec;        // Vektor aus Adressen vom Typ unique_ptr

  for (int i = 0; i < nmax; i++){
    const float tmp = i*i*i;              // Initialisierungsvariable
    vec.push_back(give_back_new_float(tmp));  // Fuege neuen unique_ptr in Vektor ein
  }

  // Test Zugriff:
  *vec[2] = 42;

  //unique_ptr<float> test_float_ptr = vec[2]; // Compilerfehler! Da das Objekt auf den der unique_ptr zeigt immer nur einen Pointer auf sich gerichtet haben darf!

  for (int i = 0; i < nmax; i++){
    cout << "i: " << i << " : " << *vec[i] << " ";
  }
  cout << endl;

  vec.clear();

  return 0;
}
*/

int main(){

  // fuege normalen Pointer zu Vektor aus unique_ptr hinzu hinzu -> typen convertierung notwendig mittels casting und bewegen eines unique_ptr in einen anderen mit std::move

  int nmax = 5;
  vector<unique_ptr<float>> vec;        // Adressarray
  unique_ptr<float> obj {new float};    // Leerer unique_ptr

  for (int i = 0; i < nmax; i++){       // Initialisiere float Variablen auf dem Heap und speichere Adressen in den vec-Adressvektor
    const float tmp = i*i*i;
    vec.push_back(give_back_new_float(tmp));
  }

  //const float *p = new float{1001010};           // Wert ist so nicht veraenderlich

  float *p;                             // 'normaler' float-Pointer
  p = new float;                        // Schreibe eine Adresse auf dem Heap in die Adresse
  *p = 1001010;                         // Initialisiere den Wert hinter der Variable mittels Dereferenzoperator


  for(int i = 0; i < vec.size(); i++){  // Print vec
    cout << "i: " << i << " : " << *vec[i] << " ";
  }
  cout << endl;

  cout << "p: " << p << " ;with value: " << *p << endl;           // Print p

  vec.push_back(unique_ptr<float>(p));    // Caste den 'normalen' pointer in einen unique_ptr, um ihn in den Vektor anzufuegen! (Die Datentypen der Vektorelemente muessen mit den Datentypen der einzufuegenden Werte uebereinstimmen, ansonsten maeckert der Compiler!)

  for (int i = 0; i < vec.size(); ++i){   // print Werte aus vec und schreibe neue rein! -> unique_ptr kann den Wert hinter dem Pointer veraendern!
    cout << "i: " << i << " : " << *vec[i] << " ";
    *vec[i] = float(i*i*i*i);
  }
  cout << endl;

  *obj = -42;                             // Initialisiere Wert des obj-unique_ptr

  vec.push_back(move(obj));               // mit std::move(<objekt>) laesst sich der unique_ptr in den Vektor uebertragen! (und das ohne dass eine Zwischenkopie angefertigt werden muss! Das ist seit C++ 11 so)
  for (int i = 0; i < vec.size(); ++i){   // Print den vollstaendig zusammengefuegten Vektor
    cout << "i : " << i << " with value " << *vec[i] << " " ;
  }
  cout << endl;

  return 0;
}
