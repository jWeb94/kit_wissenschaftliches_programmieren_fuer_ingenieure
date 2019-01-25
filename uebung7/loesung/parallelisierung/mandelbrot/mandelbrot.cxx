#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <complex>
#include <omp.h>
#include <time.h>


typedef std::complex<double> Complex;

 int MandelbrotCalculate(Complex c, int maxiter)
 {
    /*
     #pragma omp critical
     {
      std::cout << "MandelbrotCalculate was called in thread " << omp_get_thread_num() << std::endl;
     }
     */
     Complex z = c;
     int n=0;
     for(; n<maxiter; ++n)
     {
         if( std::abs(z) >= 2.0) break;
         z = z*z + c;
     }
     return n;
 }


using namespace std;



 int main()
 {
     const int width = 5*20, height = 5*20, num_pixels = width*height;

     const Complex center(-.7, 0), span(2.7, -(4/3.0)*2.7*height/width);
     const Complex begin = center-span/2.0, end = center+span/2.0;
     const int maxiter = 100000;

     // gnuplot file: define ofstream object
     ofstream gpfile("mandel.dat");
     //
     std::cout << "Number of available threads: " << omp_get_max_threads()  << std::endl;

     clock_t start, finish;
     start = clock();

     #pragma omp parallel
     {
     #pragma omp for ordered        // Loop Berechne parallel geordnet.
     for(int pix=0; pix<num_pixels; ++pix)
     {
         const int x = pix%width, y = pix/width;

         Complex c = begin + Complex(x * span.real() / (width +1.0),
                                     y * span.imag() / (height+1.0));

         int n = MandelbrotCalculate(c, maxiter);
         if(n == maxiter) n = 0;

         // n und c (enthaelt x- und y-Komponente) leben lokal in jedem Thread ! Keine Critical Section notwendig, da die Berechnung jeweils unabhaengig voneinander stattfinden kann!
         {
	     if(n>10) n=10;

	     // gnuplot output
	     if(pix>0 && x==0) gpfile<<endl;
       //#pragma omp critical // Um sicher in die Ergbenisdatei zu plotten
       #pragma omp ordered
        gpfile <<c.real()<<" "<<c.imag()<<" "<<n<<endl;

        /*
        * Was macht ordered?
        * Der Loop wird standartmaessig parallel ausgefuehrt bis zu der Stelle, an der
        * die ordered Anweisung auftaucht. Die nachfolgende Anweisung wird von den parallelen Threads so ausgefueht, als ob
        * es sich um einen sequentiellen Loop handeln wuerde.
        *
        * Das erlaubt nur einen gewissen Anteil an Parallelitaet, da in der ordered section
        * stets auf jeweils alle anderen Threads gewartet wird und das Programm sequentialisiert wird!
        */

	     //std::cout << n << " ";
	     //if(x+1 == width) std::cout << std::endl;
	 }

     }
   }
     finish = clock();

     double difference = double(finish-start)/CLOCKS_PER_SEC;
     std::cout << "the execution time of the loop was: " << difference << std::endl;

     gpfile.close();

     cout << "pixel: " << num_pixels << endl;
     //     cout << "time: " << t1-t0 << "" << endl;
 }
