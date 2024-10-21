#include "Student.h"
#include <iostream>

using std::cout, std::endl;

int main() {

  Student Student1("Alice", 1234);
  Student Student2("Bob");
  auto Student3 = Student(5678); // can use "auto" to tell the compiler to figure out the appropriate data type for Student3, must provide enough information (such as by assigning to a Student object) to not be ambiguous
  Student Student4; // calls the default constructor

  /* 
  cout << "My name is" << Student1.name << "and my UIN is" << Student1.uin << "\n";
  cout << "My name is" << Student2.name << "and my UIN is" << Student2.uin << "\n";
  cout << "My name is" << Student3.name << "and my UIN is" << Student3.uin;
  */

  cout << "My name is " << Student1.getName() << " and my UIN is " << Student1.getUIN() << endl;
  cout << "My name is " << Student2.getName() << " and my UIN is " << Student2.getUIN() << endl;
  cout << "My name is " << Student3.getName() << " and my UIN is " << Student3.getUIN() << endl;
  cout << "My name is " << Student4.getName() << " and my UIN is " << Student4.getUIN() << endl;

  return 0;
};

