#include "DynamicIntArray.h"

#include <stdexcept>

DynamicIntArray::DynamicIntArray(size_t newSize, int init_value) : size(newSize), capacity(newSize) {
    ary = new int[capacity];
    for(size_t i=0; i<size; ++i) {
        ary[i] = init_value;
    }

}


bool DynamicIntArray::empty() const {
    return size == 0;
}

size_t DynamicIntArray::getSize() const {
    return this->size;
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

void DynamicIntArray::push_back(int value) {
    if(ary == nullptr) {
        ary = new int[1];
        ary[0] = value;
        size = 1;
        capacity = 1;
    } else {
        if(size >= capacity) {
            this->resize(capacity*2);
        }
        ary[size] = value;
        size++;
    }
}

void DynamicIntArray::resize(size_t newCapacity) {
    if(newCapacity > capacity) {
        int* newAry = new int[newCapacity];
        for(size_t i=0; i<size; ++i) {
            newAry[i] = ary[i];
        }
        delete [] ary;
        ary = newAry;
        newAry = nullptr;
        capacity = newCapacity;
    }
}




