#include<iostream>
#include <typeinfo>

using namespace std;

//void print_first_element(int * array){
void print_first_element(int array[]){ // aequvalente Darstellung von [] und *
  std::cout << "this is the adress of the first element: " << array << " with the value: " << *array << std::endl;
}


int main(){

  const int nmax = 10;
  //double tab[nmax]; // Gehe 8 Byte weiter pro Speicheradresse
  int tab[nmax]; // Gehe 4 Byte weiter pro Speicheradresse

  for (size_t i = 0; i < nmax; i++){
    //tab[i] = i*i;     // Standartzugriff macht mit dem operator[i] nichts anderes, als:
    *(tab + i) = i*i;
  }

  cout << "this is the datatype of the array tab: " << typeid(tab).name() << " with the value: " << tab << endl;

  for (size_t i = 0; i < nmax; i++){
    cout << "Eintrag #" << i << ": Adresse=" << (tab+i) << " Wert: " << tab[i] << endl;
  }

  print_first_element(tab);

  return 0;
}
