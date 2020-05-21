#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {

    system("chcp 65001");

    DynamicArray a(2);
    a[0] = 1;
    a[1] = 2;
    DynamicArray b(a);
    cout << a[1] << b[1] << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
