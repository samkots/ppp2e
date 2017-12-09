
#include "std_lib_facilities.h"


int main()
{
	cout << "Please enter the number of values you want to sum:\n";
	int n = 0;
	cin >> n;
	if (n <= 0) {
		cerr << "Sum of first " << n << " numbers?" << endl;
		cerr << "Are you kidding?" << endl;
		return -1;
	}

	cout << "Please enter some integers (press '|' to stop):\n";

	vector<int> ints;
	for (int i; cin >> i;)
		ints.push_back(i);

	if (ints.size() < n) {
		cerr << "Too few elements!" << endl;
		return -1;
	}

	int sum = 0;
	cout << "The sum of the first " << n << " numbers ( ";
	for (int i = 0; i < n; ++i) {
		cout << ints[i] << ' ';
		sum += ints[i];
	}
	cout << ") is " << sum << endl;
}

