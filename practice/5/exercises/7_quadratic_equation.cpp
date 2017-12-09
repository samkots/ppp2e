
#include "std_lib_facilities.h"


//
// solving quadratic equations
// of the form:
// axx + bx + c = 0
//

void print_roots(double a, double b, double c)
{
	double bb_minus_4ac = b * b - (4 * a * c);
	if (bb_minus_4ac < 0) {
		error("The equation doesn't have real roots.");
	}

	double x1 = ( -b + sqrt(bb_minus_4ac) ) / (2 * a);
	double x2 = ( -b - sqrt(bb_minus_4ac) ) / (2 * a);

	cout << "x1: " << x1 << endl;
	cout << "x2: " << x2 << endl;
}

int main()
try
{
	cout << "Enter a, b and c: ";
	double a, b, c;
	cin >> a >> b >> c;

	print_roots(a, b, c);
}
catch (runtime_error& x)
{
	cerr << "error: " << x.what() << endl;
}


