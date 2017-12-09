
#include "std_lib_facilities.h"


int main()
{
	constexpr double dollars_per_yen = 0.0092;
	constexpr double dollars_per_euro = 1.27;
	constexpr double dollars_per_pound = 1.69;
	constexpr double dollars_per_rupee = 0.016;

	cout	<< "Enter mony followed by currency\n"
		<< "y for yens\n"
		<< "e for euros\n"
		<< "p for pounds\n"
		<< "r for rupees\n";

	double ammount = 0;
	char currency = 0;
	cin >> ammount >> currency;


	if (currency == 'y')
		cout << ammount << " yens == " << ammount * dollars_per_yen<< " dollars\n";
	else if (currency == 'e')
		cout << ammount << " euros == " << ammount * dollars_per_euro << " dollars\n";
	else if (currency == 'p')
		cout << ammount << " pounds == " << ammount * dollars_per_pound << " dollars\n";
	else if (currency == 'r')
		cout << ammount << " rupees == " << ammount * dollars_per_rupee << " dollars\n";
	else
		cout << "Not a currency I know... :/";
}
