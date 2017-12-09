
#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

//------------------------------------------------------------------------------

enum class Day {	// sunday == 0
	sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

//------------------------------------------------------------------------------

class Date {
public:
	class invalid { };			// exception

	Date(int year, Month month, int day);	// check for valid date and initialize
	Date();					// make a default date
	// the default copy operations are fine

	// nonmodifying operations
	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

private:
	int y;					// year
	Month m;				// month
	int d;					// day
};

//------------------------------------------------------------------------------

const Date first_date{1601, Month::jan, 1};
const Day first_day = Day::monday;

//------------------------------------------------------------------------------

int days_in_month(int year, Month m);
bool is_date(int year, Month month, int day);
bool leapyear(int y);
void increment(Month& m);
Day day_of_week(const Date& d);
Date next_sunday(const Date& d);
Date next_weekday(const Date& d);
int week_in_year(const Date& d);

bool operator==(const Date& d, const Date& dd);
bool operator!=(const Date& d, const Date& dd);

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& d);

ostream& operator<<(ostream& os, const Day& day);
ostream& operator<<(ostream& os, const Month m);

int operator-(const Date& a, const Date& b);
Date operator+(const Date& d, int n);

//------------------------------------------------------------------------------

} // namespace Chrono

//------------------------------------------------------------------------------

