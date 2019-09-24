#include "pch.h"
#include <iostream>

using namespace std;
int main()
{
	cout << "Enter a, b, c" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b > c && b + c > a && a + c > b)
		if (a == b && b == c)
			cout << "equilateral triangle" << endl;
		else
			if (a == b || a == c || b == c)
				cout << "isosceles triangle" << endl;
			else
				cout << "versatile triangle" << endl;
	else
		cout << "such triangle doesn't exist" << endl;

	return 0;
}
