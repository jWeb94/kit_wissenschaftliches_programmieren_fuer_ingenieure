#include<iostream>
#include<list>
#include<typeinfo>


using namespace std;

int main(){
  list<int> li;
  int i = 0;
  for (int i = 0; i < 4; i++){
    li.push_back(i);
  }

  for (auto x : li){
    i++;
    cout << "this is the type of x in iteration i = " << i << " : " << typeid(x).name() << endl;

  } // Ich nehme an, das ist ein Iterator-Objekt?

  for(list<int>::iterator it=li.begin(); it != li.end();++it){
    cout << "this is the type of x in iteration i = " << i << " : " << typeid(it).name() << endl;
  }

  return 0;
}
