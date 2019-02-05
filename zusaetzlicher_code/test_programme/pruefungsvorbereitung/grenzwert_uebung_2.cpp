#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

typedef double myfloat;

myfloat function(myfloat const x)
{
  return (sqrt(16.+x)-4.)/x;
};

int main(){
  myfloat a, b;
  int n;

  cout << "Eingabe der Intervallgrenzen: " << endl;
  cin >> a;
  cout << endl;
  cin >> b;

  cout << "Stuetzstellen: " << endl;
  cin >> n;

  myfloat h = (b-a)/myfloat(n-1);

  for(size_t i = 0; i < n; i++){
    myfloat x = b-i*h;          // naehere mich von rechts dem Grenzwert numerisch an
    myfloat fx = function(x);
    if (fx>1){
      cout << "fx: " << fx << " ,x: " << x << " sqrt(16-x)-4:" << (sqrt(16.+x)-4.) << endl;
    }
    //cout << setprecision(15) << x << " " << fx << endl;
  }

  return 0;
}
