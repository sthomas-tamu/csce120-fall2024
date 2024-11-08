#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstddef>

using std::size_t;

class DynamicIntArray {
    int* ary;
    size_t size, capacity;

    void resize(size_t newCapacity);

  public:
    //constructor
    DynamicIntArray() : ary(nullptr), size(0), capacity(0) {}
    DynamicIntArray(size_t newSize, int init_value = 0);

    bool empty() const;
    size_t getSize() const;

    const int& at(size_t index) const;
    int& at(size_t index);

    void push_back(int value);
};

#endif
