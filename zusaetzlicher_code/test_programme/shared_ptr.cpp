#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<algorithm>

using namespace std;

shared_ptr<float> give_back_new_float(const float &value){
  // Erstelle neues Objekt auf dem Heap und liefere den Smartpointer zurueck
  return shared_ptr<float> {new float(value)}; // Initialisierung mit value
}

void print_field_usage_count(vector<shared_ptr<float>> &val, const string txt){
  cout << "usecount of the elements of " << txt << endl;
  for (int i = 0; i<val.size(); i++){
    cout << "element" << i << ": " << val[i].use_count() << endl;
  }
}

/*

int main(){
  const int nmax = 4;
  // ADRESSvektoren!
  vector<shared_ptr<float>> vec1;
  vector<shared_ptr<float>> vec2;

  for (int i=0; i<nmax; i++){
    const float tmp = i*i*i;
    shared_ptr<float> ptr {give_back_new_float(tmp)};       // 1. use durch pointervariable ptr
    vec1.push_back(ptr);                                    // 2. use durch pointervariable vec1
    cout << "use count: " << vec1[i].use_count() << endl;   // Jedes Vektorelement enthaelt einen shared_ptr!
  }

  // Nach der for-Schleife geht der ptr-Pointer out of scope und  nachfolgend ist der usecount fuer die Elemente in vec1 wieder 1. (der ptr-Zeiger wird geloescht!)
  cout << "print values behind vec1: " << endl;
  for (int i=0; i<nmax; i++){
    cout << "i: " << i << " : " << *vec1[i] << " " << endl; // In give_back_new_float wird mit value initialisiert
  }

  print_field_usage_count(vec1, "vec1: ");  // usecount 1
  vec2 = vec1;                              // kopiere Pointer-Vektor vec1 - 2. use fuer die in vec1 abgespeicherten Adressen!
  print_field_usage_count(vec1, "1:vec1: ");
  print_field_usage_count(vec2, "1:vec2: ");
  //
  vec1.erase(vec1.begin()+1);                 // loesche Element aus Vektor!
  print_field_usage_count(vec1, "2:vec1: ");  // Alle Elemente in vec1 (das sind nach dem erase nur noch 3 Elemente) haben den usecount 2 durch vec1 und vec2
  print_field_usage_count(vec2, "2:vec2: ");  // In vec2 hat das 2. Element den usecount 1, da das korresponierende Element in vec1 geloescht wurde!
  //
  vec1.clear();                               // Loesche alle Elemente aus vec1
  print_field_usage_count(vec2, "vec2: ");    // Pointer stehen nur noch in vec2, also usecount 1


  return 0;
}
*/

// Lambdafunktion zur Initialisierung!
int main(){
  const int nmax = 4;
  // ADRESSvektoren!
  vector<shared_ptr<float>> vec1;
  vector<shared_ptr<float>> vec2;

  for (int i=0; i<nmax; i++){
    const float tmp = i*i*i;
    shared_ptr<float> ptr([](const float &val)->shared_ptr<float>{return shared_ptr<float> {new float(val)};}(tmp));       // 1. use durch pointervariable ptr
    vec1.push_back(ptr);                                    // 2. use durch pointervariable vec1
    cout << "use count: " << vec1[i].use_count() << endl;   // Jedes Vektorelement enthaelt einen shared_ptr!
  }

  // Nach der for-Schleife geht der ptr-Pointer out of scope und  nachfolgend ist der usecount fuer die Elemente in vec1 wieder 1. (der ptr-Zeiger wird geloescht!)
  cout << "print values behind vec1: " << endl;
  for (int i=0; i<nmax; i++){
    cout << "i: " << i << " : " << *vec1[i] << " " << endl; // In give_back_new_float wird mit value initialisiert
  }

  // Testzugriff:
  *vec1[2] = 42;
  //*(vec1 + 2) = 42; // vgl Zeigerarithmetik - das geht aber nur bei zusammenhaengenden Arrays! Hier sind einzelne Adressen 'zufaellig' in einem Vektor abgespeichert

  //float * test_float_ptr = vec1[2]; // Das geht nicht, da wir immer im gleichen Datentyp, also shared_ptr, bleiben muessen!
  shared_ptr<float> test_float_ptr = vec1[2]; 


  for_each(vec1.begin(), vec1.end(), [](shared_ptr<float> vec){cout << vec << " , "; }); cout << endl;  // printe adressen
  for_each(vec1.begin(), vec1.end(), [](shared_ptr<float> vec){cout << *vec << " , "; }); cout << endl; // printe Werte hinter den Adressen

  print_field_usage_count(vec1, "vec1: ");  // usecount 1
  vec2 = vec1;                              // kopiere Pointer-Vektor vec1 - 2. use fuer die in vec1 abgespeicherten Adressen!
  print_field_usage_count(vec1, "1:vec1: ");
  print_field_usage_count(vec2, "1:vec2: ");
  //
  vec1.erase(vec1.begin()+1);                 // loesche Element aus Vektor!
  print_field_usage_count(vec1, "2:vec1: ");  // Alle Elemente in vec1 (das sind nach dem erase nur noch 3 Elemente) haben den usecount 2 durch vec1 und vec2
  print_field_usage_count(vec2, "2:vec2: ");  // In vec2 hat das 2. Element den usecount 1, da das korresponierende Element in vec1 geloescht wurde!
  //
  vec1.clear();                               // Loesche alle Elemente aus vec1
  print_field_usage_count(vec2, "vec2: ");    // Pointer stehen nur noch in vec2, also usecount 1

  vec2.clear();                               // Nachdem kein Zeiger mehr auf die float-Objekte auf dem Heap zeigt, wird das Float-Objekt automatisch geloescht!
                                              // So kann kein Memory Leak entstehen!

  return 0;
}
