#include <iostream>

using namespace std;
int main()
{
	double i;
	cout << "enter the number from 1 to 12" << endl;
	while (true)
	{
		cin >> i;
		if (i > 0 && i < 13 && i == int(i))
			break;
		else
			cout << "error. Input correct number" << endl;
	}

	i = float(i / 3) + 1;
	switch (int(i))
	{
		case 2:
		{
			cout << "spring" << endl;
			break;
		}
		case 3: 
		{
			cout << "summer" << endl;
			break;
		}
		case 4:
		{
			cout << "fall" << endl;
			break;
		}
		default: cout << "winter" << endl;
	}	
}

