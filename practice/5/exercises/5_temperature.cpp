
#include "std_lib_facilities.h"


double ctok(double c)		// converts Celsius to Kelvin
{
	if (c < -273.15)
		error("ctok(): temperature below absolute 0!");

	double k = c + 273.15;
	return k;
}

double ktoc(double k)
{
	if (k < 0)
		error("ktoc(): temperature below absolute 0!");

	double c = k - 273.15;
	return c;
}


int main() try
{
	cout << "Enter temperature with unit (c, k): ";
	double t = 0;		// declare input variable
	char u = 0;		// c for Celsius k for Kelvin
	cin >> t >> u;		// retrieve temperature to input variable with unit

	switch (u) {
	case 'c':
	case 'C':
		cout << t << " Celsius == " << ctok(t) << " Kelvin(s).\n";	// convert temperature
		break;

	case 'k':
	case 'K':
		cout << t << " Kelvin(s) == " << ktoc(t) << " Celsius.\n";	// convert temperature
		break;

	default:
		error ("invalid unit");
	}
}
catch (runtime_error& x)
{
	cerr << "error: " << x.what() << endl;
	return -1;
}
catch (...)
{
	cerr << "error!\n";
	return -1;
}

