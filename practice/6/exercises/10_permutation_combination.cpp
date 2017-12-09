
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int fact(int n)
{
	if (n < 0)
		error("negative number");

	int fact = 1;
	for (; n > 1; --n)
		fact *= n;

	return fact;
}

//------------------------------------------------------------------------------

int permutation(int a, int b)
{
	if (a < b)
		error("first number is less than the second");

	int p = 1;
	int subtraction = a - b;
	for (; a > subtraction; --a)
		p *= a;

	return p;
}

//------------------------------------------------------------------------------

double combination(int a, int b)
{
	if (a < b)
		error("first number is less than the second");

	return permutation(a, b) / fact(b);
}

//------------------------------------------------------------------------------

char get_input()
{
	cout << "Do you want permutation or combination? (p/c): ";
	char ch = 0;
	while (true) {
		cin >> ch;
		if (ch == 'p' || ch == 'c')
			return ch;

		cout << "Please enter valid character. Either p or c: ";
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Welcome to permutation-combination calculator!\n";
	cout << "Enter two numbers: ";
	int a, b;
	cin >> a >> b;
	if (!cin)
		error("Bad input!");

	switch (get_input()) {
	case 'p':
	{
		int p = permutation(a, b);
		cout << "Permutation: " << p << '\n';
		break;
	}
	case 'c':
	{
		double c = combination(a, b);
		cout << "Combination: " << c << '\n';
		break;
	}
	}
}
catch (runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}
catch (...) {
	cerr << "error!" << endl;
	return -1;
}

//------------------------------------------------------------------------------

