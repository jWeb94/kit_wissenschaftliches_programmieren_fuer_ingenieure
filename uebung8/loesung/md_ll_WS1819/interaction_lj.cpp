#include <iostream>
#include <cmath>
#include "particle.h"
using namespace std;

// Lennard Jones Potenzial
// alle Groessen sind normiert

//  ! length in units of [sigma]
//  ! energy in units of [eps]
//  ! force in units of [eps/sigma]
//  ! mass in units if [m]
//  ! time in units of [sigma sqrt(m/eps)]
//  ! velocity in units of [sqrt(sigma/m)]

// Kraft Berechnung zwischen Teilchen 1 und 2:
// actio=reactio

void force_lj(particle *const p1,particle *const p2){
    double r[dim],f[dim];           // r beinhaltet den Abstand der Atome in (zwei) Dimensionen
    double r2,rm6,one_div_r2;
    double fs;
    //
    for(auto i=0;i<dim;i++)
        r[i]=p2->pos[i]-p1->pos[i];
    //Abstandsquadrat:
    r2=0.;
    for(auto i=0;i<dim;i++)
        r2+=r[i]*r[i];
    //force: skalarer Anteil:
    one_div_r2=1./r2;                       // 1/(delta_r_x^2 + delta_r_y^2)
    rm6=one_div_r2*one_div_r2*one_div_r2;   // (1/r^6) Anteil
    fs= 24.*one_div_r2*rm6*(1.-2.*rm6);     // Berechnung des Lennard-Jones-Potentials, inklusive des Vorfaktors fuer die Kraft (die 24)
    for(auto i=0;i<dim;i++){
        f[i]= fs*r[i];                      // Kraft nach Lennard-Jones-Potentials
        p1->f[i]+=f[i];                     // Kraft * Richtungsvektor
        p2->f[i]-=f[i];                     // Kraft * Richtungsvektor
    }
}

// Berechnung der Potentiellen Energy zweier Teilchen im LJ
// Potenzial

double energy_lj(particle *const p1,particle *const p2){
    double r[dim];
    double r2,rm6,one_div_r2;
    double fs,energy;
    //
    for(auto i=0;i<dim;i++)
        r[i]=p2->pos[i]-p1->pos[i];
    //Abstandsquadrat:
    r2=0.;
    for(auto i=0;i<dim;i++)
        r2+=r[i]*r[i];
    //force: skalarer Anteil:
    one_div_r2=1./r2;
    rm6=one_div_r2*one_div_r2*one_div_r2; // (1/r^6) Anteil
    energy= 4.*rm6*(rm6-1.);
    return double(energy);
}
