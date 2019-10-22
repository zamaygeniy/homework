#include <iostream>

using namespace std;

void menu();
void menuText();
void workWithConsole();
short enterDigit();
int enterNumber();
int changeDigitInNumber(int, short, short);
void runTests();
void changeDigitInNumberTests(short, int, short, short, int);

int main()
{
	menu();
	return 0;
}

void menu()
{
	while (true)
	{
		char operation;
		menuText();
		cin >> operation;

		switch (operation)
		{
		case '1':
			workWithConsole();
			break;
		case '2':
			runTests();
			break;
		case '3':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}
		system("pause");
		system("cls");
	}
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}

void workWithConsole()
{
	int number = enterNumber();

	short digit = enterDigit(), digitchange = enterDigit();

	int result = changeDigitInNumber(number, digit, digitchange);

	cout << "   result = " << result << endl;
	///displayResult(number, digit, count);
}

short enterDigit()
{
	short digit;

	while (true)
	{
		cout << "Enter digit (0..9): ";
		cin >> digit;

		if (digit >= 0 && digit <= 9)
		{
			break;
		}

		cout << "Not digit! Try again." << endl;
		system("pause");
		system("cls");
	}

	return digit;
}

int enterNumber()
{
	int number;

	cout << "Enter number: ";
	cin >> number;

	return number;
}

int changeDigitInNumber(int number, short digit, short digitchange)
{
	int k;
	if (number < 0) k = 1;
	number = abs(number);

	int copynumber = number, diff = digit - digitchange;

	while (copynumber)
	{
		short rest = copynumber % 10;

		if (rest == digit)
		{
			number -= diff;
		}

		diff *= 10;
		copynumber /= 10;
	}
	
	if (k = 1)
		number = -number;
	if (number == 0 && digit == 0)
		number = digitchange;

	return number;
}

void runTests()
{
	int testNumber = 1;

	changeDigitInNumberTests(testNumber++, 657444, 4, 3, 657333);
	changeDigitInNumberTests(testNumber++, -100000, 0, 5, -155555);
	changeDigitInNumberTests(testNumber++, -1222442, 2, 4, -1444444);
	changeDigitInNumberTests(testNumber++, 1, 1, 0, 0);
	changeDigitInNumberTests(testNumber++, 0, 0, 1, 1);
}

void changeDigitInNumberTests(short testCaseNumber, int number, short digit, short digitchange, int expectedCount)
{
	int actual = changeDigitInNumber(number, digit, digitchange);
	if (actual == expectedCount)
	{
		cout << "Case #" << testCaseNumber << " is correct. :)" << endl;
	}
	else
	{
		cout << "Case #" << testCaseNumber << " IS NOT CORRECT. :(" << endl;
		cout << "\t actual = " << actual << ", but expected = " << expectedCount << endl;
	}
}
