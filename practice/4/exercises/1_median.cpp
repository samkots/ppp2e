
#include "std_lib_facilities.h"


int main()
{
	vector<double> temps;	//temperatures
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	double sum = 0;
	for (int x : temps)
		sum += x;

	cout << "Aberate temperatures: " << sum / temps.size() << "\n";

	sort(temps);

	cout << "Median temperature: ";
	if (temps.size() % 2 == 0)
		cout << ( temps[temps.size() / 2 - 1] + temps[temps.size() / 2] ) / 2;
	else
		cout << temps[temps.size() / 2];

	cout << "\n";
}

