#include "functions_game.h"
using namespace std;

MatrixXi create_field2d(const unsigned int nx, const unsigned int ny){

  MatrixXi field=MatrixXi::Zero(nx,ny);

  return field;

}

void init_field2d(MatrixXi &field, const double frac){

    int count = 0;
    int todo_fill;
    int rand_x, rand_y;

    srand(time(NULL)); // setze die Zufallszahlen-Seed neu auf Basis der aktuellen Systemzeit
    /*
     * Unterschied zwischen rand() und srand():
     *
     * rand() erzeugt Pseudo-Zufallszahlen (!) in einem gewissen Bereich (RAND_MAX ist die Obergrenze).
     * Das funktioniert mehr oder minder Kompliziert, abhängig von der Implementiert. Grundsätzlich ist es so, dass
     * eine Basiszahl genommen wird und dann eine Zahl, die auf einer randomisierenden Rechenvorschrift basiert, auf die aktuelle Zahl aufaddiert wird.
     * Eine andere möglichkeit ist es, den Pointer auf die Zahl zu verschieben und so eine andere Zahl zu erhalten.
     * Das Problem ist, dass diese Zahlen einer gewissen Regelmäßgkeit unterliegen (Ende des Definitionsbereichs/Komplementendarstellung von Zahlen im PC)
     * Also wird man ab einer gewissen Anzahl erzeugter Zufallszahlen erneut die gleiche Sequenz bekommen.
     *
     * Das kann, muss aber nicht erwünscht sein!
     * Beispiel für erwünscht:
     *    Randomisiertes Experiment soll mehrfach mit anderen Parametern wiederholt werden.
     *    Dann will ich immer die gleiche Squenz an Zufallszahlen in meinem Experiment haben
     *
     * Möchte ich bewusst immer andere Sequenzen von Zufallszahlen, funktioniert das mit dem rand()-Befehl nicht!
     * srand() versetzt die Parameter der Zufallszahlen und erzeugt somit ein neues 'Set' an Zufallszahlen für den rand-Befehl.
     * Auf diese Weise erhalte ich eine andere Sequenz an Zufallszahlen für einen neuen Aufruf.
     * srand bedeutet soviel wie 'setze Zufallszahlen neu'
     */




    const unsigned int nx = field.rows();
    const unsigned int ny = field.cols();

    todo_fill = int(nx*ny*frac); //Anzahl der zu fuellenden Felder

    while(count < todo_fill){

        rand_x = rand()%nx;
        rand_y = rand()%ny;
        if(field(rand_x,rand_y) != 1){

            field(rand_x,rand_y) = 1;
            count++;
        }
    }
}
void make_step(MatrixXi & field,MatrixXi  & field_tmp){

    int n_neigh;

    const unsigned int nx = field.rows();
    const unsigned int ny = field.cols();

    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){

            //alle 8 Nachbarn checken:
            n_neigh =   int(field((i-1+nx)%nx,j))+
                        int(field((i+1)%nx,j))+
                        int(field(i,(j-1+ny)%ny))+
                        int(field(i,(j+1)%ny))+
                        int(field((i-1+nx)%nx,(j-1+ny)%ny))+
                        int(field((i-1+nx)%nx,(j+1)%ny))+
                        int(field((i+1)%nx,(j-1+ny)%ny))+
                        int(field((i+1)%nx,(j+1)%ny));

            if(field(i,j) == 1){


                switch(n_neigh){
                                case(2): break;
                                case(3): break;
                                default: field_tmp(i,j) = 0;
                }
            }
            else{
                if(n_neigh == 3){

                    field_tmp(i,j)= 1;
                }
            }
        }
    }

    field = field_tmp;
}

void plot_field(MatrixXi const & field, const unsigned int nstep){
    char Dateiname[256]; // Laenge auf 256 Zeichen begrenzt; sollte reichen
    ofstream Datei;

    const unsigned int nx = field.rows();
    const unsigned int ny = field.cols();

    // c-style Dateiname zusammenbauen
    sprintf(Dateiname,"field%d.dat",nstep);
    Datei.open(Dateiname);
    for(int i = 0;i<nx;i++){
      for(int j=0;j<ny;j++){
	Datei<<i<<" "<<j<<" "<<field(i,j)<<endl;
      }
      Datei<<endl;
    }
    Datei.close();
}
