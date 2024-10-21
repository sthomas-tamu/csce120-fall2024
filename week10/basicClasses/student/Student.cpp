#include "Student.h"

using std::string;

// Two ways to access data members in a member function:
//  - pre C++11: this->uin = 0;
//  - now just:  uin = 0;

// Good style convention, name input parameters with "_" at the beginning
// so you can distinguish between the input variable and the object's data member

Student::Student(int _uin) {
    // using pre C++11 way to access data members
    this->uin = _uin;
    this->name = "No Name";
}

Student::Student(string _name) { 
    // using current way to access data members
    name = _name;
    uin = 0;
}

// using member initialization list format instead
Student::Student(string _name, int _uin): name(_name), uin(_uin) {}

// default constructor
Student::Student() { 
    name = "No Name";
    uin = 0;
}

// always think about which constructors you want to have;
// should we be able to make a student without a name or uin?


// implementing member functions
//  - typically you want to keep all implementation in the .cpp file,
//    but sometimes if it is a very simple function (like a getter/setter)
//    you may decide to implement it in the .h file
std::string Student::getName() const {
    return name;
}

int Student::getUIN() const {
    return uin;
}

