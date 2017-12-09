
#include "std_lib_facilities.h"


int square(int n)
{
	int square = 0;
	for (int i = 0; i < n; ++i)
		square += n;

	return square;
}

int main()
{
	cout << "Enter a positive number: ";
	int n;
	cin >> n;

	cout << "square(" << n << "): " << square(n) << endl;
}

