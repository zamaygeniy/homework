#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "enter n, x" << endl;
	double x;
	int n, k = 1;
	cin >> n >> x;
	double sum = 0, z = x;

	for (int i = 1; i <= n; i++)
	{
	    sum += k * x / i;
	    x *= z;
	    k *= -1;
	}
	cout << "sum = " << setprecision(15) << sum << endl;


}
