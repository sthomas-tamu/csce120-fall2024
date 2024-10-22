#include "Student.h"
#include <iostream>

using std::cout, std::endl;

int main() {
    Student student1("Alice", 1234);
    Student student2("Bob");
    auto student3 = Student(5678); // can use "auto" to tell the compiler to figure out the appropriate data type for Student3, must provide enough information (such as by assigning to a Student object) to not be ambiguous
    Student student4; // calls the default constructor
  
    /*
    cout << "My name is" << student1.name << "and my UIN is" << student1.uin << "\n";
    cout << "My name is" << student2.name << "and my UIN is" << student2.uin << "\n";
    cout << "My name is" << student3.name << "and my UIN is" << student3.uin;
    */
  
    cout << "My name is " << student1.getName() << " and my UIN is " << student1.getUIN() << endl;
    cout << "My name is " << student2.getName() << " and my UIN is " << student2.getUIN() << endl;
    cout << "My name is " << student3.getName() << " and my UIN is " << student3.getUIN() << endl;
    cout << "My name is " << student4.getName() << " and my UIN is " << student4.getUIN() << endl;
  
    return 0;
};

