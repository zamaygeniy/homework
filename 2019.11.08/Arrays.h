#if !defined ARRAYS_H
#define ARRAYS_H

using namespace std;


void Swap(int&, int&);
void Sort(int*, int);
int* AllocateMemory(int);
void DeleteMemory(int*);
void InputArray(int*, int);
void OutputArray(int*, int);
void CreateTest(int, int, int, int*);
void SortTests(int, int, int);

void CreateTest(int n1, int n2, int n, int* arrayref)
{
	for (int i = 0; i < n;)
	{
		bool flag = false;
		int a = n1 + rand() % (n2 - n1 + 1);
		
		for (int j = 0; j < i; j++)
			if (a == arrayref[j])
			{
				flag = true;
				break;
			}
		
		if (!flag)
		{
			arrayref[i] = a;
			i++;
		}
	}
}

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
			if (sourceArray[j] < sourceArray[min])
			{
				min = j;
			}
		
		if (min != i)
		{	
			Swap(sourceArray[i], sourceArray[min]);
		}
	}
}

void SortTests(int Testnumber, int n1, int n2)
{
	if (n1 > n2)
	{
		swap(n1, n2);
	}
	
	int n = abs(n1 - n2) + 1;

	int* TestArray = AllocateMemory(n);
	int* TestArrayref = &TestArray[0];

	CreateTest(n1, n2, n, TestArrayref);
	Sort(TestArrayref, n);
	
	bool flag = false;
	int k = n1;
	
	for (int i = 0; i < n; i++)
	{
		if (TestArray[i] != k)
		{
			flag = true;
			break;
		}
		k++;
	}

	if (!flag)
	{
		cout << endl << endl << "Case #" << Testnumber << " is correct. :)" << endl;
	}
	else
	{
		cout << "Case #" << Testnumber << " IS NOT CORRECT. :(" << endl;
	}
	
	cout << endl << "Actual:     ";
	for (int i = 0; i < n; i++)
	{
		cout << TestArray[i] << " ";
	}
	
	cout << endl << "Expected:   ";
	for (int i = n1; i <= n2; i++)
	{
		cout << i << " ";
	}
}

#endif
