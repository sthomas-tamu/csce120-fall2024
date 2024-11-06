#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstddef>

using std::size_t;

class DynamicIntArray {
    int* ary;
    size_t size, capacity;

  public:
    //constructor
    DynamicIntArray() : ary(nullptr), size(0), capacity(0) {}

    bool empty() const;
    size_t getSize() const;

    int& at(size_t index) const;

    void push_back(int value);
};

#endif
