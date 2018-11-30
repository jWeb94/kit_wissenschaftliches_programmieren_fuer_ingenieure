#include<iostream>
#include "addiere.h"

using namespace std;

int main(){

  int summe,a,b;

  cout<<"a und b eingeben:";
  //Lies die Zahlen a und be ein:
  cin >> a >>b;
  /* Berechne die Summe beider Zahlen */

  summe = addiere(a,b);

  //Zeige das Ergebnis auf dem Bildschirm an

  cout<<"Summe="<<summe<<endl;

  return 1;

}
