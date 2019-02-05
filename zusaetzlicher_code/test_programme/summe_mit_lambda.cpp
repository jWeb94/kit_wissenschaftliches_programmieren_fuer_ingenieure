#include<iostream>
#include<list>
#include <typeinfo>
#include<string>

using namespace std;

template<class Inhalt, typename T, typename Funktion>
T berechne_funktion( Inhalt & ll,T startwert, Funktion f){
  T ergebnis = startwert;
  for(auto val:ll) ergebnis = f(ergebnis,val);
  return ergebnis;
}

template<typename T>
T test_init(T in){
  return in;
}

int main(){
  int result {-1};
  int insert_var;

  list<int> li;

  try{
    cout << "please insert the list elements of the type in with the max value of 20: " << endl;
    for (int i = 0; i < 4; i++){
      cout << "i: " << i << endl; // debug
      cin >> insert_var;
      if (insert_var > 20){
        throw string("wrong input! Please try again."); // Nach einem Throw springt er direkt aus dem try block!
      }
      li.push_back(insert_var);
    }
  }
  catch (string & message)
  {
    cout << message << endl;
  }

  int start_value = 0;

  result = berechne_funktion(li, start_value, [](auto summe,auto wert){return summe+wert;}); // Durch den Aufruf deduziert der Compiler, wie er das Template umschreiben muss!
  //auto result2 = berechne_funktion<list<int>, int, ???>(li, start_value, lambda_function_ptr);
  cout << "this is the result: " << result << endl;
  cout << "this is the result2: " << result2 << endl;

  // teste Template
  auto test = test_init<float>(5);      // Explizit angeben, was der Compiler aus dem Template machen soll
  auto test2 = test_init(4.2);          // Compiler deduziert das Template selbst!
  cout << "this is test: "<< test << " with the type: " << typeid(test).name() << endl;
  cout << "this is test2: " << test2 << " with the type " << typeid(test2).name() << endl;

  return 0;
}
