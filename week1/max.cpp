#include <iostream>

int main() {
    std::cout << "Enter 3 numbers." << std::endl;

    int greatest = 0;

    std::cin >> greatest;

    //check if input is ok
    if(std::cin.fail()) {
        std::cout << "ERROR! not a number. Try again." << std::endl;
        return -1;
    }

    std::cout << "Read number " << greatest << std::endl;

    //read in two more numbers
    for(int i=0; i<2; i++) {
        int value = 0;
        std::cin >> value;
        //check if input is ok
        if(std::cin.fail()) {
            std::cout << "ERROR! not a number. Try again." << std::endl;
            return -1;
        }
        std::cout << "Read number " << value << std::endl;

        //update the greatest
        if(value > greatest) {
            greatest = value;
        }

    }

    std::cout << "The greatest number is " << greatest << std::endl;
    return 0;
}