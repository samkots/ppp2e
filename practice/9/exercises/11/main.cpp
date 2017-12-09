
#include "../std_lib_facilities.h"
#include "date.h"

using namespace Chrono;

//------------------------------------------------------------------------------

int main()
try
{
	Date d{2015, Month::feb, 22};
	cout << day_of_week(d) << endl;
	cout << next_weekday(d) << endl;
}
catch (const Date::invalid& x) {
	cerr << "error: invalid date!" << endl;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------

