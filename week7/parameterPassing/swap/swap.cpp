#include <iostream>

using std::cout, std::endl;

// update this function so the swap persists outside the function 
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "in swap: " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

int main() {
    int x = 11;
    int y = 7;
    
    cout << "before swap: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    swap (x, y);

    cout << "after swap: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}
