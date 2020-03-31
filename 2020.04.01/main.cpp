#include <iostream>

using namespace std;

/*В массиве целых чисел среди элементов, имеющих повторения,
 * оставить по одному, удалив повторяющиеся элементы и записав в новый массив их «перевертыши».
 * Оставшиеся элементы массива отсортировать по возрастанию
 * разности остатков от целочисленного деления на a и b соответственно(значения a и b ввести с клавиатуры)*/

void Merge(int* array, int l, int m, int r)
{
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

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int* array, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2; // при больших значениях можно выйти за границы int

        MergeSort(array, l, m);
        MergeSort(array, m + 1, r);
        Merge(array, l, m, r);
    }
}



int main() {

    int n;



    cout << "enter n" << endl;
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    MergeSort(array, 0, n - 1);

    for (int k = 0; k < n; ++k) {
        cout << array[k] << " ";
    }

    /* int* _array = new int[n];
     int counter = 1;
     _array[0] = array[0];

     int* needless = new int[n];
     int needless_counter = 0;

     for (int i = 1; i < n; ++i){
         bool flag = true;

         for (int j = 0; j < counter; ++j){
             if (array[i] == _array[j]){
                 flag = false;
                 j = counter;
             }
         }

         if (flag){
             _array[counter] = array[i];
             counter++;
         }
         else{
             needless[needless_counter] = reversing(array[i]);
             needless_counter++;
         }
     }

     for (int i = 0; i < counter; ++i) {
         cout << _array[i] << " ";
     }

     cout << endl;

     for (int i = 0; i < needless_counter; ++i) {
         cout << needless[i] << " ";
     }
    */


}
