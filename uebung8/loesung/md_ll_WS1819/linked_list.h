#ifndef _LINKED_LIST
#define _LINKED_LIST

void init_linked_list(const double L[],
                      const double rcut,
                      const unsigned int ntot);

void setup_neighbour_list(const particle * const p, const unsigned int ntot);

void print_neighour_list();

void force_calculation_neighbour(particle *const p, const unsigned int ntot,
					void force(particle *const p1, particle * const p2));

#endif
