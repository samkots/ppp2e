
#include "std_lib_facilities.h"


//
// Largest fibonacci number to fit in an int: 1836311903
// its the 46th number in the series!
//

void print_fibonacci(int n)
{
	if (n <= 0)
		error("invalid argument");

	for (int i = 0, fib = 1, prev = 0; i < n; ++i) {
		cout << fib << ' ';
		int tmp = fib;
		fib += prev;
		prev = tmp;
	}
	cout << '\n';
}

int main()
try
{
	cout << "Enter n: ";
	int n;
	cin >> n;

	print_fibonacci(n);
}
catch (runtime_error& x)
{
	cerr << "error: " << x.what() << endl;
}

