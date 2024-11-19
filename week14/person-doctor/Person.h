#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <ostream>
#include <sstream>

class Person {
    std::string name;
    int age;

  public:
    Person() : name(""), age(-1) {}
    Person(std::string name, int age) : name(name), age(age) {}
   
    std::string getName() const { return name; }
    void setName(std::string newName) { name = newName; }

    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.getName() << " (" << p.getAge() << ")";
    return os;
}

#endif
