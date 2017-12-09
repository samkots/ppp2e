
#include "std_lib_facilities.h"


int main()
{
	constexpr double dollars_per_yen = 0.0092;
	constexpr double dollars_per_euro = 1.27;
	constexpr double dollars_per_pound = 1.69;
	constexpr double dollars_per_rupee = 0.016;
	constexpr double dollars_per_yuan = 0.16;
	constexpr double dollars_per_kroner = 0.17;

	cout	<< "Enter mony followed by currency\n"
		<< "y for yens\n"
		<< "e for euros\n"
		<< "p for pounds\n"
		<< "r for rupees\n"
		<< "u for yuan\n"
		<< "k for kroner\n"
		<< ">>> ";

	double ammount = 0;
	char currency = 0;
	cin >> ammount >> currency;


	switch (currency) {
	case 'y':
		cout << ammount << " yens == " << ammount * dollars_per_yen<< " dollars\n";
		break;

	case 'e':
		cout << ammount << " euros == " << ammount * dollars_per_euro << " dollars\n";
		break;

	case 'p':
		cout << ammount << " pounds == " << ammount * dollars_per_pound << " dollars\n";
		break;

	case 'r':
		cout << ammount << " rupees == " << ammount * dollars_per_rupee << " dollars\n";
		break;

	case 'u':
		cout << ammount << " yuans == " << ammount * dollars_per_yuan << " dollars\n";
		break;

	case 'k':
		cout << ammount << " kroners == " << ammount * dollars_per_kroner << " dollars\n";
		break;

	default:
		cout << "Not a currency I know... :/";
	}
}
