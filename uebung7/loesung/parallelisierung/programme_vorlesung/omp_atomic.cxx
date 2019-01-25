/*
 * omp_atomic.cxx
 *
 */
#include<iostream>
#include <omp.h>

using namespace std;

int main()
{
	int i = 0;
	int j = 0;

#pragma omp parallel
	{
		i++;
		#pragma omp critical
		{
			cout << "thread number: " << omp_get_thread_num() << " i=" << i << endl;
		}


#pragma omp atomic
		j++; // atomic bezieht sich nur auf die naechst folgende Zeile und geht nur fuer elementare Operatoren wie +=, +, -, * !
		#pragma omp critical
		{
			cout << "thread number: " << omp_get_thread_num() << " j=" << j << endl;
		}

		/*
		 * atomic wird bei einzelnen Operationen die geschuetzt werden sollen
		 * gerne genommen, da der Compiler damit besser optimieren kann!
		 *
		 * ACHTUNG: Wenn ein Funktionsaufruf in der Atomic-Anweisung steht, dann ist nur der Funktionsaufruf geschuetzt
		 * Die Funktion selbst nicht!
		 */



	}


	cout << "Wert von i am Ende: " << i << endl;
	cout << "Wert von j am Ende: " << j << endl;
}
