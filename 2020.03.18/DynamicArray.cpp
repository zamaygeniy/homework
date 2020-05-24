#include <istream>
#include "DynamicArray.h"

void DynamicArray::NewSize(int newSize){

    capacity = newSize * 2;
    int *newData = new int[capacity];
    for (int i = 0; i < size; ++i) {
        *(newData + i) = *(data + i);
    }
    delete[] data;

    size = newSize;
    data = newData;

}

DynamicArray::DynamicArray(int size) {

    this->size = size;
    capacity = size * 2;
    data = new int[capacity];

}

DynamicArray::DynamicArray(int size, int value): DynamicArray(size) {

    for (int i = 0; i < size; ++i) {
        *(data + i) = value;
    }

}

DynamicArray::DynamicArray(const DynamicArray &array) {

    size = array.size;
    capacity = size * 2;
    data = new int[capacity];

    for (int i = 0; i < size; ++i) {
        *(data + i) = *(array.data + i);
    }

}

DynamicArray &DynamicArray::operator=(const DynamicArray &array) {

    if (array.size > size) {
        NewSize(array.size);
    }

    for (int i = 0; i < size; ++i) {
        *(data + i) = *(array.data + i);
    }

    return *this;

}

int &DynamicArray::operator[](int index) {

    return *(data + index);

}

std::istream &operator>>(std::istream &in, DynamicArray &array) {

    int value = 0;
    int i = 0, cap = array.capacity;

    while (in >> value) {

        if (i >= cap) {
            array.NewSize(cap);
            cap = array.capacity;
        }

        *(array.data + i++) = value;

    }

    return in;

}

std::ostream &operator<<(std::ostream &out, const DynamicArray &array) {

    out << '[';
    for (int i = 0; i < array.size; ++i) {
        out << *(array.data + i);
        if (i + 1 < array.size) {
            out << ", ";
        }
    }
    out << ']';

    return out;

}

DynamicArray operator+(DynamicArray lhs, const DynamicArray &rhs) {

    if (lhs.size < rhs.size) {
        lhs.NewSize(rhs.size);
    }

    for (int i = 0; i < lhs.size; ++i) {
        *(lhs.data + i) += *(rhs.data + i);
    }

    return lhs;

}
