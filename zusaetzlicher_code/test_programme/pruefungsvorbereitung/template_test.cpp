#include<iostream>
#include <typeinfo>

using namespace std;

typedef int myDatatype;

template<typename T>
auto addiere(T a, T b)->decltype(a + b)
{
  return a + b;
}
// auto ist ein Platzhalter fuer den nachgestellten Datentyp, der durch decltype deduziert wird!


int main(){
  myDatatype zahl_1 = 10;
  myDatatype zahl_2 = 30;

  auto result = addiere(zahl_1, zahl_2);

  cout << "this is the result of the template function: " << result << endl;
  cout << "with the datatype: " << typeid(result).name() << endl;

  return 0;
}
