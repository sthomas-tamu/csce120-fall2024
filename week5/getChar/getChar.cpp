#include <iostream>

using std::cin, std::cout, std::endl, std::string;

int main() {
    string word = "supercalifragilisticexpialidocious";
    cout << "The string is '" << word << "'" << endl;

    size_t index = 0;
    do {
        cout << "Enter index to show letter or 9999 to exit: ";
        if(cin >> index) {
            if(index != 9999) {
                try {
                    cout << word.at(index) << " is the letter at index " << index << endl;
                }
                catch (std::out_of_range &e) {
                    cout << "out of range: " << e.what() << endl;
                }
                catch ( ... ) {
                    cout << "unknown exception" << endl;
                }
            }
        } else {
            cout << "bad input, try again" << endl;
            cin.clear();
            cin.ignore(100000, '\n');
        }
    } while (index != 9999);

    return 0;
}
