#include <iostream>
#include <string>
#include <ctime>

using std::cout, std::endl, std::cin, std::string;

//return the middle of the string
string getMiddleThird(string& str) {
    string retStr;

    size_t third = str.size()/3; // will accept there may be some rounding errors
    for (size_t i=third; i<(third*2); ++i) {
        retStr += str.at(i);
    }

    // side effect to fix
    str.at(str.size()/2) = '?';

    return retStr;
}


// randomly swap characters from the first half of the string with the second half
void shuffle(string& str) {
    for (size_t i=0; i<str.size()/2; ++i) {
        size_t index = random() % (str.size() / 2);

        char temp = str.at(index);
        str.at(index) = str.at(str.size()-1-index);
        str.at(str.size()-1-index) = temp;
    }
}


int main() {
    srand(time(NULL));

    cout << "Enter a string: ";
    string str;
    getline(cin, str);

    shuffle(str);
    cout << "String: " << str << endl;

    //cout << "Middle third: " << getMiddleThird(str) << endl;
    //cout << "String: " << str << endl;

    return 0;
}
