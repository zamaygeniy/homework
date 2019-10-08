#include <iostream> 


using namespace std;
int main()
{
	double i;
	cout << "enter the number from 1 to 99" << endl;
	while (true)
	{
		cin >> i;
		if (i > 0 && i < 100 && i == int(i))
			break;
		else
			cout << "error. Input correct number" << endl;
	}
	int a, b;
	a = int(i);

	b = a % 10;
	a /= 10;

	switch (a) {
	case 2: {
		cout << "twenty ";
		break;
	}
	case 3: {
		cout << "thirty ";
		break;
	}
	case 4: {
		cout << "forty ";
		break;
	}
	case 5: {
		cout << "fifty ";
		break;
	}
	case 6: {
		cout << "sixty ";
		break;
	}
	case 7: {
		cout << "seventy ";
		break;
	}
	case 8: {
		cout << "eighty ";
		break;
	}
	case 9: {
		cout << "ninety ";
		break;
	}
	case 1: {
		switch (b)
		{
		case 0: {
			cout << "ten";
			break;
		}
		case 1: {
			cout << "eleven";
			break;
		}
		case 2: {
			cout << "twelve";
			break;
		}
		case 3: {
			cout << "thirteen";
			break;
		}
		case 4: {
			cout << "fourteen";
			break;
		}
		case 5: {
			cout << "fifteen";
			break;
		}
		case 6: {
			cout << "sixteen";
			break;
		}
		case 7: {
			cout << "seventeen";
			break;
		}
		case 8: {
			cout << "eighteen";
			break;
		}
		default: cout << "nineteen";
		}
	}
	}
	if (a != 1 && b != 0) {
		switch (b)
		{
		case 1: {
			cout << "one";
			break;
		}
		case 2: {
			cout << "two";
			break;
		}
		case 3: {
			cout << "three";
			break;
		}
		case 4: {
			cout << "four";
			break;
		}
		case 5: {
			cout << "five";
			break;
		}
		case 6: {
			cout << "six";
			break;
		}
		case 7: {
			cout << "seven";
			break;
		}
		case 8: {
			cout << "eight";
			break;
		}
		default: cout << "nine";
		}
	}
}