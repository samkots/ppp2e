
#include "std_lib_facilities.h"


double ctof(double c)
{
	return c * 9.0 / 5 + 32;
}

double ftoc(double f)
{
	return (f - 32) * 5.0 / 9;
}

int main() try
{
	cout << "Enter temperature with unit(c or f): ";

	double temp;
	char unit = 0;
	cin >> temp >> unit;

	switch (unit) {
	case 'c':
	case 'C':
		cout << temp << " Celcius == " << ctof(temp) << " Fahrenheit(s)\n";
		break;

	case 'f':
	case 'F':
		cout << temp << " Fahrenheit == " << ftoc(temp) << " Celcius\n";
		break;

	default:
		error("invalid unit");
	}
}
catch (runtime_error& x)
{
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (...)
{
	cerr << "error!\n";
	return -1;
}

