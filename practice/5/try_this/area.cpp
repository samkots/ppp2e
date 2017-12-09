
#include "std_lib_facilities.h"



int area(int length, int width)
// calculate area of a rectangle
// pre-condition: length and width are positive
// post-condition: returns a positive value that is the area
{
	if (length <= 0 || width <= 0)
		error ("area() pre-condition");
	int a = length * width;
	if (a <= 0)
		error("area() post-condition: " + to_string(a));
	return a;
}


int main() try
{
	cout << "Enter length and width: ";
	int length, width;
	cin >> length >> width;
	cout << "area: " << area(length, width) << endl;
} catch (const std::runtime_error& x) {
	cerr << "what: " << x.what() << endl;
}

