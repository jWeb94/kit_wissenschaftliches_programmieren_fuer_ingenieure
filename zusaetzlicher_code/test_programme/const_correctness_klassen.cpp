#include<iostream>

using namespace std;

// Klasse:
class Entity
{
private:
  int m_x, m_y = 1;
  //mutable int m_x; // Dann koennte ich m_x in getX veraendern und printEntity wuerde nicht maeckern!

public:
  int m_z;
  int getX() const{
    //m_x = 2; // geht nicht fuer printEntity, da ich dann in der Funktion printEntity(e) das Objekt e veraendern wuerde, was ich mit dem const in printEntity(CONST...) verhindere! -> Syntax Error
    return m_x;
  }

};

void printEntity(const Entity & e){
  // m_z = 2; // geht nicht, da ich e veraendern wuerde, was ich ueber const verhindere
  cout << e.getX() << endl;
}

void print1(const int * integerPtr){
  int * tempPtr = new int(4); // Ich kann eine andere Adresse zuweisen!
  // *integerPtr = 29;   // ich kann aber keine neuen Zahlen zuweisen
  cout << *integerPtr << endl;
}

void print2(int * const integerPtr){
  // integerPtr = &m_y; // Ich kann keine andere Adresse zuweisen!
  *integerPtr = 29;   // ich kann aber neuen Zahlen zuweisen
  cout << *integerPtr << endl;
}

int main(){

  Entity testEntity;

  int * testPtr = new int(5);
  print1(testPtr);
  print2(testPtr);

  int m = 5, n = 3;

  if (m == n){
    cout << "case 1" << endl;
  }
  else if( m<n){
    cout << "case 2" << endl;
  }
  else{
    cout << "case 3" << endl;
  };
  cout << "end of the if statement" << endl;
  return 0;
}
