#include "Doctor.h"

#include <iostream>

using std::cout, std::endl;

int main() {
   Person p("George", 22);
   cout << "p: " << p << endl;

   Doctor d("Sam", 37, "surgeon");
   cout << "d: " << d << endl;
   cout << "d has a specialty: " << d.getSpecialty() << endl;

   cout << endl;

   Person* ary[2];
   ary[0] = &p;
   ary[1] = &d;
   cout << "The people are: " << endl;
   for(int i=0; i<2; ++i) {
       cout << *ary[i] << endl;
   }
}
