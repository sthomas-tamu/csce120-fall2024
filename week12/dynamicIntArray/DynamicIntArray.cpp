#include "DynamicIntArray.h"

#include <exception>

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
    } else {
        if(size < capacity) {
            ary[size] = value;
            size++;
        } else {
            //IN PROGRESS, START HERE
            this->resize(capacity*2);

        }
    }
}


