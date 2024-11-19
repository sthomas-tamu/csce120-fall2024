#include "Employee.h"

#include <iostream>

using std::cout, std::endl;

int main (int argc, char * argv[]) {
    HourlyEmployee he {"James", "Williams", 18.50};
    cout << "HourlyEmployee" << endl;
    cout << '\t' << he.firstName << ' ' << he.lastName << '\t' << he.hourlyWage << endl;

    SalariedEmployee sh {"Mary", "Smith", 134000};
    cout << "SalariedEmployee" << endl;
    cout << '\t' << sh.firstName << ' ' << sh.lastName << '\t' << sh.annualSalary << endl;

    return 0;
}
