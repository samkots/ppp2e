
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void swap_v(int a, int b)
{
	int temp;
	temp = a, a = b;
	b = temp;
}

//------------------------------------------------------------------------------

void swap_r(int& a, int& b)
{
	int temp;
	temp = a, a = b;
	b = temp;
}

//------------------------------------------------------------------------------

/*
void swap_cr(const int& a, const int& b)	// doesn't compile
{
	int temp;
	temp = a, a = b;			// oops! assigning to a const
	b = temp;				// oops! assigning to a const
}
*/

//------------------------------------------------------------------------------

int main()
{
	int x = 7;
	int y = 9;
	//swap_v(x, y);			// doesn't swap: pass-by-value
	swap_r(x, y);			// swaps							!!!
	//swap_cr(x, y);		// error

	//swap_v(7, 9);			// doesn't swap: pass-by_value
	//swap_r(7, 9);			// error: non-const-reference initialized to rvalue
	//swap_cr(7, 9);		// won't compile
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';

	const int cx = 7;
	const int cy = 9;
	//swap_v(cx, cy);		// doesn't swap: pass-by-value
	//swap_r(cx, cy);		// error: non-const-reference initialized to const-reference
	//swap_cr(cx, cy);		// won't compile

	//swap_v(7.7, 9.9);		// doesn't swap: pass-by-value
	//swap_r(7.7, 9.9);		// error: non-const-reference initialized to rvalue
	//swap_cr(7.7, 9.9);		// won't compile
	//cout << "cx: " << cx << '\n';
	//cout << "cy: " << cy << '\n';

	double dx = 7.7;
	double dy = 9.9;
	//swap_v(dx, dy);		// doesn't swap
	//swap_r(dx, dy);		// error: initialization of 'int&' from 'double' -- no conversion for non-const-references /!\ ...
	//swap_cr(dx, dy);		// won't compile

	//swap_v(7.7, 9.9);		// doesn't swap
	//swap_r(7.7, 9.9);		// error: non-const-reference initialized to rvalue
	//swap_cr(7.7, 9.9);		// won't compile
	//cout << "dx: " << dx << '\n';
	//cout << "dy: " << dy << '\n';
}

//------------------------------------------------------------------------------

