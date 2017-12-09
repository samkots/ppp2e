
#include "std_lib_facilities.h"


double ctok(double c)		// converts Celsius to Kelvin
{
	if (c < -273.15)
		error("temperature below absolute 0!");

	double k = c + 273.15;
	return k;
}


int main() try
{
	cout << "Enter temperature in celsius: ";
	double c = 0;		// declare input variable
	cin >> c;		// retrieve temperature to input variable

	double k = ctok(c);	// convert temperature
	cout << k << '\n';;	// print out temperature
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

