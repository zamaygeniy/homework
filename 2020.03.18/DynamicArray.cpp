//
// Created by 100nout.by on 016 16.03.20.
//

#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray(int i){
    size = i;
    if (size != 0)
        array = new double[size];
    else
        array = nullptr;
}

DynamicArray::DynamicArray(DynamicArray& other)
{
    this->SetSize(other.GetSize());
    array = new double[GetSize()];
    for (int i = 0; i < GetSize(); i++)
        array[i] = other[i];
}

int DynamicArray::GetSize() const
{
    return size;
}

void DynamicArray::SetSize(int size) {

        if (size < 0)
            throw  std :: invalid_argument ("size < 0");
        this->size = size;
}

void DynamicArray::Display() const
{
    for (int i = 0; i < GetSize(); i++)
    {
        std::cout << array[i] << " ";
    }
}

double& DynamicArray::operator[](const int index)
{
    if (CheckIndex(index))
        return array[index];
    else
        throw std::out_of_range("Wrong index");
}

DynamicArray::~DynamicArray()
{
    delete[] array;
    SetSize(0);
    std::cout << "Array is no more";
}

bool DynamicArray::CheckIndex(int index) {
    if ((index < 0) || (index >= size))
        return false;
    return true;
}

DynamicArray::DynamicArray(){
    size = 0;
}

double& DynamicArray::operator=(const DynamicArray & _array) {
    if(count > 0)
        delete[] array;
    size = _array.GetSize();
    array = new double[size];
    for (int i = 0; i < size; i++)
        array[i] = _array[i];
}

