
#include "std_lib_facilities.h"


int sum_of_first_n(vector<double> numbers, int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; ++i)
		sum += numbers[i];

	try {
		return narrow_cast<int>(sum);
	} catch (const runtime_error&) {
		error("the result cannot be represented as an int!");
	}
}

int main()
try
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

	int sum = sum_of_first_n(numbers, n);
	cout << "The sum of the first " << n << " numbers ( ";
	for (int i = 0; i < n; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << ") is " << sum << endl;
}
catch (const runtime_error& x)
{
	cerr << "error: " << x.what() << endl;
}

