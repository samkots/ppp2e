
#include "std_lib_facilities.h"


int main()
{
	vector<double> distances;

	for (double distance; cin >> distance;)
		distances.push_back(distance);

	double total_distance = 0;
	for (auto x : distances)
		total_distance += x;

	cout << "total distance: " << total_distance << endl;

	sort(distances);
	cout << "smallest distance: " << distances[0] << "\n";
	cout << "largest distance: " << distances[distances.size() - 1] << "\n";
	cout << "mean distance: " << total_distance / distances.size() << "\n";
}

