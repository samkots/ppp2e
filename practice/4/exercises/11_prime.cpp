
#include "std_lib_facilities.h"

bool is_prime(int n)
{
	if (n == 1)
		return false;

	vector<int> primes{
		2, 3, 5, 7, 11, 13, 17, 19, 23,
		29, 31, 37, 41, 43, 47, 53, 59,
		61, 67, 71, 73, 79, 83,89, 97
	};

	for (int i = 0; i < primes.size() && primes[i] < n; ++i) {
		if (n % primes[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	cout << "Enter max: ";
	int max;
	cin >> max;
	for (int i = 1; i <= max; ++i) {
		if (is_prime(i))
			cout << i << ' ';
	}

	cout << '\n';
}

