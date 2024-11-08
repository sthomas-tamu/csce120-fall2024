#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstddef>

using std::size_t;

class DynamicIntArray {
  private:
    int* ary;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity = 0);
    void build_copy(const DynamicIntArray& src);

  public:
    // constructors, destructor, and assignment
    DynamicIntArray() : ary(nullptr), size(0), capacity(0) {}
    DynamicIntArray(size_t newSize, int val = 0);
    DynamicIntArray(const DynamicIntArray& src);
    ~DynamicIntArray();
    DynamicIntArray& operator=(const DynamicIntArray& src);

    // capacity methods
    size_t getSize() const { return size; }
    //size_t getCapacity() const { return capacity; }
    bool empty() const { return size == 0; }
    
    // modification methods
    const int& at(size_t index) const;
    int& at(size_t index);
    
    const int& operator[](size_t index) const { return ary[index]; }
    int& operator[](size_t index) { return ary[index]; }
    
    void push_back(int val);
};

#endif
