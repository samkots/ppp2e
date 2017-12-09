
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Reading {		// a temperature reading
	int hour;		// hour after midnight [0:23]
	double temperature;	// in Faherenheit
};

//------------------------------------------------------------------------------

ostream& operator << (ostream& os, const Reading& r)
	// writes a Reading in format: (hour, temperature)
	// example: (4, 66.60)
{
	return os << '(' << r.hour << ", " << r.temperature << ')';
}

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Reading& r)
	// reads a Reading in format: (hour, temperature)
	// example: (4, 66.60)
{
	char ch = 0;
	is >> ch;
	if (ch != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char term = 0;
	int h;
	double t;
	is >> h >> ch >> t >> term;
	if (!is || ch != ',' || term != ')')
		error("bad reading");

	r.hour = h;
	r.temperature = t;
	return is;
}

//------------------------------------------------------------------------------

bool operator < (const Reading& a, const Reading& b)
{
	return a.temperature < b.temperature;
}

//------------------------------------------------------------------------------

