/*
 * omp_parallel.cxx
 *
 */
#include<iostream>
#include <omp.h> // Schnittstelle zu openmp

using namespace std;

int main()
{
#pragma omp parallel
	{											// hier beginnt der parallel ausgefuehrte Block
		cout << "Thread num: " << omp_get_thread_num() << endl;
		/*
		 * Bei der Umgebundvariable OMP_NUM_THREADS=4
		 * Werden 4 Threads aufgemacht, die von 0 bis 3 numeriert sind!
		 * Der Parallele Teil wird dann 3 Mal ausgefuehrt, da jeder Thread quasi ein eigener Prozess ist.
		 * Eine Logik kriege ich nur rein, wenn ich Abbruch/Kopplungsbedingungen zu den anderen Threads
		 * implementiere, in dem ich globale Variablen schuetze und an die einzelnen Threads uebergebe!
		 */

		 /*
		  * Da der cout-Kanal nur ein Kanal ist und dieser für alle Programme, also auch alle Threads
			* die Kanalnummer 0 hat, wird ungeordnet in den Kanal geprintet.
		  * Das könnte man mit einer critial Section o.ae. umgehen
		  */


	}											// hier endet der parallel ausgefuehrte Block

	cout << "this is the same code in a critical section: " << endl;
	#pragma omp parallel
	{
		#pragma omp critical
		{
				/*
				 * Critical Sections sind fuer printouts die zusammenhaengen sollen,
				 * Dateizugriffe und Berechnungen die in eine gemeinsame Variable
				 * laufen sollen (das ist auch ein Variablenzugriff)
				 */
			 cout << "Thread num: " << omp_get_thread_num() << endl;
		}
	}
}
