
/*
	The rogram prints first n prime numbers using the algorithm Seive of eratosthenes...
*/

//------------------------------------------------------------------------------

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	cout << "Enter max number: ";
	int max;
	cin >> max;

	vector<int> numbers;
	for (int i = 2; i <= max; ++i)
		numbers.push_back(i);				// 2, 3, 4, 5, 6, ... max

	vector<int> primes;
	for (int i = 0; i < numbers.size(); ++i)
		if (numbers[i] != 0) {
			primes.push_back(numbers[i]);
			for (int j = i; j < numbers.size(); j += primes[primes.size() - 1])	// multiples of i in numbers
				numbers[j] = 0;							// make them 0
		}

	for (const auto x : primes)
		cout << x << '\n';				// print 'em all..!
}

//------------------------------------------------------------------------------

