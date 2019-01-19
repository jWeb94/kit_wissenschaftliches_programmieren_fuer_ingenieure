#include <iostream>
#include  <cmath>
using namespace std;

int main(){

    /*
    Erklaerung im handschriftlichen Aufschrieb der Uebung 6. Insbesondere Zusammenfassung auf der
    Rueckseite von Seite 1

    Siehe auch: https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html

    */

    double v1,v2,v3;

    cout.precision(15); // precision auf 15 setzen, um double vollstaendig abbilden zu können

    double test_relativ = 1.e16;
    cout << "test_relativ is: " << test_relativ << endl;
    test_relativ = test_relativ - 5.1;
    cout << "test_relativ - 1 is: " << test_relativ << endl;

    double test2 = 1.e19;
    cout << test2 << endl;
    test2 += 1000;
    cout  << "test2 + 1000: " << test2 << endl;
    if (test2 == 1.e19){
      cout << "unterscheidbarkeit 1" << endl;
    }
    test2 += 2000;
    cout << "test2 + 2000: " << test2 << endl;
    if (test2 == 1.e19){
      cout << "unterscheidbarkeit 2" << endl;
    }

    // Vergleich von Fliesszahlen

    for(int i=0;i<4;i++){        // iterate 0 to 9

        cout << "Iteration " << i << " :" << endl;

        v1=pow(10,i)*1e16;        // 10^i*10^16
        v2=v1;
        unsigned int nc { 0};     // unsigned int holds values from 0 to 65535
        v3 =0.;

        size_t while_counter = 0;
        while(v2==v1){  // so lange kein Unterschied zwischen den Zahlen festzustellen ist
            while_counter++;
            v3+=10.e2;  // Inkrement mit 1000=10*10^2 erhöhen
            v2+=v3;     // Erhoehe v2 immer staerker von Iteration zu Iteration

            nc++;       // Counter wie viele Iterationen ich brauche, bis ein Unterschied entsteht!
            //
            if(nc==0){          // wenn irgendwas schief laeuft
                cout<<"break ";
                break;
            }
            cout << "v2 of while iteration " << while_counter << " is: " << v2 << endl;
            cout << "corresponding v1 is: " << v1 << endl;
            cout << "v3 is : " << v3 << endl;
        }
        cout << "while_counter for this iteration is: " << while_counter << endl;
        cout<<"nc="<<nc  <<" v2="<<v2<<" v1="<<v1<<endl;
    }
    return 0 ;
}
