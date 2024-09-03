#include <iostream>

int main() {
    char input[20];
    std::cout << "> ";
    std::cin >> input;
    std::cout << "input: " << std::flush << input << std::endl;
}