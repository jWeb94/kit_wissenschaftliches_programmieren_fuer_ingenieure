#include<iostream>
#include<memory>

using namespace std;

int main(){

  int nx;
  cin >> nx;
  {
  shared_ptr<int> my_shared = make_shared<int>();
  shared_ptr<double> my_secound_shared = shared_ptr<double>{new double};
  shared_ptr<char> my_char_array = shared_ptr<char>{new char[nx]};
  cout << "this is the adress of the new shared ptr: " << my_shared << endl;
  cout << "this is the adress of the secound shared ptr: " << my_secound_shared << endl;
  *my_shared = 42;
  cout << "this is the value behind the shared_ptr: " << *my_shared << endl;

  // Nachdem kein Smartpointer mehr auf die erstellten Objekte zeigen, werden diese automatisch geloescht!

  cout  << "here comes the unique_ptr-section: " << endl;

  unique_ptr<int> my_unique = unique_ptr<int>{new int};
  *my_unique = 666; // the number of the beast
  weak_ptr<int> weak_ptr_to_shared = my_shared;
  // weak_ptr<int> weak_ptr_to_unique = my_unique; // Das geht nicht!
  cout << "this is my_shared adressed over the weak pointer: " << *(weak_ptr_to_shared.lock()) << endl; // Ich muss lock schreiben, da ich damit den weak- temporaer zu einem shared-pointer mache. Das ist notwendig, um mit dem weak-pointer etwas machen zu koennen!
  }
  return 0;
}
