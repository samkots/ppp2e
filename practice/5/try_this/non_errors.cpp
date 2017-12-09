
#include "std_lib_facilities.h"

int area(int length, int width)	// calculate area of a rectangle
{
	return length * width;
}

int main()
{
	//int x4 = area(10, -7);
	//int x5 = area(10.7, 9.3);
	char x6 = area(100, 9999);

	cout << x6 << "\n";
}

