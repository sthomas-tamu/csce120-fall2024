#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
// will have using std::string etc commands in .cpp file
// best to keep these out of the header since other files include this header

class Student {
  
  private: // private keyword is optional since this is the default, good practice to be explicit

    //Data Members
    // - when designing classes, typically want data to be private so you can guard it properly
    std::string name;
    int uin;
  
  public:
    
    //Constructors
    // - these are member functions that create new Student objects/instances
    // - they define how to initialize all the data members
    // - always think about what constructors make sense to provide
    // - if you don't define any constructors, the compiler may automatically create the default, 
    //   but this is not standardized so unpredictable
    // - if you do define one or more constructors, the default constructor is not automatically created
    //   so you should define it (you know best what should be done)
    Student(std::string _name, int _uin); // supply both name and uin
    Student(std::string _name);           // supply just name, need to set a default value for uin
    Student(int _uin);                    // supply just uin, need to set a default value for name
    Student();                            // supply nothing, need to set a default for both

    //Member Methods
    // - declare them const when you don't want them to change any of the object's data members,
    //   this lets the compiler help you by giving an error if you try to change something directly or
    //   call another function that will change something

    std::string getName() const; // getter function

    int getUIN() const; //getter function
};

#endif
