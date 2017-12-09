
#include "std_lib_facilities.h"

int main()
{
	double sum = 0;
	double high_temp = -1000;		// initialize to impossibly low
	double low_temp = 1000;			// initialize to "impossibly high"
	int no_of_temps = 0;

	vector<double> temps;			// temperature

	for (double temp; cin >> temp;) {
		temps.push_back(temp);
		sum += temp;
		if (temp > high_temp)
			high_temp = temp;	// find high

		if (temp < low_temp)
			low_temp = temp;	// find low
	}

	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum/temps.size() << '\n';
}

