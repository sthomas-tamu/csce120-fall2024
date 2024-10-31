#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

int main() {
    // vector of int pointers
    vector<int*> vi;

    // put new items in vector  
    for (size_t i=0; i<10; ++i) {
        vi.push_back(new int(i+1));
    }
  
    // print out the vector
    for (size_t i=0; i<vi.size(); ++i) {
        cout << *(vi.at(i)) << endl;
    }
  
    // clear the vector by removing the first element each time until the vector is empty
    while (!vi.empty()) {
        delete vi.at(0);
        vi.erase(vi.begin());
    }
}
