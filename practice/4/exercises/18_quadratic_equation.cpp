
#include "std_lib_facilities.h"


int main()
{
	cout << "For solving quadratic equation like ax*x + bx +c = 0, enter a, b and c...\n";
	double a, b, c;
	cin >> a >> b >> c;

	double x1 = ( -1 * b + sqrt( b * b - 4  * a * c )) / (2 * a);
	double x2 = ( -1 * b - sqrt( b * b - 4  * a * c )) / (2 * a);

	cout << "x1: " << x1 << '\n';
	cout << "x2: " << x2 << '\n';
}

