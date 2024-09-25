#include <iostream>
#include <limits>

using std::cin, std::cout, std::endl;

int main()
{
    cout << "Please provide a number of lines to print the stair-case pattern: ";
    unsigned int no_lines = 0;
    cin >> no_lines;
    cout << "read: " << no_lines << endl;

    while (cin.fail() || no_lines > 80 || no_lines < 1) { // input failed, ask again
        if (!cin.fail()) { // failed due to no_lines being incorrect
            cout << "number must be between 1 and 80" << endl;
        }
        if (cin.bad()) { // check first since bad also makes fail true
            cout << "unexpected error, please try again." << endl;
        }
        else if (cin.fail()) { // check for invalid char for int
            cout << "your input is not a valid number" << endl;
        }
        cin.clear(); // reset bits
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove bad data
        cout << "Please provide a number of lines to print the stair-case pattern : ";
        cin >> no_lines;
    }
    
    for (unsigned int i = 1; i <= no_lines ; ++i) {
        for (unsigned int j = 1 ; j <= i ; ++j) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
