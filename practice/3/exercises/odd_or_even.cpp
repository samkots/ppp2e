
#include "std_lib_facilities.h"


int main()
{
	cout << "Enter an integer: ";
	int i;
	cin >> i;

	if (i % 2 == 0)
		cout << "Integer " << i << " is an even number.\n";
	else
		cout << "Integer " << i << " is an odd number.\n";
}
