#include "Doctor.h"

#include <iostream>

using std::cout, std::endl;

int main() {
   Person* p = new Person("George", 22);
   cout << "p: " << *p << endl;

   Doctor* d = new Doctor("Sam", 37, "surgeon");
   cout << "d: " << *d << endl;
   d->setAge(45);
   cout << "updated age for d: " << *d << endl;

   cout << endl;
 
   Person* w;
   cout << "setting w = p" << endl;
   w = p;
   cout << "w: " << *w << endl;

   cout << endl;

   cout << "setting w = d" << endl;
   w = d;
   cout << "w: " << *w << endl;

   delete p;
   delete d;
}
