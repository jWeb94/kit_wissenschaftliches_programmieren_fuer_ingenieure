#include <iostream>
#include <string>

#include "complex.h"

using namespace std;

void output_my_cplx(const MyComplex &c,const std::string txt){
    cout<<txt<<": ("<<c.real()<<", "<<c.imag()<<")"<<endl;
}

int main(){
    MyComplex z1 {2.,7.};
    MyComplex z2 {42.,-9};
    MyComplex z3 {-11.,19.};
    MyComplex z4,z5,z6,z7,z8,z9;

    output_my_cplx(z1,"z1 ");
    output_my_cplx(z2,"z2 ");
    output_my_cplx(z3,"z3 ");

    z4.operator=(z1.operator*(z2));
    output_my_cplx(z4,"z4=z1*z2 =");
    z5.operator=((z1.operator+(z2)));
    output_my_cplx(z5,"z5=(z1+z2) =");
    z6.operator=((z1.operator+(z2)).operator*(2.));
    output_my_cplx(z6,"z6=(z1+z2)*2. = ");
    z7.operator=((z2.operator+(z3)).operator*(z1));
    output_my_cplx(z7,"z7=(z2+z3)*z1 = ");
    z8.operator=(z1.operator+(5.));
    output_my_cplx(z8,"z8=z1+5. = ");
    z9.operator=(z1.operator-().operator+(z2));
    output_my_cplx(z9,"z9=-z1+z2 = ");

    return 0;
}
