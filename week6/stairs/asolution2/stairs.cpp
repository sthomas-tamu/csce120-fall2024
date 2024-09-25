#include <iostream>
#include <limits>

using std::cin, std::cout, std::endl;

int main()
{
    unsigned int no_lines = 0;
    while (no_lines == 0) { // read in no_lines until successfully get a number between 1 and 80
        try {
            cout << "Please provide a number of lines to print the stair-case pattern: ";
            cin >> no_lines;

            if (cin.fail()) {
                cin.clear(); // reset the stream's state bits so we can try to read again
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ingore the rest of the input line to get clean data on the next read
                                                                               //  - first parameter is the number of characters to ignore
                                                                               //    which we set to the maximum size the stream can be for the computer
                                                                               //  - second parameter is the end of file delimiter which we set to '\n'
                throw std::string("invalid input"); // throw a string with an error message to catch and print
            }
            if (no_lines > 80) { // will only get to this if the first if statement doesn't throw anything
                                 // don't need to check if < 0 because the >> operator already converted 
                                 // the input into an unsigned int which cannot be negative
                // don't need to reset any stream state bits because the read was succesful, just out o frange
                throw std::string("out of range, number must be between 0 and 80"); // throw a string with an error message to catch and print
            }
        }
        catch (const std::string errorMessage) {
            cout << "Error: " << errorMessage << ", try again." << endl;
            no_lines = 0; // reset no_lines to attempt while loop again
        }
    }

    // no_lines validated, can now safely execute for loop
    for (unsigned int i = 1; i <= no_lines ; ++i) {
        for (unsigned int j = 1 ; j <= i ; ++j) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
