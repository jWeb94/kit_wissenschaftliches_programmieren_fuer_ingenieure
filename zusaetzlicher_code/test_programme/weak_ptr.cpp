#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int nmax = 5;
  vector<shared_ptr<float>> vec;

  for (int i = 0; i < nmax; i++){ // Erstelle Vektor mit float Adressobjekten
    const float tmp = i*i*i;
    vec.push_back([](const float &value){return shared_ptr<float> {new float (value)};}(tmp)); // initialisierung der Vektorelemente mit Lambda-Funktion
  }

  cout << "print values of the vector: " << endl;
  for_each(vec.begin(), vec.end(), [](shared_ptr<float> gg){cout <<  *gg << endl;}); // printe alle Werte des Vektors

  weak_ptr<float> obj (vec[nmax/2]);    // Erstelle weak_ptr auf das mittlere Objekt des Vektors
  cout << "Anzahl der Nutzer vor lock: " << obj.use_count() << endl;

  // Teste schreiben mit weak_ptr:
  //*obj = 4;
  // Teste lesen mit weak_ptr:
  // cout << "this is the value of obj: " << *obj << endl;

  // TODO: Lesen und Schreiben durch Konvertierung in shared_ptr:
  shared_ptr<float> test_rw_ptr = shared_ptr<float>(obj);
  //shared_ptr<float> test_rw_ptr = obj.lock(); // syntaktisch einfachere Alternative
  cout << "this is test_rw_ptr to read/write the obj weak_ptr contents: " << test_rw_ptr << endl;


  shared_ptr<float> ptr = obj.lock();   // Wandle weak_ptr in shared ptr um - wrapper fuer das was in Zeile 29 steht!
  if (ptr){
    cout << "Anzahl der Nutzer: " << obj.use_count() << endl;
  }

  cout << "ptr: " << *ptr << endl;

  return 0;
}
