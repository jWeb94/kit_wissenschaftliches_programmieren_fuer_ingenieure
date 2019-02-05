#include<iostream>

using namespace std;

enum Atomart {Al, Ag, Au};

int main(){
  Atomart atom1, atom2;

  atom1 = Al;
  atom2 = Au;
  // atom3 = Zn; // Er checkt, ob die Zuweisung im Datentyp passt!
  // Ab hier geht die Information was atom1 und atom2 ursprueglich als String mal waren verloren!
  // IDEE:  Koennte man zum Parsen nehmen!

  cout << "Atoms: " << atom1 << " , " << atom2 << endl;
  // gibt 0 , 2 aus!
  return 0;
}
