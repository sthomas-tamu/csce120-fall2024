#include <iostream>
#include <limits>

using std::cin, std::cout, std::endl;

int main()
{
    cout << "Please provide a number of lines to print the stair-case pattern: ";
    unsigned int no_lines;
    cin >> no_lines;
    
    for (unsigned int i = 1; i <= no_lines ; ++i) {
        for (unsigned int j = 1 ; j <= i ; ++j) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
