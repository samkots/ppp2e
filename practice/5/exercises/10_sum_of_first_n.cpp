
#include "std_lib_facilities.h"

double sum_of_first_n(vector<double> numbers, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += numbers[i];

	return sum;
}

vector<double> adjecent_differences(vector<double> numbers, int n)
{
	vector<double> ad;
	for (int i = 0; i < n - 1; ++i)
		ad.push_back(numbers[i + 1] - numbers[i]);

	return ad;
}

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

	vector<double> numbers;
	for (double d; cin >> d;)
		numbers.push_back(d);

	if (numbers.size() < n) {
		cerr << "Too few elements!" << endl;
		return -1;
	}

	double sum = sum_of_first_n(numbers, n);
	vector<double> ad = adjecent_differences(numbers, n);

	cout << "The sum of the first " << n << " numbers ( ";
	for (int i = 0; i < n; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << ") is " << sum << endl;

	if (ad.size() != 0) {
		cout << "Adjecent differences: " << endl;
		for (int i = 0; i < ad.size(); ++i)
			cout << ad[i] << ' ';

		cout << '\n';
	}
}

