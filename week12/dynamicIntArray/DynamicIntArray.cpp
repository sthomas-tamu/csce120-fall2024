#include "DynamicIntArray.h"

bool DynamicIntArray::empty() const {
    return size == 0;
}

size_t DynamicIntArray::getSize() const {
    return this->size;
}

int& DynamicIntArray::at(size_t index) const {
    return ary[index];
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


