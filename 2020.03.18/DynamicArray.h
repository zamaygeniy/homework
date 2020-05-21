
#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H


class DynamicArray {
public:
    DynamicArray();
    DynamicArray(int);
    DynamicArray(DynamicArray&);
    ~DynamicArray();
    inline int GetSize() const;
    void Display() const;
    double& operator[](const int);
private:
    double* array;
    int size;
    bool CheckIndex(int);
    inline void SetSize(int);
};


#endif //DYNAMICARRAY_DYNAMICARRAY_H
