
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// simple Date
// guarantee initialization with constructor
// provide some notational convenience
struct Date {
	int y, m, d;			// year, month, day
	Date(int y, int m, int d);	// check for valid date and initialize
	void add_day(int n);		// increase the Date by n days
};

//------------------------------------------------------------------------------

bool is_date_valid(int y, int m, int d)
{
	// assume the year is valid
	if (d < 0)
		return false;

	if (m < 0 || m > 12)
		return false;

	int number_of_days = 31;
	switch (m) {
	case 4: case 6:
	case 9: case 11:
		number_of_days = 30;
		break;

	case 2:
		number_of_days = 28;
		break;
	}

	if (d > number_of_days)
		return false;

	return true;
}

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd)
	:y(yy), m(mm), d(dd)
{
	if (!is_date_valid(y, m, d))
		error("Invalid date");
}

//------------------------------------------------------------------------------

Date add_day(const Date& d, int n)
{
	Date dd = d;
	dd.d += n;
	return dd;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')';
}

//------------------------------------------------------------------------------

int main()
try
{
	Date today(1978, 6, 25);
	Date tomorrow = add_day(today, 1);

	cout << "today: " << today << '\n'
		<< "tomorrow: " << tomorrow << '\n';

	Date test(2004, 13, -5);
}
catch(const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

