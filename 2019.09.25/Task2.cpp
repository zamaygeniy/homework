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

	double sum = 0, l = 1;
	x = sqrt(abs(x));
	for (int i = 0; i < n; i++)
	{
		l *= (i+1);
		sum += 1. / l + x;

	}
	cout << "sum = " << setprecision(15) << sum << endl;


}
