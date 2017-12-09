
#include "date.h"

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------

const Date& default_date()
{
	static const Date d(2001, Month::jan, 1);	// starting from the 21st century
	return d;
}

//------------------------------------------------------------------------------

Date::Date():
	y{default_date().year()},
	m{default_date().month()},
	d{default_date().day()}
{
}

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
	: y(yy), m(mm), d(dd)
{
	if(!is_date(yy, mm, dd))
		throw invalid();
}

//------------------------------------------------------------------------------

void Date::add_day(int n)
{
	if (n < 0)
		error("Can't handle negatives yet");

	while (days_in_month(y, m) < n) {		// move month by month...
		add_month(1);
		n -= days_in_month(y, m);
	}

	d += n;
}

//------------------------------------------------------------------------------

void Date::add_month(int n)
{
	if (n < 0)
		error("Can't handle negatives yet");

	int prev_days_in_months = days_in_month(y, m);

	for (; n; --n) {
		increment(m);
		if (m == Month::jan)
			++y;
	}

	if (days_in_month(y, m) < prev_days_in_months) {
		increment(m);
		if (m == Month::jan)
			y += 1;
	}
}

//------------------------------------------------------------------------------

void Date::add_year(int n)
{
	if (n < 0)
		error("Can't handle negatives yet");

	if (m == Month::feb && d == 29 && !leapyear(y + n)) {
		m = Month::mar;
		d = 1;
	}

	y += n;
}

//------------------------------------------------------------------------------

bool is_date(int y, Month m, int d)
{
	// assume that the year is correct
	if (d < 0)
		return false;

	if (d > days_in_month(y, m))
		return false;

	return true;
}

//------------------------------------------------------------------------------

bool leapyear(int y)			// FIXME: Algo from Wiki through stackoverflow.com
{
	if (y % 4)
		return false;
	if (y % 100 == 0 and y % 400)
		return false;
	return true;
}

//------------------------------------------------------------------------------

int linear_day(const Date& d);		// forward declaration

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b)
{
	return a.year() == b.year() and
		a.month() == b.month() and
		a.day() == b.day();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
	return !(a == b);
}

//------------------------------------------------------------------------------

int operator-(const Date& a, const Date& b)
	// how many days are there between a and b?
{
	return linear_day(a) - linear_day(b);
}

//------------------------------------------------------------------------------

Date operator+(const Date& d, int n)
	// n days beyond d
{
	Date dd = d;
	dd.add_day(n);
	return dd;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Month m)
{
	switch (m) {
	case Month::jan: return os << "January";
	case Month::feb: return os << "February";
	case Month::mar: return os << "March";
	case Month::apr: return os << "April";
	case Month::may: return os << "May";
	case Month::jun: return os << "June";
	case Month::jul: return os << "July";
	case Month::aug: return os << "August";
	case Month::sep: return os << "September";
	case Month::oct: return os << "October";
	case Month::nov: return os << "Novermber";
	case Month::dec: return os << "December";
	}
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '('
		<< d.year() << ", "
		<< d.month() << ", "
		<< d.day() << ')';
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& date)
{
	int y, m, d;
	char c1, c2, c3, c4;
	is >> c1 >> y >> c2 >> m >> c3 >> d >> c4;
	if (!is)
		return is;
	if (c1 != '(' || c2 != ',' || c3 != ',' || c4 != ')') {
		is.clear(ios_base::failbit);
		return is;
	}

	date = Date{y, Month(m), d};
	return is;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Day& day)
{
	switch (day) {
	case Day::sunday:	return os << "Sunday";
	case Day::monday:	return os << "Monday";
	case Day::tuesday:	return os << "Tuesday";
	case Day::wednesday:	return os << "Wednesday";
	case Day::thursday:	return os << "Thursday";
	case Day::friday:	return os << "Friday";
	case Day::saturday:	return os << "Saturday";
	}
}

//------------------------------------------------------------------------------

void increment(Month& m)
{
	if (m == Month::dec)
		m = Month::jan;
	else
		m = Month(int(m) + 1);
}

//------------------------------------------------------------------------------

int days_in_month(int year, Month m)
{
	switch (m) {
	case Month::feb:
		return leapyear(year) ? 29 : 28;

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
	// number of days since Jan 1 before the current month.
	// e.g. nmonths(feb) == 31
	// caller must take care of leap years.
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

int day_in_year(Date d)
	// e.g. Jan 1 is day #1, Jan 2 is day #2 and so on.....
{
	int days = nmonth(d.month());			// days up to last month
	if (Month::feb < d.month() && leapyear(d.year()))
		++days;

	return days + d.day();
}

//------------------------------------------------------------------------------

int nleaps(int y)
	// number of leap years since the first day
	// taken from the Lord's code :p
	// first year must be divisible by 400 he says.
{
	int yy = y - first_date.year();			// years passed in between
	return yy / 4 - yy / 100 + yy / 400;
}

//------------------------------------------------------------------------------

int linear_day(const Date& d)
	// days since the default date
	// don't know how it works!	:o
	// Taken from the Lord's code
{
	int years = d.year() - first_date.year();
	if (years < 0)
		error("cant yet handle dates before (1601, Jan, 1)!");

	int months = int(d.month()) - int(first_date.month());
	int days = d.day() - first_date.day();

	if (years == 0 && months == 0)
		return d.day();

	int days_in_year = 365 * years + nleaps(d.year());
	return days_in_year - day_in_year(d) - 1;
}

//------------------------------------------------------------------------------

Date date_from_linear(int n)
{
	return Date {
		first_date.year(),
		first_date.month(),
		first_date.day()
	} + n;
}

//------------------------------------------------------------------------------

Day day_of_week(const Date& d)
{
	int days = int(first_day) + linear_day(d);
	return Day(days % 7);
}

//------------------------------------------------------------------------------

Date next_sunday(const Date& d)
{
	Day dd = day_of_week(d);
	Date ret{d};
	ret.add_day(7 - int(dd));
	return ret;
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d)
{
	Day dd = day_of_week(d);
	int n = 1;
	switch (dd) {
	case Day::friday:
		n = 3;
		break;

	case Day::saturday:
		n = 2;
		break;
	}

	return d + n;
}

//------------------------------------------------------------------------------

int week_in_year(const Date& d)
	// taken from the Lord's code :o
	// the number of a week in a year is defined by ISO 8601:
	// week #1 is the week with the year's first Thursday in it
	// Monday is the first day of the week

	// 0 means that the date is in the last week ofthe previous year
{
	int diy = day_in_year(d);
	Day jan1 = day_of_week(d);
	int delta;
	switch (jan1) {
	case Day::monday:	delta = 0;	break;
	case Day::tuesday:	delta = 1;	break;
	case Day::wednesday:	delta = 2;	break;
	case Day::thursday:	delta = 3;	break;
	case Day::friday:	delta = -3;	break;
	case Day::saturday:	delta = -2;	break;
	case Day::sunday:	delta = -1;	break;
	}

	return (diy + delta) / 7;
}

//------------------------------------------------------------------------------

} // namespace Chrono

//------------------------------------------------------------------------------

