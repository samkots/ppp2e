
#include "std_lib_facilities.h"

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

// simple Date (control access)
class Date {
private:
	int y, m, d;
public:
	Date(int y, int m, int d);	// check for valid date and initialize
	void add_day(int n);		// increase the Date by n days
	int month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }
};

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd)
	:y(yy), m(mm), d(dd)
{
	if (!is_date_valid(y, m, d))
		error("Invalid date");
}

//------------------------------------------------------------------------------

void Date::add_day(int n)
{
	d += n;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}

//------------------------------------------------------------------------------

int main()
try
{
	Date today(1978, 6, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "today: " << today << '\n'
		<< "tomorrow: " << tomorrow << '\n';

	Date test(2004, 13, -5);
}
catch(const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

