#include <iostream>

using std::cout, std::endl;

int main(int argc, char *argv[]) {
    // argc = the number of cstrings on the commandline
    // argv = the array of cstrings on the commandline,
    //         the first one is always the executable name
    // sometimes you'll see (int argc, char** argv)
  
    cout << "executable: " << argv[0] << endl;
  
    cout << "there are " << (argc-1) << " input parameters" << endl;
  
    // print remaining parameters
    if (argc > 1) {
        cout << "they are";
        for (unsigned int i=1; i<argc; i++) {
            cout << " " << argv[i];
        }
        cout << endl;
    }

    return 0;
}
