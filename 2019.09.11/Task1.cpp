#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter a, b, c " << endl;
	int a, b, c;
	cin >> a >> b >> c;
	int min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;

	cout << "min = " << min << endl;

}