#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main(){
  double x;
  for(size_t i = 0; i < 10; i++){
    x = double(i)*0.15227364672;
    double temp_val1 = pow(x-1., 2);         //(x-1)^2
    double temp_val2 = pow(x, 2)-2.*x+1.;   //x^2 - 2*x + 1^2 (binomical formula)
    /*
    * Anmerkungen: (Richtig?)
    *   Die Formeln sind analytisch genau gleich, von daher ist das Ergbnis eigentlich auch gleich
    *   Da bei der ausgeschriebenen Formel an anderen Stellen gerundet wird (da Zahlen teilweise nicht mehr genau darstellbar sind) entsteht
    *   ein anderes Ergbnis trotz aequivalenter Rechnung!
    *
    *   Laesst sich die berechneten Zahlen exakt darstellen mit der floating point variable oder werden beide auf den gleichen Wert gerundet entsteht kein Fehler.
    *   Werden die Berchnungen auf andere Werte gerundet so entsteht ein Fehler!
    */

    cout << "comparing (x-1)^2="<< temp_val1 << " with x^2 - 2*x + 1^2 (binomical formula) = " << temp_val2 << endl;
    auto erg = (pow(x-1., 2) == (pow(x, 2)-2.*x+1.));
    if(erg){
      cout << i << " Wahr fuer " << x << endl;
    }
    cout << setprecision(16) << "(x-1)^2: " << erg << endl; // double ist bis 15 Stellen relative Genauigkeit genau!
  }
  return 0;
}
