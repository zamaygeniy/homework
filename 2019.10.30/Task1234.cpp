#include <iostream>
#include <cmath>

using namespace std;

void InputArray(int* arrayref)
{
	for (int i = 0; i < 10; i++)
	{
		cin >> arrayref[i];
	}
}

void Task1(int* arrayref)
{
	int j = 9;
	for (int i = 0; i < 5; i++)
	{
		arrayref[i] += arrayref[j];
		arrayref[j] = arrayref[i] - arrayref[j];
		arrayref[i] -= arrayref[j];
		j--;
	}
}

void Task2(int* arrayref)
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{	
		if (arrayref[i] < 0)
		{
			arrayref[i] = 0;
		}
		
		for (int j = 2; j <= sqrt(arrayref[i]); j++)
		{
			if (arrayref[i] % j == 0)
			{
				k++;
			}
		}
		
		if (k > 0)
		{
			arrayref[i] = 0;
		}
		
		k = 0;
	}

	for (int i = 0; i < 10; i++)
	{
		if (arrayref[i] == 0) 
		{
		}
		else
		{
			cout << arrayref[i] << "  ";
		}
	}
}

void Task3(int* arrayref)
{
	cout << "enter n = ";
	int n;
	cin >> n;
	int i = 9;
	
	while (true)
	{
		if (arrayref[i] >= n)
		{
			i--;
		}
		else
		{
			break;
		}
	}

	cout << "number of elements = " << i + 1;


}

void Task4(int* arrayref)
{
	int equal = 0, more = 0, less = 0;
	
	for (int i = 1; i < 10; i++)
	{
		if (arrayref[i] == arrayref[i - 1] && equal == 0)
		{
			equal++;
		}
		else
		{
			if (arrayref[i] < arrayref[i - 1] && less == 0)
			{
				less++;
			}
			else
			{
				if (arrayref[i] > arrayref[i - 1] && more == 0)
				{
					more++;
				}
			}
		}
	}
}

int main()
{
	int array[10];
	int* arrayref = &array[0];
	InputArray(arrayref);
	Task3(arrayref);
}
