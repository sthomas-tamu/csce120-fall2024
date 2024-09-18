#include <iostream>
#include <string>

using std::cin, std::cout, std::endl, std::string;

int main() {
    string term; // constructor initialzies to empty string

    do {
        cout << "Enter string to convert to an integer or '.' to exit: ";
        cin >> term;

        if(term != ".") {
            size_t size = 0;
            try {
                int value = std::stoi(term, &size);
                cout << term << " times 2 is " << (value * 2) << endl;
            }
            catch (std::invalid_argument &e) {
                cout << "invalid argument - " << e.what() << endl;
            }
            catch (std::out_of_range &e) {
                cout << "out of range - " << e.what() << endl;
            } 
    	    catch (std::exception &e) {
                cout << "other exception - " << e.what() << endl;
            }
    	    catch ( ... ) {
                cout << "unknown exception" << endl;
    	    }
        }
    } while (term != ".");

    return 0;
}
