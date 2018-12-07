#ifndef FUNCTIONS_GAME_H_
#define FUNCTIONS_GAME_H_

// durch obige Anweisungen wird doppeltes Einbinden verhindert

#include <cstdlib>
#include <Eigen/Dense>
#include <fstream>

using namespace Eigen;


MatrixXi create_field2d(const unsigned int ,const unsigned int);
void init_field2d(MatrixXi &, const double);
void make_step(MatrixXi &, MatrixXi &);
void plot_field(MatrixXi const &,const unsigned int);

#endif /* FUNCTIONS_GAME_H_ */
