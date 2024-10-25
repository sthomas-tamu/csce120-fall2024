#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

// what happens when you change x to &x?
// what happens when you change y to &y?
// what happens when you change both to &?
int myFunction(int x, int y) {
    x++;
    y = y-2;
    return x + y;
}

// what happens when you remove p = q?
// what happens when you change int* p to int*& p?
// what haqqens when you change int* q to int*& q?
int myOtherFunction(int* p, int* q) {
    p = q;
    *p = -2;
    *q = -5;

    return *p + *q;
}


struct Person {
    string name;
    unsigned int age;
};

void printPerson(Person p) {
    cout << p.name << ", " << p.age;
}

// what happens if you change p to be &p?
// what if it is a pointer?
void myNextFunction(Person p) {
    p.name = p.name + "-";
    p.age++;
}


int main() {
    int a = 5;
    int b = 10;

    cout << "Before myFunction:\t" << "a: " << a << "\tb: " << b << endl;
    int c = myFunction(a, b);
    cout << "After myFunction:\t" << "a: " << a << "\tb: " << b << "\tc: " << c << endl;
    cout << endl;  

 
    int *p = &a;
    int *q = &b;
    cout << "Before myOtherFunction:\t" << "a: " << a << "\tb: " << b << endl;
    cout << "\taddress of\ta: " << &a << " and b: " << &b << endl;
    cout << "\tvalue of\tp: " << p << "\tq: " << q << endl;
    cout << "\tvalue AT\tp: " << *p << "\tq: " << *q << endl;
    c = myOtherFunction(p, q);
    cout << "After myOtherFunction:\t" << "a: " << a << "\tb: " << b << "\tc: " << c << endl;
    cout << "\taddress of\ta: " << &a << " and b: " << &b << endl;
    cout << "\tvalue of\tp: " << p << "\tq: " << q << endl;
    cout << "\tvalue AT\tp: " << *p << "\tq: " << *q << endl;
    cout << endl;

    Person person = {"Bob", 20};
    cout << "Before myNextFunction:\tperson: ";
    printPerson(person);
    cout << endl;

    myNextFunction(person);    
    cout << "After myNextFunction:\tperson: ";
    printPerson(person);
    cout << endl;
    

    return 0;
}
