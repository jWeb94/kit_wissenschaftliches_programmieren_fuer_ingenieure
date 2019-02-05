#ifndef _PARTICLE
#define _PARTICLE

const auto dim=2;

struct particle{
    double pos[dim];
    double vel[dim];
    double f[dim];
    double fold[dim]; // fuer Verlet Verfahren - Kraft im letzten Iterationsschritt
    double m;
};

#endif
