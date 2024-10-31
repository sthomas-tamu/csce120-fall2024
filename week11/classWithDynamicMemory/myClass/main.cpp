#include <iostream>

class MyClass {
    int* ptr;

  public:
    MyClass() { 
        ptr = new int(0); 
    }

    void increment() {
        if(ptr != nullptr) { 
            *ptr = *ptr + 1; 
        }
    }

    void print() const {
        if(ptr != nullptr) { 
            std::cout << *ptr << std::endl; 
        }
    }
};


int main() {
    MyClass c;

    for(int i=0; i<5; ++i) {
        c.increment();
    }

    c.print();
}
