#include <iostream>

using namespace std;

int* encoding(char const*, char const*);
char* decoding(int const*, char const*, int);
char* createRule(const char*);
void createRuleTest();
void encodingTests();
void decodingTests();
bool equals(const char*, const char*);
bool equals(const int*, const int*, int);
int getlength(const char*);

int main()
{
	createRuleTest();
	encodingTests();
	decodingTests();
	system("pause");
}


char* createRule(const char* source, int shift)
{
	int length = getlength(source), j = length - 1;;

	char* rule = new char[length];

	for (int i = 0; i < length / 2 + 1; i++)
	{
		rule[i] = source[j];
		rule[j] = source[i];
		j--;

	}

	int n = length;
	/*for (int i = 0; i < shift; i++)
	{
		char temp = rule[--length];
		while (length > 0)
			rule[length--] = rule[length - 1];  // сдвиг вправо
		rule[0] = temp;

		length = n;
	}*/

	for (int j = 0; j < shift; j++)
	{
		int temp = rule[0];
		for (int i = 1; i < length; i++)
			rule[i - 1] = rule[i];
		rule[length - 1] = temp;
	}
	return rule;
}

char* createRule(const char* source)
{
	int length = getlength(source), j = length - 1;

	char* rule = new char[length];

	for (int i = 0; i < length / 2 + 1; i++)
	{
		rule[i] = source[j];
		rule[j] = source[i];
		j--;
	}

	return rule;
}

int getlength(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (source[length])
	{
		length++;
	}
	return length;
}

int* encoding(const char* source, const char* rule)
{
	int n = getlength(source), j;
	int* encode = new int[n];

	for (int i = 0; i < n; i++)
	{
		if (source[i] >= 'A' && source[i] <= 'Z' || source[i] >= 'a' && source[i] <= 'z')
		{
			j = 0;
			while (true)
			{
				if (source[i] == rule[j] || source[i] == rule[j] + 32)
				{
					j++;
					break;
				}
				j++;
			}
		}
		else
		{
			j = int(source[i]);
		}
		encode[i] = j;
	}

	return encode;
}

char* decoding(const int* source, const char* rule, int n)
{
	char* decode = new char[n];
	for (int i = 0; i < n; i++)
	{
		if (source[i] >= 1 && source[i] <= 26)
		{
			decode[i] = rule[source[i]-1];
		}
		else
			decode[i] = source[i];
	}
	
	return decode;
}

bool equals(const char* lhs, const char* rhs)
{
	int i = 0;
	while (lhs[i] && rhs[i])
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
		i++;
	}

	return true;
}

bool equals(const int* lhs, const int* rhs, int n)
{
	int i = 0;

	for (int i = 0; i < n; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

void createRuleTest()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* actual = createRule(source);

	const char* expected = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

	cout << "Test for creation rule " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;

	//delete[] actual;

	actual = createRule(source, 5);
	expected = "UTSRQPONMLKJIHGFEDCBAZYXWV";

	cout << "Test for creation rule " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;

	//delete[] actual;
}

void encodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	int* encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode, new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, 10) ? "Passed." : "Failed.") << endl;

	delete[] encode;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode, new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, 29) ? "Passed." : "Failed.") << endl;

	delete[] encode;

	//delete[] rule;

	// new shift rule

	rule = createRule(source, 5);

	encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode, new int[10]{ 10, 17, 21, 4, 8, 32, 19, 43, 43, 33 }, 10) ? "Passed." : "Failed.") << endl;

	delete[] encode;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode, new int[29]{ 19, 7, 15, 13, 2, 7, 44, 32, 17, 4, 15, 7, 32, 3, 1, 9, 33, 32, 40, 18, 17, 3, 19, 21, 4, 2, 17, 3, 41 }, 29) ? "Passed." : "Failed.") << endl;

	delete[] encode;

	//delete[] rule;
}

void decodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	char* decode = decoding(new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, rule, 10);

	cout << "Test for decoding " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	decode = decoding(new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, rule, 29);

	cout << "Test for decoding " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	//delete[] rule;

	// new shift rule

	rule = createRule(source, 5);

	decode = decoding(new int[10]{ 10, 17, 21, 4, 8, 32, 19, 43, 43, 33 }, rule, 10);

	cout << "Test for decoding " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	decode = decoding(new int[29]{ 19, 7, 15, 13, 2, 7, 44, 32, 17, 4, 15, 7, 32, 3, 1, 9, 33, 32, 40, 18, 17, 3, 19, 21, 4, 2, 17, 3, 41 }, rule, 29);

	cout << "Test for decoding " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;

	delete[] decode;

	delete[] rule;

}