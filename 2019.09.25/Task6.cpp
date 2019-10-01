#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "enter n, x" << endl;
	double x;
	int n, j = 1;;
	cin >> n >> x;
	double sum = 0, l = 1, z = x;

	for (int i = 1; i <= n; i++)
	{
	 	sum += x / l;
		x *= z * z;
		l *= (j+1)*(j+2);
		j += 2;
	}
	cout << "sum = " << setprecision(15) << sum << endl;


}
