#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	cout << "enter n, x" << endl;
	double x;
	int n;
	cin >> n >> x;

	double k = x, sum = -x;
	for (int i = 1; i <= n; i++)
	{
		sum -= k / i;
		k *= x;
	}
	cout << "sum = " << sum << endl;


}


