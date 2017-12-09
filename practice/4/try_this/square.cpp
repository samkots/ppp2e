
#include "std_lib_facilities.h"


int square(int n)
{
	double square = 0;

	for (int i = 0; i < n; i++) {
		square += n;
	}

	return square;
}

int main()
{
	cout << "Enter a number: ";
	int n;
	cin >> n;
	cout << "square(" << n << ") == " << square(n) << "\n";
}
