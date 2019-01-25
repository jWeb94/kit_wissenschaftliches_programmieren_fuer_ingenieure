/*
 * omp_for.cxx
 *
 */
#include<iostream>
#include <omp.h>

using namespace std;

int main()
{
	int i;
	int feld[20];
	int sum;

	i=10;
	sum=0;

#pragma omp parallel
	{
#pragma omp for // Nicht mit parallel Statement, da wir schon im parallelen Teil des Codes sind!
		for(int i=0;i<20;i++){ 	// Wird von jedem Thread parallel ausgefuehrt!
			#pragma omp critical
			{
					std::cout << "this is i in the first for loop in thread " << omp_get_thread_num() << " : " << i << std::endl;
			}
			feld[i]=i*i; // i ist hier die Scope-Variable von for
	  }

#pragma omp for reduction(+:sum)
		for(int i=0;i<20;i++) // Warum hier reduction? 
			#pragma omp critical
			{
				sum=sum+feld[i];
				std::cout << "this is sum in iteration i = "  << i << " in thread " << omp_get_thread_num() << " : " << sum << std::endl;
			}


	}

	for(i=0;i<20;i++)
		cout <<"feld["<<i<<"]="<<feld[i]<<endl;

	cout <<"Summe:"<<sum<<endl;

	// Nicht parallel gegenchecken:
	int sum_test = 0;
	for (int i = 0; i < 20 ; i++){
		sum_test = sum_test + feld[i];
	}
	std::cout << "this is sum_test: " << sum_test << std::endl;
}
