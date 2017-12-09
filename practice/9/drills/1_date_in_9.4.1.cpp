
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// simple Date (too simple actually)
struct Date {
	int y;		// year
	int m;		// month in year
	int d;		// day of month
};

//------------------------------------------------------------------------------

Date init_date(int y, int m, int d)
{
	Date dd;
	dd.y = y;
	dd.m = m;
	dd.d = d;

	return dd;
}

//------------------------------------------------------------------------------

bool is_date_valid(const Date& dd)
{
	// assume the year is valid
	if (dd.d < 0)
		error("Invalid day");

	if (dd.m < 0 || dd.m > 12)
		error("Invalid month");

	int number_of_days = 31;
	switch (dd.m) {
	case 4: case 6:
	case 9: case 11:
		number_of_days = 30;
		break;

	case 2:
		number_of_days = 28;
		break;
	}

	if (dd.d > number_of_days)
		error ("Invalid day");
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
	Date today;
	today.d = 25;
	today.m = 6;
	today.y = 1978;

	Date tomorrow = add_day(today, 1);

	cout << "today: " << today << '\n'
		<< "tomorrow: " << tomorrow << '\n';

	Date test;
	test.y = 2004;
	test.m = 13;
	test.d = -5;
	is_date_valid(test);
	cout << "test: " << test << '\n';
}
catch(const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

