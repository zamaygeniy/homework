#if !defined ARRAYS_H
#define ARRAYS_H

using namespace std;

char* AllocateMemory(int);
void DeleteMemory(char*);
void InputArray(char*, int);
void OutputArray(char*, int);

void InputArray(char* arrayref, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arrayref[i];
	}
}

void OutputArray(char* arrayref, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arrayref[i];
	}
}

void  DeleteMemory(char* sourceArray)
{
	delete[]sourceArray;
}

char* AllocateMemory(int n)
{
	return new char[n];
}

int Searching(char* string, int n, char* substring, int subn)
{
	for (int i = 0; i < n; i++)
	{
		if (string[i] == substring[0])
		{
			bool flag = true;
			int l = i;

			for (int j = 0; j < subn ;j++)
			{
				if (substring[j] != string[l])
				{
					flag = false;
					break;
				}
				l++;
			}

			if (flag == true)
			{
				return i;
			}

		}
	}

	return -1;
}

#endif