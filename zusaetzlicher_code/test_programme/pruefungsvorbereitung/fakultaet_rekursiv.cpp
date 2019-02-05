#include<iostream>

/*
unsigned int fakultaet(unsigned int intput_zahl){
  // 3! = 3*2*1
  if (intput_zahl > 1){
    return intput_zahl*fakultaet(intput_zahl-1);
  }
  else{
    return 1;
  }
}
*/
 unsigned int fakultaet(unsigned int intput_zahl){
   if (intput_zahl<=1)
   {
     return 1;
   }
   else
   {
     return intput_zahl * fakultaet(intput_zahl-1); 
   }
 }


int main(){
  unsigned int zahl;
  unsigned int fakultaet_zahl;
  std::cout << "Bitte gib die Zahl ein, von der die Fakultaet berechnet werden soll: " << std::endl;
  std::cin >> zahl;

  fakultaet_zahl =  fakultaet(zahl);

  std::cout << zahl << "! = " << fakultaet_zahl << std::endl;

  return 0;
}
