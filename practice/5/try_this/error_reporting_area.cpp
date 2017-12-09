
#include "std_lib_facilities.h"


int area(int length, int width)
{
	if (length <= 0 || width <= 0)
		return -1;
	return length * width;
}

int framed_area(int length, int width)
{
	return area(length - 2, width - 2);
}

int f(int x, int y, int z)
{
	int area1 = area(x, y);
	if (area1 <= 0)
		error("non-positive area");

	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = double(area1) / area3;

	cout << "area1: " << area1 << '\n';
	cout << "area2: " << area2 << '\n';
	cout << "area3: " << area3 << '\n';
	cout << "ratio: " << ratio << '\n';
	//...
}

int main()
{
	f(2, -2, -2);
}

