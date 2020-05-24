#include <iostream>

using namespace std;

/*В массиве целых чисел среди элементов, имеющих повторения,
 * оставить по одному, удалив повторяющиеся элементы и записав в новый массив их «перевертыши».
 * Оставшиеся элементы массива отсортировать по возрастанию
 * разности остатков от целочисленного деления на a и b соответственно(значения a и b ввести с клавиатуры)*/

void mergeSort(int*, int, int, int&, int&);
int reversing(int);
int key(int, int, int);
void merge(int*, int, int, int, int&, int&);
void work(int*, int*, int*, int, int&, int&);

int main() {

    int n;
    cout << "enter n" << endl;
    cin >> n;

    int* firstArray = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> firstArray[i];
    }

    int* secondArray = new int[n];
    int* needless = new int[n];
    int counter = 1;
    int needlessCounter = 0;

    work(firstArray, secondArray, needless, n, counter, needlessCounter);

    cout << "Array without extra elements" << endl;
    for (int i = 0; i < counter; ++i) {
        cout << secondArray[i] << " ";
    }
    cout << endl;

    cout << "Extra elements" << endl;
    for (int i = 0; i < needlessCounter; ++i) {
        cout << needless[i] << " ";
    }

    cout << endl << "Enter a, b: ";
    int a, b;
    cin >> a >> b;

    cout << "Sorted elements" << endl;
    mergeSort(secondArray, 0, counter - 1, a, b);

    for (int k = 0; k < counter; ++k) {
        cout << secondArray[k] << " ";
    }


    delete[]firstArray;
    delete[]secondArray;
    delete[]needless;
}


void work(int* firstArray, int* secondArray, int* needless, int n, int& counter, int& needlessCounter) {
   
    secondArray[0] = firstArray[0];
   
    for (int i = 1; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < counter; ++j) {
            if (firstArray[i] == secondArray[j]) {
                flag = false;
                j = counter;
            }
        }
        if (flag) {
            secondArray[counter] = firstArray[i];
            counter++;
        }
        else {
            needless[needlessCounter] = reversing(firstArray[i]);
            needlessCounter++;
        }
    }
}

int reversing(int number) {
    int t = 0;
    while (number) {
        int temp = number % 10;
        t = t * 10 + temp;
        number /= 10;
    }
    return t;
}

void mergeSort(int* array, int l, int r, int& a, int& b) {
    if (l < r)
    {
        int m = (l + r) / 2; // при больших значениях можно выйти за границы int
        mergeSort(array, l, m, a, b);
        mergeSort(array, m + 1, r, a, b);
        merge(array, l, m, r, a, b);
    }
}

void merge(int* array, int l, int m, int r, int& a, int& b) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* left = new int[n1];
    int* right = new int[n2];

    for (i = 0; i < n1; i++)
        left[i] = array[l + i];
    for (j = 0; j < n2; j++)
        right[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (key(left[i], a, b) <= key(right[j], a, b)) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }
}

int key(int number, int a, int b) {
    return (number % a - number % b);
}
