#include<iostream>
#include<vector>

using namespace std;

void test_function(){
  cout << "hello World" << endl;
}

void test_function_2(int i){
  cout << "this is the given Integer" << i << endl;
}

void print_values(int value){
  cout << "value is: " << value << endl;
}

int squared(int value){
  return value*value;
}
int times_3(int value){
  return 3*value;
}


// Ueberlade for_each mit Uebergabefunktionen mit unterschiedlichen Rueckgabetypen
void for_each(vector<int> & input_vector, void(*input_function)(int)){
  cout << "for each with void was called" << endl;
  for (int value : input_vector){
    cout << "this is value of the for loop: " << value << endl;
    input_function(value);
  }
}

void for_each(vector<int> & input_vector, int(*input_function)(int)){
  // Ich kann auch nicht void-Funktionen uebergeben! Dazu muss ich aber den Rueckgabetyp kennen!
  cout << "for_each with int function was called" << endl;
  int temp_value;
  for (int value : input_vector){
    cout << "this is value of the for loop: " << value << endl;
    temp_value = input_function(value);
    cout << "this is the Result of i: " << temp_value << endl;
  }
}


int main(){
  // auto function = test_function(); // das geht nicht, da ich mit () sage, dass ich die Funktion aufrufe

  //auto function = test_function;    // So weise ich die Funktion (den Pointer auf die Funktion) zu einer Variable zu
  auto function = &test_function;     // aequivalente Darstellung -> ohne & wird das & implizit vom Compiler gemacht
  /*
  * Im Endeffekt speichere ich die Adresse der Funktion (Funktionen sind nichts anderes als eine CPU Anweisungskette)
  * in einer Variablen ab. Rufe ich diesen Pointer mit den entsprechenden Uebergabeparametern auf, so weiß der Compiler, dass er hier die
  * Funktion aufrufen muss. (Das würde beim konventonellen Aufruf ebenfalls passieren)
  * Effeiv setze ich einen Alias für eine Funkion.
  */
  function();                         // Hier rufe ich die Funktion auf

  // Was ist der deduzierte Datentyp?
  void(*name_der_zielvariable)() = test_function; // die letzte Klammer enthaelt die Uebergabeparameter
  name_der_zielvariable(); // rufe test_function auf!

  // Mit Uebergabeparametern:
  void(*fcn_ptr_2)(int) = test_function_2;
  test_function_2(42);
  test_function_2(666);

  // Tatsaechliche Anwendungsmoeglichkeiten:
  vector<int> values = {1, 2, 4, 5, 7, 5};

  for_each(values, print_values);
  for_each(values, times_3);
  for_each(values, squared);
  /*
   * Funktionspointer ermoeglichen es mir, eine Grundfunktionalitaet mit selbst programmierbaren anderen Funktionalitaeten
   * zu erweitern.   
   */


  return 0;
}
