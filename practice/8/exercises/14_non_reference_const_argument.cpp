
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

/*
	non-reference const argument.
	That means the function gest a copy. And that copy cannot be modified.

	It might be thought of as if the argument logically is a constant
	for the function for its internal logic.

	People don't do that often since it doesn't make any difference to
	the caller. Because even if the functinomodified that argument, that
	will affect the function's local copy and the actual argument would be
	unchanged.
*/

//------------------------------------------------------------------------------

void f(const int n) {
	cout << ">>> " << n << endl;
	//n++;					// can't modify a constant
}

//------------------------------------------------------------------------------

int main()
{
	f(2);
}

//------------------------------------------------------------------------------

