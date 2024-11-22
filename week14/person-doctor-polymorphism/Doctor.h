#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "Person.h"

class Doctor : public Person {
    std::string specialty;

  public:
    Doctor() : Person(), specialty("none") {}
    Doctor(std::string name, int age, std::string specialty = "none") : Person(name, age), specialty(specialty) {}
   
    std::string getSpecialty() const { return specialty; }
    void setSpecialty(std::string newSpecialty) { specialty = newSpecialty; }

    virtual std::string getString() const {
        std::ostringstream os;
        //os << Person::getString();
        os << getName() << " (" << getAge() << ")";
        os << " [" << specialty << "]";
        return os.str();
    }


};

#endif
