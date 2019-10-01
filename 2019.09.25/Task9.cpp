#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "enter n, x" << endl;
	double x;
	int n, k = -1;
	cin >> n >> x;
	double sum = 0, l = 1, z = x;

	for (int i = 1; i <= n; i++)
	{
	  k *= -1;
		sum += k * x / l;
		x *= z * z;
		l += 2;
	}
	cout << "sum = " << setprecision(15) << sum << endl;


}
