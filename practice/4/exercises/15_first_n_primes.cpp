
#include "std_lib_facilities.h"

bool is_prime(int n)
{
	for (int i = 2; i <= n / 2; ++i)
		if (n % i == 0)
			return false;

	return true;
}

int main()
{
	cout << "Enter n: ";
	int n;
	cin >> n;

	for (int i = 0, j = 2; i < n; ++j) {
		if (is_prime(j)) {
			cout << j << '\n';
			++i;
		}
	}
}

