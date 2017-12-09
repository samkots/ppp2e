
#include "std_lib_facilities.h"


double smaller(double n, double nn)
{
	if (n <= nn)
		return n;
	return nn;
}

double larger(double n, double nn)
{
	if (n >= nn)
		return n;
	return nn;
}

double to_m(double distance, string unit)
{
	constexpr double cm_per_m = 100;
	constexpr double cm_per_in = 2.54;
	constexpr double in_per_ft = 12;

	if (unit == "m")
		return distance;
	else if (unit == "cm")
		return distance / cm_per_m;
	else if (unit == "in")
		return to_m(distance / cm_per_in, "cm");
	else if (unit == "ft")
		return to_m(distance / in_per_ft, "in");

	return -1;
}

int main()
{
	double d;
	double total = 0;
	string unit;
	vector<double> distances;

	for (int i = 1; cin >> d >> unit; i++)
	{
		double distance = to_m(d, unit);
		if (distance == -1) {
			cout << "error: invalid unit: \"" << unit << "\"\n";
			return -1;
		}

		distances.push_back(distance);

		double smallest, largest;
		if (i == 1)
			smallest = largest = distance;

		if (distance < smallest)
			smallest = distance;

		if (distance > largest)
			largest = distance;

		total += distance;

		cout << i << ".\n";
		cout << "distance: " << distance << " m\n";
		if (distance == smallest)
			cout << "smallest so far\n";

		if (distance == largest)
			cout << "largest so far\n";

		cout << "total distance: " << total << "m\n";

		cout << "\n";
	}

	sort(distances);

	cout << "All the values that were entered:\n";
	for (auto x : distances) {
		cout << x << "m\n";
	}
}

