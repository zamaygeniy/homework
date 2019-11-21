#include <iostream>

using namespace std;

void Swap(int&, int&);
void Sort(int*, int);
int* AllocateMemory(int);
void DeleteMemory(int*);
void InputArray(int*, int);
void OutputArray(int*, int);

void InputArray(int* arrayref, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arrayref[i];
	}
}

void OutputArray(int* arrayref, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arrayref[i] << " ";
	}
}

void  DeleteMemory(int* sourceArray)
{
	delete[]sourceArray;
}

int* AllocateMemory(int n)
{
	return new int[n];
}

void Swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void Sort(int* sourceArray, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (sourceArray[j] < sourceArray[min]) 
				min = j;
		}
		
		if (min != i)
		{
			Swap(sourceArray[i], sourceArray[min]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* array = allocateMemory(n);
	int* arrayref = &array[0];
	
	InputArray(arrayref, n);
	Sort(array, n);
	OutputArray(arrayref, n);
}
