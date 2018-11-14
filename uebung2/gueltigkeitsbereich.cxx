#include<iostream>
using namespace std;

int a = 1, b = 2;

int main()  {  
    cout << "globales a= " << a << endl;  

    int a = 10;
  
    cout << "lokales a= " << a << endl;

    cout << "globales ::a= " << ::a << endl;


    {  // Ein neuer Block innerhalb des bestehenden beginnt.

       int b = 20;
       
       int c = 30;
       
       cout << "lokales b = " << b << endl;
       cout << "lokales c = " << c << endl;

       cout << "globales ::b = " << ::b << endl;
    }   // Ende innerer Block
     
    cout << "globales b wieder sichtbar: b = " << b << endl;

    // cout << "c = " << c << endl; // Fehler, siehe Text
} //  Ende des äußeren Blocks
