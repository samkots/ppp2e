
#include "std_lib_facilities.h"


void print_values(vector<int> vec)
{
	for (auto x : vec)
		cout << x << " ";
}

int vec_sum(vector<int> vec)
{
	int sum = 0;
	for (auto x : vec)
		sum += x;

	return sum;
}

int main()
{
	vector<int> sun, mon, tue, wed, thu, fri, sat;
	int rejected_values = 0;

		int val = 0;
	for (string day; cin >> day >> val;) {
		try {
			if (day == "Sunday" || day == "Sun" || day == "sunday" || day == "sun")
				sun.push_back(val);
			else if (day == "Monday" || day == "Mon" || day == "monday" || day == "mon")
				mon.push_back(val);
			else if (day == "Tuesday" || day == "Tue" || day == "tuesday" || day == "tue")
				tue.push_back(val);
			else if (day == "Wednesday" || day == "Wed" || day == "wednesday" || day == "wed")
				wed.push_back(val);
			else if (day == "Thursday" || day == "Thu" || day == "thursday" || day == "thu")
				thu.push_back(val);
			else if (day == "Friday" || day == "Fri" || day == "friday" || day == "fri")
				fri.push_back(val);
			else if (day == "Saturday" || day == "Sat" || day == "saturday" || day == "sat")
				sat.push_back(val);
			else
				error("Bad day!");
		} catch (runtime_error x) {
			rejected_values++;
		}
	}

	cout << "Sunday: ";
	print_values(sun);
	cout << ": " << vec_sum(sun) << '\n';

	cout << "Monday: ";
	print_values(mon);
	cout << ": " << vec_sum(mon) << '\n';

	cout << "Tuesday: ";
	print_values(tue);
	cout << ": " << vec_sum(tue) << '\n';

	cout << "Wednesday: ";
	print_values(wed);
	cout << ": " << vec_sum(wed) << '\n';

	cout << "Thursday: ";
	print_values(thu);
	cout << ": " << vec_sum(thu) << '\n';

	cout << "Friday: ";
	print_values(fri);
	cout << ": " << vec_sum(fri) << '\n';

	cout << "Saturday: ";
	print_values(sat);
	cout << ": " << vec_sum(sat) << '\n';


	cout << "Number of rejected values: " << rejected_values << '\n';
}

