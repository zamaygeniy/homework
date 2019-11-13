#include <iostream>

using namespace std;

void swap(int&, int&);
void sort(int*, int);
int* allocateMemory(int);
void deleteMemory(int*);
void input_array(int*, int);
void output_array(int*, int);

void input_array(int* arrayref, int n)
{
	for (int i = 0; i < n; i++) cin >> arrayref[i];
}

void output_array(int* arrayref, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++) cout << arrayref[i] << " ";
}

void  deleteMemory(int* sourceArray)
{
	delete[]sourceArray;
}

int* allocateMemory(int n)
{
	return new int[n];
}

void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void sort(int* sourceArray, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (sourceArray[j] < sourceArray[min]) min = j;
		if (min != i)
			swap(sourceArray[i], sourceArray[min]);
	}
}

int main()
{
	int n;
	cin >> n;
	int* array = allocateMemory(n);
	int* arrayref = &array[0];


	input_array(arrayref, n);
	sort(array, n);
	output_array(arrayref, n);

}

