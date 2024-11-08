#include "DynamicIntArray.h"

#include <stdexcept>

DynamicIntArray::DynamicIntArray(size_t newSize, int val) 
        : ary(nullptr), size(0), capacity(0) {
    resize(newSize);
    for (size_t i=0; i<newSize; ++i) {
        this->ary[i] = val;
    }
    this->size = newSize;
}

void DynamicIntArray::resize(size_t newCapacity) {
    // double current capacity if no new capacity given
    if(newCapacity == 0) {
        if(this->capacity == 0) 
            newCapacity = 1;
        else
            newCapacity = this->capacity * 2;
    }

    if(newCapacity <= this->capacity) {
        return;
    }

    int* newAry = new int[newCapacity];

    // copy
    for (size_t i=0; i<size; ++i) {
        newAry[i] = ary[i];
    }

    // delete
    delete [] ary;

    // fix
    ary = newAry;
    capacity = newCapacity;
}

const int& DynamicIntArray::at(size_t index) const {
    if (index >= this->size) {
        throw std::out_of_range("out of range");
    }
    return this->ary[index];
}

int& DynamicIntArray::at(size_t index) {
    if (index >= this->size) {
        throw std::out_of_range("out of range");
    }
    return this->ary[index];
}

void DynamicIntArray::push_back(int val) {
    if (this->size == this->capacity) {
        resize();
    }
    this->ary[size] = val;
    size++;
}

DynamicIntArray::~DynamicIntArray() {
    delete [] ary;
    size = 0;
    capacity = 0;
    ary = nullptr;
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& src) 
        : ary(nullptr), size(src.size), capacity(src.capacity) {
    build_copy(src);
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& src) {
    if (this != &src) {
        delete [] this->ary;
        this->size = src.size;
        this->capacity = src.capacity;
        build_copy(src);
    }
    return *this;
}

void DynamicIntArray::build_copy(const DynamicIntArray& src) {
    this->ary = new int[this->capacity];
    for (size_t i=0; i<this->size; ++i) {
        this->ary[i] = src.ary[i];
    }
}
