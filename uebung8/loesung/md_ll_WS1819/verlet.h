#ifndef _VERLET
#define _VERLET
#include "particle.h"

void init_verlet(particle * const p, const unsigned int nmax);
void update_positions(particle *const p,const unsigned int nmax, const double dt);
void update_velocities(particle *const p, const unsigned int nmax, const double dt);

#endif
