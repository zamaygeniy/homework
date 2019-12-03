#include <iostream>

using namespace std;

int main()
{
	int size = 1;
	char* str = new char[size];

	char value;
	int i = 0;

	while (cin.get(value))
	{
		if (value == '\n')
		{
			break;
		}

		i++;
		if (i >= size)
		{
			int newsize = size * 2;
			char* newstr = new char[newsize];

			for (int j = 0; j < size; j++)
			{
				newstr[j] = str[j];
			}
			delete[] str;
			size = newsize;
			str = newstr;
		}
		str[i] = value;
	}

	for (int j = 1; j <= i; j++)
		cout << str[j];

	return 0;
}

