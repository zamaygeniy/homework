#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	cout << "enter n, x(radians)" << endl;
	double x;
	int n, k = 0;
	cin >> n >> x;

	double sum = 0, l = 1;

	for (int i = 0; i < n; i++)
	{
	    k++;
		l *= (i+1);
		sum += 1 + sin(k*x) / l;

	}
	cout << "sum = " << setprecision(15) << sum << endl;


}
