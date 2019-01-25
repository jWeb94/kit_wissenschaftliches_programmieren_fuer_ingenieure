/*
 * omp_critical.cxx
 *
 */
#include<iostream>
#include <omp.h>

using namespace std;

int main()
{
	int i = 0;
#pragma omp parallel
	{
#pragma omp critical
		{
			// Berechnung und Ausgabe in critical Section
			i++;
			cout << "i = " << i << endl;
		}

	}

	cout << "Wert von i am Ende: " << i << endl;

}
