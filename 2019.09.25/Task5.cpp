#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "enter n, x" << endl;
	double x;
	int n, k = 1, j = 2;;
	cin >> n >> x;
	double sum = 1, l = 2, z = x;

	for (int i = 1; i <= n; i++)
	{
	  x *= z;
	  k *= -1;
		sum += k * x / l;
		l *= (j+1)*(j+2);
		j += 2;
		x *= z;
	}
	cout << "sum = " << setprecision(15) << sum << endl;


}
