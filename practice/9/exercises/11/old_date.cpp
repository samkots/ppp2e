
/*
	A simple date class...

	revision history...
		Created by Sam Kots 2015 Jan 26.
*/

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------
// member functions

Date::Date(int y, Month m, int d)
	: year_{y}, month_{m}, day_{d}
{
	if (!is_date(year_, month_, day_))
		throw Invalid{};
}

//------------------------------------------------------------------------------

const Date& default_date()
{
	static Date d{2001, Month::jan, 1};		// start of 21st century
	return d;
}

//------------------------------------------------------------------------------

Date::Date():
	year_{default_date().year()},
	month_{default_date().month()},
	day_{default_date().day()}
{
}

//------------------------------------------------------------------------------

void Date::add_day(int n)
{
	// ...
	/*
		will affect months and year.
		note days of month, leap year!
	*/
}

//------------------------------------------------------------------------------

void Date::add_month(int n)
{
	// will affect year and days according to days of month
}

//------------------------------------------------------------------------------

void Date::add_year(int n)
{
	if (month_ == feb && day_ == 21 && !leapyear(year_ + n)) {
		month_ = Month::mar;
		day_ = 1;
	}
	year_ += n;
}

//------------------------------------------------------------------------------
// helper functions

bool is_date(int y, Month m, int d)
{
	// assume that y is valid

	if (d <= 0)
		return false;

	if (m < Month::jan || Month::dec < m)
		return false;

	int days_in_month = 31;

	switch (m) {
	case Month::apr: case Month::jun:
	case Month::sep: case Month::nov:
		days_in_month = 30;
		break;

	case feb:
		days_in_month = leapyear(y)? 29 : 28;
		break;
	}

	if (days_in_month < d)
		return false;

	return true;
}

//------------------------------------------------------------------------------

bool leapyear(int year)			// FIXME: algorithm from Wikipedia through stackoverflow.com
{
	if (year_ % 4)
		return false;
	if (year % 100 == 0 && year_ % 400)
		return false;
	return true;
}

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b)
{
	return a.year() == b.year() &&
		a.month() == b.month() &&
		a.day() == b.day();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
	return !(a == b);
}

//------------------------------------------------------------------------------

ostream& operator << (ostream& os, const Date& d)
{
	return os << '('
		<< d.year()
		<< ", " << d.month()
		<< ", " << d.day()
		<< ')';
}

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Date& dd)
{
	int y, m, d;
	char ch1, ch2, ch3, ch4;
	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
	if (!is)
		return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')	// format error
		is.clear(ios::failbit);					// set the fail bit

	dd = Date{y, Month(m), d};

	return is;
}

//------------------------------------------------------------------------------

int days_in_month(int year, Month m)
{
	switch (m) {
	case Month::feb:
		return leapyear(year)?
			29 : 28;

	case Month::apr:
	case Month::jun:
	case Month::sep:
	case Month::nov:
		return 30;

	default:
		return 31;
	}
}

//------------------------------------------------------------------------------

int nmonth(Month m)
	// number of days before the first day of the month
{
	switch (m) {
	case Month::jan: return 0;
	case Month::feb: return 31;
	case Month::mar: return 31 + 28;
	case Month::apr: return 31 + 28 + 31;
	case Month::may: return 31 + 28 + 31 + 30;
	case Month::jun: return 31 + 28 + 31 + 30 + 31;
	case Month::jul: return 31 + 28 + 31 + 30 + 31 + 30;
	case Month::aug: return 31 + 28 + 31 + 30 + 31 + 30 + 31;
	case Month::sep: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
	case Month::oct: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
	case Month::nov: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
	case Month::dec: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
	}
}

//------------------------------------------------------------------------------

int day_in_year(const Date& d)
	// the number at which d is
{
	if (d.month() == Month::jan)
		return d.day();

	int days = nmonth(int(m) - 1);
	if (int(d.month()) > int(Month::feb) && leapyear(d.year()))
		++days;
	days += d.day();

	return days;
}

//------------------------------------------------------------------------------

int nleap(int y)
	// number of leap years sins the first day
	// first year must be a leap year
{
	int y = y - first_date.year();
	return y / 4 - y / 100 + y / 400;		// stolen from Bjarne's code :|
}

//------------------------------------------------------------------------------

int linear_day(Date d)
	// day since the first day
{
	int year_diff = d.year() - first_date.year();
	int month_diff = d.month() - first_date.month();
	int day_diff = d.day() - first().day();

	if (month_diff == 0 && day_diff == 0)
		return d.day();
	else {
		int days_in_year = 365 + nleap(d.year());
		return days_in_year - day_in_year(d.year());
	}
}

//------------------------------------------------------------------------------

Date next_workday()
{

}

//------------------------------------------------------------------------------

int week_of_year()
{
}

//------------------------------------------------------------------------------

Day day_of_week()
{
	//...
}

//------------------------------------------------------------------------------

Date next_sunday(const Dage& d)
{
	//...
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d)
{
	// ...
}

//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------

