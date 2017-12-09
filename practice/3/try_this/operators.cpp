
#include "std_lib_facilities.h"


int main()
{
	cout << "Please enter a floating-point value: ";
	int input_int;
	double n = input_int;
	cin >> n;
	cout	<< "n == " << n
		<< "\nn + 1 == " << n + 1
		<< "\nthree times n == " << n * 3
		<< "\ntwice n == " << n * 2
		<< "\nn square == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsquare root of n == " << sqrt(n)
		<< "\n";
}
