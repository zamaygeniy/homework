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

void Replacement(char* str, int n, char* repstr, int repstrsize, int* index, int newsize, int subn)
{
	char* newstr = AllocateMemory(newsize);
	int l = 0;

	for (int i = 0; i < n; i++)
	{
		if (index[i] == 0)
		{
			newstr[l] = str[i];
			l++;
		}
		else
		{
			for (int j = 0; j < repstrsize; j++)
			{
				newstr[l] = repstr[j];
				l++;
			}
			i += subn - 1;
		}
	}

	for (int i = 0; i < newsize; i++)
	{
		cout << newstr[i];
	}
	DeleteMemory(newstr);
}

void SearchAndReplace(char* string, int n, char* substring, int subn, char* repstr, int repstrsize)
{
	int* index = new int[n];
	int* indexref = &index[0];

	for (int i = 0; i < n; i++)
	{
		index[i] = 0;
	}

	int counter = 0;

	for (int i = 0; i < n; i++)
	{
		if (string[i] == substring[0])
		{
			bool flag = true;
			int l = i;

			for (int j = 0; j < subn; j++)
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
				index[i] = 1;
				i += subn - 1;
				counter++;
			}

		}
	}

	counter = n + (repstrsize - subn) * counter;

	Replacement(string, n, repstr, repstrsize, indexref, counter, subn);
}

#endif