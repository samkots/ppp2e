
#include "std_lib_facilities.h"


int main()
{
	//int n = 2147483647;
	//cout << n << '\n';
	//cout << ++n << '\n';

	//narrow_cast<int>(2147483647 + 1);
	//narrow_cast<int>(++n);

	int n = 0;
	cin >> n;
	if (cin)
		cout << "still cin!\n";
	cout << narrow_cast<int>(n) <<'\n';
}

