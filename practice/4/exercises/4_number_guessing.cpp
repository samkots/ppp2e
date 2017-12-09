
#include "std_lib_facilities.h"


int main()
{
	cout << "Think of any number between 1 to 100.\n";
	cout << "I'll try to guesss.\n";
	int lower = 1;
	int upper = 100;

	while (upper != lower) {
		cout << lower << "\t" << upper << endl;
		int mid = (upper - lower) / 2 + lower;
		cout << "Is the number less than or equal to " << mid << "? ";
		char ans;
		cin >> ans;
		if (ans == 'y')
			upper = mid;
		else
			lower = mid + 1;
	}

	cout << lower << "! right? :)\n";
}

