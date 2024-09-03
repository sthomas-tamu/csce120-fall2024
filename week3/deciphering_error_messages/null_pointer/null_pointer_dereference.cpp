#include <iostream>

int main() {
    int* p = nullptr;
    std::cout << "p is a null pointer." << std::endl;
    std::cout << "the value of p (the address stored in p) is " << p << std::endl;
    std::cout << "the value of *p (the value at the address stored in p) is " << std::flush << *p << std::endl;
    std::cout << "here there be dragons" << std::endl;
}