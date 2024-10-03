#include <iostream>

using std::cout, std::endl;

int main() {
    // create a cstring with 3 elements
    char* str = new char[3];

    // initialize str
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';
    cout << "cstring is '" << str << "'" << endl;

    // count str's size by iterating through it using pointers
    unsigned int cnt = 0;
    char* iter = str; // start at the beginning of the cstring
    while (*iter != '\0') { // while haven't reached the end
        cnt++;
        iter++; // move the pointer (iterator) to the next item in the cstring (also works for other types of arrays)
    }

    cout << "It has " << cnt << " characters." << endl;

    // release memory for str;
    delete[] str;
}
