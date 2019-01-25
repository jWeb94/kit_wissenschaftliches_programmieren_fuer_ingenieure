/*
 * omp_reduction.cxx
 *
 */
#include<iostream>
#include <omp.h>

using namespace std;

int main()
{
	int i = 10;
#pragma omp parallel reduction(-:i)
	{
		i=2-3; // Berechnung des lokalen i
		#pragma omp critical
		{
			cout << "in thread number " << omp_get_thread_num() << " i is: " << i << endl;
		}

	}

	cout << "Wert von i am Ende: " << i << endl;

}
