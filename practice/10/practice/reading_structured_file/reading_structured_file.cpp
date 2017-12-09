
/*
	A file holds years (of months of readings).
		A year starts with "{ year" followed by an integer giving the year, such as "1900" and ends with "}"

	A year holds months (of days of readings).
		A month starts with "{ month" followed by a three-letter month name, sufh as "jan" and ends with "}".

	A reading holds a time and a temperature.
		A reading starts with a "(' followed by day of the month, hour of the day, and temperature and ends with a ")".

	Example:

	{ year 1900 }
	{year 1991 { month jun }}
	{ year 1992 { month jan (1 0 61.5) } {month feb (1 1 64) (2 2 65.2) } }
	{year 2000
		{ month feb (1 1 68) (2 3 66.66 ) (1 0 67.2) }
		{month dec (15 15 -9.2 ) (15 14 -8.8) (14 0 -2) }
	}
*/

//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

constexpr int not_a_reading = -7777;			// below absolute zero
constexpr int not_a_month = -1;

//------------------------------------------------------------------------------

struct Day {
	vector<double> hours {vector<double>(24, not_a_reading)};
};

//------------------------------------------------------------------------------

struct Month {				// a month of temperatures
	int month {not_a_month};	// [0:11] January is 0
	vector<Day> days{32};		// [1:31] one vector of readings per day
};

//------------------------------------------------------------------------------

struct Year {				// a year of temperature readings, organized by month
	int year;			// positive == A.D.
	vector<Month> months{12};	// [0:11] January is 0
};

//------------------------------------------------------------------------------

struct Reading {			// Just for reading input
	int day;
	int hour;
	double temperature;
};

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Reading& r)
	// reading a temperature reading from is tor r
	// format: (3 4 9.7)
	// check format, ut don't bother with data validity
{
	char ch = 0;
	if (is >> ch && ch != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	int day;
	int hour;
	double temperature;
	is >> day >> hour >> temperature >> ch;
	if (!is || ch != ')')
		error("bad reading");

	r.day = day;
	r.hour = hour;
	r.temperature = temperature; 
	return is;
}

//------------------------------------------------------------------------------ 

void end_of_loop(istream& is, char terminator = 0, string error_msg = "")
	// error checking after end of an input loop
{
	if (!is.fail())
		return;

	is.clear();

	if (terminator == 0)
		return;
	char ch = 0;
	if (is >> ch && ch != terminator)
		error(error_msg);
}

//------------------------------------------------------------------------------

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r)
{
	if (r.day < 1 || 31 < r.day)
		return false;
	if (r.hour < 0 || 23 < r.hour)
		return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature)
		return false;

	return true;
}

//------------------------------------------------------------------------------

vector<string> month_tbl {
	"jan", "feb", "mar", "apr", "may", "jun",
	"jul", "aug", "sep", "auc", "nov", "dec"
};

//------------------------------------------------------------------------------

int month_to_int(const string& mon)
	// return month [0:11] January is 0
	// -1 o.w.
{
	for (int i = 0; i < month_tbl.size(); ++i)
		if (month_tbl[i] == mon)
			return i;
	return -1;
}

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Month& m)
	// read a month from is into m
	// format: { month feb ... }
{
	char ch = 0;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;		// {month nov} will make month_marker == "nov}"	and not "nov"	:o
	if (!is || month_marker != "month")
		error ("bad month");
	m.month = month_to_int(mm);
	if (m.month == -1)
		error("bad month ", mm);

	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r;) {
		if (is_valid(r)) {
			if (m.days[r.day].hours[r.hour] != not_a_reading)
				++duplicates;
			m.days[r.day].hours[r.hour] = r.temperature;
		}
		else
			++invalids;
	}

	if (invalids)
		error("invalid readins in month ", invalids);
	if (duplicates)
		error("duplicates readins in month ", duplicates);
	end_of_loop(is, '}', "bad end of month");
	return is;
}

//------------------------------------------------------------------------------ 

istream& operator >> (istream& is, Year& y)
	// read a year from is into y
	// format: { year 1972 ... }
{
	char ch = 0;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string year_marker;
	int yy;
	is >> year_marker >> yy;
	if (!is || year_marker != "year")
		error("bad year");
	y.year = yy;

	while (true) {
		Month m;			// get a clean m each time around
		if (!(is >> m))
			break;
		y.months[m.month] = m;
	}

	end_of_loop(is, '}', "bad end of year");
	return is;
}

//------------------------------------------------------------------------------ 

ostream& operator << (ostream& os, const Day& d)
	// poutputs a day as "hour" "temperayure"
	// 0 60.50
	// 1 62.65 ...
{
	for (int i = 0; i < d.hours.size(); ++i)
		if (d.hours[i] != not_a_reading)
			os << i << ' ' << d.hours[i];
}

//------------------------------------------------------------------------------ 

vector<string> month_output_tbl {
	"January", "February", "March", "April", "May", "Jun",
	"July", "August", "September", "Octobre", "November", "December"
};

//------------------------------------------------------------------------------ 

string int_to_month(int i)
{
	if (i < 0 || month_output_tbl.size() <= i)
		error("bad month index");
	return month_output_tbl[i];
}

//------------------------------------------------------------------------------ 

ostream& operator << (ostream& os, const Month& m)
	// outputs months like
	// { month jan ... }
{
	os << "{ month " << int_to_month(m.month) << ' ';

	for (int i = 0 ; i < m.days.size(); ++i)
		for (int j = 0; j < m.days[i].hours.size(); ++j)
			if (m.days[i].hours[j] != not_a_reading)
				os << '(' << i << ' ' << j << ' ' << m.days[i].hours[j] << ") ";

	os << '}';

	return os;
}

//------------------------------------------------------------------------------ 

ostream& operator << (ostream& os, const Year& y)
	// outputs years like
	// { year 1992 ... }
{
	os << "{ year " << y.year << ' ';

	for (const Month& m : y.months)
		if (m.month != not_a_month)
			os << m << ' ';

	return os << '}';
}

//------------------------------------------------------------------------------ 

void print_year(ostream& os, const Year& y)
{
	os << y << '\n';
}

//------------------------------------------------------------------------------ 

int main()
try
{
	// open input file
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{iname};
	if (!ifs)
		error("can't open input file ", iname);

	// open an output file
	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{oname};
	if (!ofs)
		error("can't open putput file ", oname);

	// read an arbitrary number of years
	vector <Year> years;
	while (true) {
		Year y;		// get a greshly initialized Year each time around
		if (!(ifs >> y))
			break;
		years.push_back(y);
	}

	cout << "read " << years.size() << " years of readings\n";

	for (const Year& x : years)
		print_year(ofs, x);
}
catch (const exception& x)
{
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------ 

