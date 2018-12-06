#include <iostream>
#include <Eigen/Dense>  // Dicht besetzte Matrizen ~ nicht volles Eigen3 Package, da sonst das Compilieren ewig dauert
						// Eigen3 liegt als rein header-basierte Bibliothek vor -> wird immer neu übersetzt!

using namespace Eigen;
using namespace std;


/*
 * Eigen3 lässt es zu, dynamisch Matrizen/Vektoren zu erstellen, ohne deren Dimensionen hart zu coden
 * Das ist ansonsten nur möglich, wenn man die Speicherverwaltung auf dem Heap selbst übernimmt
 * (arbeiten mit new)
 *
 * Schleifen über Komponenten zum Verrechnen nicht notwendig, alles im Hintergrund effizient implementiert
 */



Vector3d gib_ein_ergebnis_zurueck(Matrix3d const &mat,Vector3d const &vec){
  /*ü
   * Uebergeben wird eine Referenz auf eine Matrix (ein Alias innerhalb der Methode), die innerhalb der Methode nicht veränderlich sein sollen.
   * Vgl 'Constant Correctness'
   *
   * Rückgabe ist ein Objekt vom Typ Vector3d, dass sich aus der Verrechnung der beiden Übergabeparametern ergibt
   * Der *-Operator wurde überladen und gibt ein Objekt zurück, dass den Datentyp anhand des aufrufenden Objekts und des damit zu verrechnenden Objekts ableitet!
   * vgl Documentation (anschauen mit F3)
   */

  cout<<"Ausgabe Vektor:"<<vec<<endl;
  return mat*vec;
  // return vec*mat; // test ob er dann mäckert/was passiert wenn die Dimensionen nicht passen
  // Dann mäckert der Compiler, da Eigen über assertions checkt, ob die Dimensionen passen!

}

int main()
{
  Matrix3d m = Matrix3d::Random();  		// dies ist eine static Methode der Matrix3d Klasse (kommt noch)
  	  // Matrix3d erstellt eine 3x3 Matrix; diese soll initialisiert werden mit den Werten des (temporär eristierenden) Objekts Matrix3d::Random()
  	  /*
  	   * MatrixXd -> X x X große Matrix vom Type d = double
  	   * Konstruktor: Eigen::MatrixXd testMatrix(rows, columns);
  	   * Oder Zuweisung eines anderen, temprären Objekts
  	   * Eigen3::MatrixXd m = Eigen3::MatrixXd::Random(rows, cols); // Matrix mit Random Values zwischen -1 und 1 vom typ double
  	   * Eigen3::MatrixXd m2 = Eigen3::MatrixXd::Constant(rows, cols, value);
  	   */

  m = (m + Matrix3d::Constant(1.2)) * 50;
  	  // Rechnen mit gleichartigen Matrizen ist ähnlich wie in Mathematik möglich. Die +, -, *, /, ... Operatoren sind entsprechend überladen


  /*
  // debug
  Matrix3d testMatrixConst = Matrix3d::Constant(1.2);
  std::cout << "This is testMatrixConst: " << std::endl;
  std::cout << testMatrixConst << std::endl;
  // ::Constant(double) erstellt eine X dimensionale Matrix die in allen ihren Elementen die double-zahl stehen hat
  */


  cout << "m =" << endl << m << endl;

  // Gleiches gilt für Vektoren
  Vector3d V(1,2,3);  // Initialisierung der Komponeten mit (1,2,3)

  cout << "m * v =" << endl << m * V << endl;

  Vector3d vec;
  vec = gib_ein_ergebnis_zurueck(m,V);

  cout<<"vec:"<<vec<<endl;

  double val=vec.transpose()*vec;
  	  // Vetoren und Matrizen sind als Objekte implementiert!
  	  // transpose ist eine Methode von Vector3d und transponiert den Vector
  	  // Sie liefert ein (temporäres) Objekt vom selben Datentyp wie das Objekt mit dem die Methode aufgerufen wurde zurück

  cout<<"Skalarprodukt:"<<val<<" oder mit .dot Methode: "<<vec.dot(vec) <<endl;

  // aeusser Produkt:
  Matrix3d m2=vec*vec.transpose();

  cout<<"m2: "<<endl;
  cout<<m2<<endl;

  return 0;

}

