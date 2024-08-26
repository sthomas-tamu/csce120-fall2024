#include <iostream>

using std::cout, std::endl, std::string;

// define a struct
struct Student {
    string firstName = "";   //the first name, initiatilized to an empty string
    string lastName = "";    //the last name, initialized to an empty string
    int graduatingClass = 0; //their graduating class year, initialized to 0
};


void PrintStudent(Student student) {
    cout << student.firstName << " " << student.lastName << ", class of " << student.graduatingClass;
}


int main() {
    // declare / define a struct variable
    Student student;

    // assign values to members of the struct
    student.firstName = "Shawna";
    student.lastName = "Thomas";
    student.graduatingClass = 2002;
    
    // access members of the struct
    cout << "I am ";
    PrintStudent(student);
    cout << "." << endl;


    // another way to declar a struct variable and set its members
    Student grandfather;
    grandfather = {"Charles", "Miller", 1940};
    cout << "My grandfather was ";
    PrintStudent(grandfather);
    cout << "." << endl;


    // yet another way, all on 1 line
    Student ta({"Sam", "Lightfoot", 2024});
    cout << "The TA is ";
    PrintStudent(ta);
    cout << "." << endl;
}
