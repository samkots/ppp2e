
#include "std_lib_facilities.h"


int main()
{
	cout << "Enter an operation followed by two operands(eg. + 100 3.14): ";
	string operation;
	double d, dd;
	cin >> operation;
	cin >> d >> dd;

	if (operation == "+")
		cout << d << " + " << dd << " == " << d + dd << "\n";
	else if (operation == "-")
		cout << d << " - " << dd << " == " << d - dd << "\n";
	else if (operation == "*")
		cout << d << " * " << dd << " == " << d * dd << "\n";
	else if (operation == "/")
		cout << d << " / " << dd << " == " << d / dd << "\n";
}
