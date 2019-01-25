/*
 * omp_private.cxx
 *
 */
#include<iostream>
#include <omp.h>

using namespace std;

int main()
{
	//int i = 20;

#pragma omp parallel private(i) // i wird innerhalb des threads als lokale variable behandelt und mit undefiniertem Zustand inititalisiert!
	{
		i = 0; // Um den undefinierten Zustand zu überschreiben mit einem gesicherten Wert

		#pragma omp critical
		{
			std::cout << "this is i in thread " <<  omp_get_thread_num() << " : " << i << std::endl;
		}

		i++;

		#pragma omp critical
		{
				cout << omp_get_thread_num() << " i = " << i << endl;
		}


	}

	cout << "Wert von i am Ende: " << i << endl;

}
