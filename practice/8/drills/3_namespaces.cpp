
/*
	For the given code for main(), wirte the three namespaces X, Y and Z so
	that the code works correctly.
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

namespace X {
	int var;
	void print()
	{
		cout << "X::var: " << var << '\n';
	}
}

//------------------------------------------------------------------------------

namespace Y {
	int var;
	void print()
	{
		cout << "Y::var: " << var << '\n';
	}
}

//------------------------------------------------------------------------------

namespace Z {
	int var;
	void print()
	{
		cout << "Z::var: " << var << '\n';
	}
}

//------------------------------------------------------------------------------

int main()
	// Following code for main() is given in the book as it is.
{
	X::var = 7;
	X::print();		// print X's var
	using namespace Y;
	var = 9;
	print();		// print Y's var
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();	// print Z'x var
	}
	print();		// print Y's var
	X::print();		// print X's var
}

//------------------------------------------------------------------------------

