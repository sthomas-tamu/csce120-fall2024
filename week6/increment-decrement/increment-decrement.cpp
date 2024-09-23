#include <iostream>
#include <sstream>

using std::cout, std::endl;

int main() {
    // demo pre-increment and post-increment
    int i = 3;
    int j = 7;

    int p = 2 * i++;
    int w = 2 * ++j;

    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << endl;
    cout << "p: " << p << endl;
    cout << "w: " << w << endl;

    return 0;
}
