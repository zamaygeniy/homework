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

	cout << "e^x = " << setprecision(15) << exp(x) << endl;

	double k = x, sum = 1, l = 1;
	for (int i = 1; i <= n; i++)
	{
		l *= i;
		sum += k / l;
		k *= x;
	}
	cout << "sum = " << sum << endl;


}


