/*
 * omp_firstprivate.cxx
 *
 */
#include<iostream>
#include <omp.h>

using namespace std;

int main()
{
	int i = 20;

#pragma omp parallel firstprivate(i)
	{
		i++;
		#pragma omp critical
		{
				cout << omp_get_thread_num() << " i= " << i << endl;
		}

	}

	cout << "Wert von i am Ende: " << i << endl;
}
