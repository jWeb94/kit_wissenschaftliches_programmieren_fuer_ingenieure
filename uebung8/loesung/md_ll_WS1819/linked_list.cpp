#include <iostream>
#include <cmath>
#include "particle.h"
using namespace std;

int **lc;  // linked cell
int *ll;   // linked list
int nmax[dim]; // Anzahl der Unterteilungen in x und y Richtung
double rc[dim]; //rcut off in die jeweilige Berechnung, da L[]
// nicht notwendigerweise ein vielfaches von rcut ist







// (i) initialisiert die cut off parameter in beiden Dimensionen
// (ii) Speicher fuer das Feld lc und den Vektor lc wird belegt

void init_linked_list(const double L[], const double rcut,const unsigned int ntot){
    for(auto i=0;i<dim;i++){
        nmax[i]=int(floor(L[i]/rcut));
        rc[i]=L[i]/nmax[i];
    }

    cout<<"nmax:"<<nmax[0]<<","<<nmax[1]<<endl;
    cout<<"rcut:"<<rcut<<":"<<rc[0]<<","<<rc[1]<<endl;

    // Erstelle die linked list
    ll = new int[ntot]; // fuer jedes Atom wird ein Eintrag benoetigt
    // Erstelle lc als dynamisches Array auf dem Heap - mit zusammenhaengendem Speicher!
    lc = new int*[nmax[0]];
    lc[0]= new int[(nmax[0])*(nmax[1])];
    for(auto i=1;i<nmax[0];i++)
        lc[i]=lc[0]+i*(nmax[1]);
    //
    for(auto i=0;i<ntot;i++)
        ll[i]=-1;

    for(auto i=0;i<nmax[0];i++)
        for(auto j=0;j<nmax[1];j++)
            lc[i][j]=-1;

}

// Aufbau der Nachbarschaftlisten
void setup_neighbour_list(const particle * const p, const unsigned int ntot){
    // Initialsisiere ll und lc mit -1 in allen Komponenten
    for(auto i=0;i<ntot;i++)
        ll[i]=-1;
    for(auto i=0;i<nmax[0];i++)
        for(auto j=0;j<nmax[1];j++)
            lc[i][j]=-1;

    {  // Aufbau der Listen:
      int nidx[dim];
      for(auto i=0;i<ntot;i++){                                   // Iteriere ueber alle Atome
          for(auto n=0;n<dim;n++){                                // Iteriere ueber alle Dimensionen (wir: 2D)
              nidx[n]=int(floor(p[i].pos[n]/rc[n]));              // x_koord/r_cut = Anzahl der Zelle
              nidx[n]=min(nidx[n],nmax[n]-1);                     // Wenn an oberer Grenze ausserhalb des Untersuchungsbereichs, dann schiebe in letzte Zelle des Untersuchungsbereichs
              nidx[n]=max(nidx[n],0);                             // Wenn unterhalb unterer Grenze des Untersuchungsbereichs, dann schiebe in erste Zelle
          }

          ll[i] = lc[nidx[0]][nidx[1]];                           // Wenn hier schon ein Atom in der Zelle ist, wissen wir, dass das aktuelle Atom i den vorher (in der naechsten Zeile beschriebnen) Nachbarn hat!
          lc[nidx[0]][nidx[1]]=i;                                 // Schreibe die Atomnummer in lc -> Wir wissen jetzt, dass Atom Nummer i in Zelle i, j (bestimmt durch die Koordinaten nidx[0] und nidx[1]) ist.
      }

    }
}

// zur Information
void print_neighour_list(){
    int n;

    for(auto i=0;i<nmax[0];i++){
        for(auto j=0;j<nmax[1];j++){
            if(lc[i][j]!=-1){
                n=lc[i][j];
                cout<<"Zelle i,j:"<<i<<","<<j<<endl;
                while(n!=-1){
                    cout<<" "<<n<<endl;
                    n=ll[n];
                }
            }
            else{
                cout<<"keine Atome in Zelle i,j: "<<i<<","<<j<<endl;
            }
        }
    }
}



// Kraefteberechnung mit Nachbarschaftslisten: offene Raender

void force_calculation_neighbour(particle *const p, const unsigned int ntot,
        void force(particle *const p1, particle *const p2)){
    // * die Nachbarn der Zelle (i,j) lassen sich mit den Offsets ndx,ndy erreichen
    // * dabei ist zu beachten, dass actio=reactio in die Berechnung eingeht
    int ndx[]={1,1,0,-1};       //      [3](i-1,j+1)-- [2](i,j+1) --[1](i+1,j+1)
    int ndy[]={0,1,1,1};        //                        (i,j)   --[0](i+1,j)
    int n1,n2,nx,ny;
    // Kraft auf Null setzen: - da wird nicht wissen, welche Kraft noch wirkt, da sich evt Atome so weit weg bewegt haben, dass das zu untersuchende Teilchen die Kraft nicht mehr spürt!
    for(auto i=0;i<ntot;i++)
        for(auto n=0;n<dim;n++)
            p[i].f[n]=0;

    // neue Kraft berechnen: hier mal ohne auto...
    for(int i=0;i<nmax[0];i++){
        for(int j=0;j<nmax[1];j++){
            if(lc[i][j]!=-1){                                   // Wenn in einer Zelle aus lc Atome zu finden sind (dann ist ja schliesslich der Wert von lc != -1)
                n1=lc[i][j];                                    // Erstes Atom in der Zelle wird n1 zugeordnet!
                //	cout<<"Zelle i,j:"<<i<<","<<j<<endl;
                while(n1!=-1){
                    n2=ll[n1];                                  // Nachbar des ersten Atoms n1 wird n2 zugeordnet
                    while(n2!=-1){                              // So lange das Nachbaratom n2 noch Nachbarn hat
                        force(&p[n1],&p[n2]);                   // force kommt aus interaction_lj/force_lj -> Wird fuer alle Nachbarn von n1 aufaddiert!
                        n2=ll[n2];                              // Naechster Nachbar!
                    }

                    // Nachbarzellen
                    for(int no=0;no<4;no++){
                        nx=i+ndx[no];
                        ny=j+ndy[no];

                        // Randbedigungen:
                        if(nx<0) continue; // geht ans Ende der Schleife...
                        if(nx>nmax[0]-1) continue;
                        if(ny<0) continue;
                        if(ny>nmax[1]-1) continue;
                        n2=lc[nx][ny];
                        while(n2!=-1){
                            force(&p[n1],&p[n2]);
                            n2=ll[n2];
                        }
                    }
                    n1=ll[n1];
                }
            }
        }
    }
}
