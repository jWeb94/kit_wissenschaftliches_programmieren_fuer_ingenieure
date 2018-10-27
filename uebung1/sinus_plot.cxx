#include <iostream>
#include <cmath>

using namespace std;

int main(){
  double hw;
  int nsteps;
  const double PI = 3.14159;

  cout<<"Plotten einer Sinuskurve  f(x) = sin(x)"<<endl;
  cout<<"----------------------------------------";
  cout<< "Anzahl der sinus Halbwellen (= Vielfaches von PI): ";
  cin >> hw;

  cout <<" Anzahl der Stuetzstellen: ";
  cin >> nsteps;

  /*FRAGE: Warum werden einige Variablen hier als const gesetzt? Einfach nur um deutlich zu machen, dass diese sich nicht verändern?!*/

  const double maxx = hw * PI;
  const double deltax = maxx/nsteps;

  cout<<" Der x-Bereich liegt jetzt zwischen 0 und " <<maxx<<endl
      << " Diskretisierung durch "<< nsteps<< " Stuetzstellen "
      <<endl<<endl
      << "  x    f(x) "<<endl;


  double x = 0.0;

  for ( int i = 0; i< nsteps; i++){
    const double f = sin(x);
    cerr << x<< "  " << f << endl;
    x = x + deltax;
  }

  return 0;
}
