#include <iostream>

using namespace std;

int getLength(const char*);
bool isDigit(const char);
void reverseNumber(int&);
int parseStringToSumWithSigned(const char*);
void parseStringToSumWithSignedTest();


int main()
{
	parseStringToSumWithSignedTest();
	system("pause");
	return 0;
}

/*
int* arrayCreating(const char* source, int length)
{
	for (int i = 0; i < length; i++)
	{
		bool isdigit = isDigit(source[i]);

		if (isdigit && isCreating)
		{
			numbers[j] = numbers[j] * 10 + (source[i] - '0');
			counter++;
		}
		else
		{
			if (isdigit)
			{
				j++;
				numbers[j] = source[i] - '0';
				isCreating = true;
			}
			else
				if (isCreating && source[i - counter - 1] == '-')
				{
					numbers[j] = -numbers[j];
					isCreating = false;
					counter = 1;
				}
				else
				{
					isCreating = false;
					counter = 1;
				}
		}
	}
}
*/

int parseStringToSumWithSigned(const char* source)
{
	int length = getLength(source);
	bool isCreating = false;

	int* numbers = new int[length / 2 + 1];
	int j = -1, counter = 1;

	for (int i = 0; i < length; i++)
	{
		bool isdigit = isDigit(source[i]);

		if (isdigit && isCreating)
		{
			numbers[j] = numbers[j] * 10 + (source[i] - '0');
			counter++;
		}
		else
		{
			if (isdigit)
			{
				j++;
				numbers[j] = source[i] - '0';
				isCreating = true;
			}
			else
				if (isCreating && source[i - counter - 1] == '-')
				{
					numbers[j] = -numbers[j];
					isCreating = false;
					counter = 1;
				}
				else
				{
					isCreating = false;
					counter = 1;
				}
		}
	}

	int sum = 0;
	for (int i = 0; i <= j; i++)
		sum += numbers[i];

	return sum;
}

bool isDigit(const char symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return true;
	else
		return false;
}

int getLength(const char* source)
{
	int length = 0;

	while (source[length])
	{
		length++;
	}

	return length;
}

void parseStringToSumWithSignedTest()
{
	bool result = parseStringToSumWithSigned("1235+-8+*** 90") == 1317;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithSigned("1235+-8+* 4** -22--- 9") == 1218;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	//etc
}