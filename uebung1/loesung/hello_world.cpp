#include <iostream>
#include <string>
/* <> in the compiler directives means, that the compiler should search for the hpp-file in the system enviroment; '' means that it is in the current working directory */

using namespace std; 

int main(){
	/* the return value class did not have an ()! */
	/* main method must have an integer output! It enables the OS to get information, if the main method was completly executed*/

	// define string as an output
	string outputString = "Hello World";
	cout<<outputString<<std::endl; 
return 0; // if you dont write the return 0 it is included implicit by the compiler!
} 
