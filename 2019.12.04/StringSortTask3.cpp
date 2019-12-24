#include <iostream>
#include "workWithString.h"

using namespace std;

char** createWords(char[], int&);
void displayWords(char**, int);
void SortString(char**, int&);
void swap(int*, int*);

int main()
{
	char source[] = "Lorem, Ipsum is simply dummy text "
		"of the printing and ,type setting !! industry."
		"Lorem @@@ Ipsum $$$$$ has 78 been ** the industry's standard";
	int k = 0;

	char** words = createWords(source, k);
	SortString(words, k);
	displayWords(words, k);

	return 0;
}

void displayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << words[i] << endl;
	}
}

void resetBuffer(char* buffer)
{
	int i = 0;
	while (buffer[i])
	{
		buffer[i] = '\0';
		i++;
	}
}

char** createWords(char source[], int& k)
{
	const int N = 256;
	char* bufferWords[N]; 
	int i = 0,
		j = 0;
	bool isWordCreating = false;
	k = 0;
	char buffer[N] = "";

	while (source[i])
	{
		if (isAlphabet(source[i]))
		{
			buffer[j] = source[i];
			j++;
			isWordCreating = true;
		}
		else
			if (isWordCreating)
			{
				bufferWords[k] = createString(buffer);
				resetBuffer(buffer);
				j = 0;
				k++;
				isWordCreating = false;
			}

		i++;
	}
	if (isWordCreating)
	{
		bufferWords[k] = createString(buffer);
		k++;
	}

	char** words = new char* [k];

	for (int i = 0; i < k; i++)
	{
		words[i] = bufferWords[i];
	}

	return words;
}

void SortString(char** words, int& k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = k - 1; j > i; j--)
		{
			if (compare(words[j - 1], getlength(words[j - 1]), words[j], getlength(words[j]), false))
			{
				swap(words[j], words[j - 1]);
			}
		}
	}
}

void swap(int* a, int* b)
{
	int* t = a;
	a = t;
	b = t;
}
