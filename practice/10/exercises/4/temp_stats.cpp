
#include "../std_lib_facilities.h"
#include "Reading.h"

//------------------------------------------------------------------------------

int main()
{
	// open	a file for reading
	ifstream fin{"raw_temps.txt"};
	if (!fin)
		error("can't open input file");

	vector<Reading> temps;

	// read all the remperatures in the file
	for (Reading r{0, 0}; fin >> r;) {
		if (r.unit == 'c') {
			r.unit = 'f';
			r.temperature = celsius_2_fahrenheit(r.temperature);
		}
		temps.push_back(r);
	}

	cout << "read " << temps.size() << " temperatures.\n";

	// calculate mean and median...
	double sum = 0;
	for (const Reading& x : temps)
		sum += x.temperature;

	double mean = sum / temps.size();

	sort(temps);
	double median = 0;
	if (temps.size() % 2 == 0)
		median = (temps[temps.size() / 2 - 1].temperature +
				temps[temps.size() / 2].temperature) / 2;
	else
		median = temps[temps.size() / 2].temperature;

	cout << "mean: " << mean << " f\n";
	cout << "median: " << median << " f\n";
}

//------------------------------------------------------------------------------

