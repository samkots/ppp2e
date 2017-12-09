
//------------------------------------------------------------------------------

#include "Reading.h"

//------------------------------------------------------------------------------

ostream& operator << (ostream& os, const Reading& r)
	// writes a Reading in format: (hour, temperature, unit)
	// example: (4, 66.60, f) (5, 23, c)
{
	return os << '(' << r.hour << ", " << r.temperature << ", " << r.unit << ')';
}

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Reading& r)
	// reads a Reading in format: (hour, temperature, unit)
	// example: (4, 66.60, f) (5, 23, c)
{
	char ch = 0;
	is >> ch;
	if (ch != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char term = 0;
	char ch2 = 0;
	char unit = 0;
	int h;
	double t;
	is >> h >> ch >> t >> ch2 >> unit >> term;	// reads "4, 60, f)"
	if (!is || ch != ',' || ch2 != ',' || (unit != 'f' && unit != 'c') || term != ')')
		error("bad reading");

	r.hour = h;
	r.temperature = t;
	r.unit = unit;

	return is;
}

//------------------------------------------------------------------------------

bool operator < (const Reading& a, const Reading& b)
{
	double temp_a = (a.unit == 'f') ?  a.temperature : celsius_2_fahrenheit(a.temperature);
	double temp_b = (b.unit == 'f') ?  b.temperature : celsius_2_fahrenheit(b.temperature);
	return temp_a < temp_b;
}

//------------------------------------------------------------------------------

double celsius_2_fahrenheit(double celsius)
{
	return celsius * 9.0 / 5 + 32;
}

//------------------------------------------------------------------------------

