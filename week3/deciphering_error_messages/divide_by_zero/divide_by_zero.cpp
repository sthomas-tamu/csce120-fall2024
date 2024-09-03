#include <iostream>

int f(int x) {
    return 1 / (x - 2) + 3;
}

int main() {
    std::cout << "f(2) = " << f(2) << std::endl;
}