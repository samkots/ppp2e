
#include "std_lib_facilities.h"


int main()
{
	cout << "Enter two integers: ";
	double val1, val2;
	cin >> val1 >> val2;

	double smaller, larger;
	if (val1 <= val2) {
		smaller = val1;
		larger =  val2;
	} else {
		smaller = val2;
		larger = val1;
	}

	cout << "smaller: " << smaller << "\n";
	cout << "larger: " << larger << "\n";
	cout << "sum: " << val1 + val2 << "\n";
	cout << "difference: " << larger - smaller << "\n";
	cout << "product: " << val1 * val2 << "\n";
	cout << "ratio: " << larger / smaller << "\n";
}
