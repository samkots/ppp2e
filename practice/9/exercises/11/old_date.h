
/*
	A simple date class...

	revision history...
		Created by Sam Kots 2015 Jan 26.
*/

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

//------------------------------------------------------------------------------

class Date {
public:
	class Invalid { };				// exception class

	Date(int year, month m, int day);		// check for valid date
	Date();						// default constructor
	// the default copy operations are fine

	// nonmodifying operations:
	int day() const { return day_; }
	Month month() const { return month_; }
	int year() const { return year_; }

	// modifying operations:
	void add_day(int n);
	void add_month(int n);
	void add_year(int year);

private:
	int year_;
	Month month_;
	int day_;
};

//------------------------------------------------------------------------------

enum class Day {
	sunday, monday, tuesdat, wednesday, thirsday, friday, saturday
}

//------------------------------------------------------------------------------

bool is_date(int y, Month m, int d);	// true for valid date
bool leapyear(int y);			// true if y is leap year
bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& d);

//------------------------------------------------------------------------------

Date first_date = Date{1601, Month::jan, 1}:
Day first_day = Day::sunday;

//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------

int main() { }

