
#include "std_lib_facilities.h"


int main()
{
	constexpr double km_per_mile = 1.609;

	cout << "Enter distance in miles: ";
	double miles;
	cin >> miles;

	cout << miles << " miles == " << miles * km_per_mile << "\n";
}
