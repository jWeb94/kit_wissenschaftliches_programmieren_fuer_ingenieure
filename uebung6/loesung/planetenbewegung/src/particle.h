#ifndef _PARTICLE
#define _PARTICLE

const int dim=2;
struct particle{
    double pos[dim];    // Position
    double vel[dim];    // Geschwindigkeit
    double f[dim];      // Kraft auf Partikel
    double fold[dim];   // Kraft auf vorherigem Iterationsschritt - fuer Verlet Verfahren notwendig
    double m;           // Masse
    double kinE;
    double potE;
    double gesE; 
};
/* struct: ist quasi eine Klasse ohne Memberfunktionen und alles public
 * Es wird so ein neuer Datentyp erstellt, der aus mehreren Grunddatentypen besteht
 *
 */

#endif
