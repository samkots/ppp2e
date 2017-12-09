
#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Reading {		// a temperature reading
	int hour;		// hour after midnight [0:23]
	double temperature;	// in Faherenheit
	char unit;		// c for Celsius and f for Faherenheit
};

//------------------------------------------------------------------------------

// writes a Reading in format: (hour, temperature, unit)
// example: (4, 66.60, f) (5, 23, c)
ostream& operator << (ostream& os, const Reading& r);

// reads a Reading in format: (hour, temperature, unit)
// example: (4, 66.60, f) (5, 23, c)
istream& operator >> (istream& is, Reading& r);

bool operator < (const Reading& a, const Reading& b);

double celsius_2_fahrenheit(double celsius);

//------------------------------------------------------------------------------

