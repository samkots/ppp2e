
#include "std_lib_facilities.h"


int main()
{
	constexpr double cent_per_pennie = 1;
	constexpr double cent_per_nickel = 5;
	constexpr double cent_per_dime = 10;
	constexpr double cent_per_quarter = 25;
	constexpr double cent_per_half_dollar = 50;
	constexpr double cent_per_dollar = 100;

	cout << "How many pennies do you have? ";
	int pennies;		// 1 cent coins
	cin >> pennies;

	cout << "How many nickels do you have? ";
	int nickels;		// 5 cent coins
	cin >> nickels;

	cout << "How many dimes do you have? ";
	int dimes;		// 10 cent coins
	cin >> dimes;

	cout << "How many quarters do you have? ";
	int quarters;		// 25 cent coins
	cin >> quarters;

	cout << "How many half_dollers do you have? ";
	int half_dollers;	// 50 cent coins
	cin >> half_dollers;
	
	cout << "How many dollars do you have? ";
	int dollars;		// 1000 cent coins
	cin >> dollars;

	cout << "\n";

	if (pennies > 0) {
		cout << "You have "<< pennies << " pennie";
		if (pennies > 1)
			cout << "s";
		cout << ".\n";
	}

	if (nickels > 0) {
		cout << "You have "<< nickels << " nickel";
		if (nickels > 1)
			cout << "s";
		cout << ".\n";
	}

	if (dimes > 0) {
		cout << "You have "<< dimes << " dime";
		if (dimes > 1)
			cout << "s";
		cout << ".\n";
	}

	if (quarters > 0) {
		cout << "You have "<< quarters << " quarter";
		if (quarters > 1)
			cout << "s";
		cout << ".\n";
	}

	if (half_dollers > 0) {
		cout << "You have "<< half_dollers << " half_doller";
		if (half_dollers > 1)
			cout << "s";
		cout << ".\n";
	}

	if (dollars > 0) {
		cout << "You have "<< dollars << " dollar";
		if (dollars > 1)
			cout << "s";
		cout << ".\n";
	}

	double cents = pennies * cent_per_pennie +
		nickels * cent_per_nickel +
		dimes * cent_per_dime +
		quarters * cent_per_quarter +
		half_dollers * cent_per_half_dollar +
		dollars * cent_per_dollar;

	cout << "The value of all of our coins is " << cents << " cents.\n";
}
