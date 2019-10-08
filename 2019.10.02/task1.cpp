#include <iostream>

using namespace std;
int main()
{
	double i;
	cout << "enter the number from 1 to 10" << endl;
	while (true)
	{
		cin >> i;
		if (i > 0 && i < 11 && i == int(i))
			break;
		else
			cout << "error. Input correct number" << endl;
	}

	i = ++i / 2;
	switch (int(i))
	{
		case 1: 
		{
			cout << "was absent" << endl;
			break;
		}
		case 2:
		{
			cout << "not satisfactorily" << endl;
			break;
		}
		case 3:
		{
			cout << "satisfactorily" << endl;
			break;
		}
		case 4:
		{
			cout << "good" << endl;
			break;
		}
		case 5:
		{
			cout << "excellent" << endl;
		}

	}
	
}

