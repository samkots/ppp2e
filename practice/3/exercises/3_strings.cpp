
#include "std_lib_facilities.h"


int main()
{
	cout << "Enter three strings: ";
	string a, b, c;
	cin >> a >> b >> c;

	string smallest;

	if (a <= b && a <= c) {
		cout << a << " ";
		if (b <= c)
			cout << b << " " << c;
		else
			cout << c << " " << b;
	} else if (b <= a && b <= c) {
		cout << b << " ";
		if (a <= c)
			cout << a << " " << c;
		else
			cout << c << " " << a;
	} else {
		cout << c << " ";
		if (a <= b)
			cout << a << " " << b;
		else
			cout << b << " " << a;
	}

	cout << "\n";
}

