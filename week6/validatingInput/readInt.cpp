#include <iostream>

using std::cout, std::endl, std::cin;

int main() {
    int val = 0;
    cout << "Enter an integer: ";
    cin >> val;

    while(!cin.fail()) { // data was successfully read 
        cout << "You entered: " << val << endl;

	    if(!cin.eof()) { // haven't reached the end (this doesn't happen with keyboard input, but could happen with a file)

            cin.clear(); // set all stream state bits to zero, buffer NOT cleared

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer of everything/make clean slate to read again

            cout << "Enter a valid integer: ";
            cin >> val;
        }
    }
    cout << "Invalid input, exiting." << endl;

    return 0;
}
