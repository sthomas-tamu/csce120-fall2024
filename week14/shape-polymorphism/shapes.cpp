#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

struct Shape {
    virtual double area() const = 0;
    double perimeter() const { return 0; }
};

struct Square : public Shape {
    double length;
    virtual double area() const { return length*length; }
    double perimeter() const { return 4*length; }
};

struct Rectangle : public Square {
    double width;
    virtual double area() const { return length*width; }
    double perimeter() const { return 2*(length + width); }
};

int main() {
    Square square;
    square.length = 5;

    Rectangle rectangle;
    rectangle.length = 5;
    rectangle.width = 2;

    vector<Shape*> shapes;
    shapes.push_back(&rectangle);
    shapes.push_back(&square);

    cout << shapes[0]->area() << ", " << shapes[0]->perimeter() << endl;
    cout << shapes[1]->area() << ", " << shapes[1]->perimeter() << endl;


    cout << square.perimeter() << endl;
    cout << rectangle.perimeter() << endl;

    Shape s;
};
