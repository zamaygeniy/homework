#ifndef DELETE_DYNAMICARRAY_H
#define DELETE_DYNAMICARRAY_H

class DynamicArray {

public:
    explicit DynamicArray(int size = 10);
    DynamicArray(int size, int value);
    DynamicArray(const DynamicArray &array); // copy array
    DynamicArray &operator= (const DynamicArray &array);
    int &operator[] (int index);

    friend std::istream &operator>>(std::istream &in, DynamicArray &array);
    friend std::ostream &operator<<(std::ostream &out, const DynamicArray &array);

    friend DynamicArray operator+(DynamicArray lhs, const DynamicArray &rhs);

private:

    int* data;
    int size;
    int capacity;
    void NewSize(int newSize);
};


#endif //DELETE_DYNAMICARRAY_H
