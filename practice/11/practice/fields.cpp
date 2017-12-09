
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	cout	<< 123456				// no field used
		<< '|' << setw(4) << 123456 << '|'	// 123456 doesn't fit in 4-char field
		<< setw(8) << 123456 << '|'		// set field width to 8
		<< 123456 << "|\n";			// field sizes don't stick

	cout	<< 12345 << '|' << setw(4) << 12345 << '|'
		<< setw(8) << 12345 << '|' << 12345 << "|\n";

	cout	<< 1234.5 << '|' << setw(4) << 1234.5 << '|'
		<< setw(8) << 1234.5 << '|' << 1234.5 << "|\n";

	cout	<< "asdfg" << '|' << setw(4) << "asdfg" << '|'
		<< setw(8) << "asdfg" << '|' << "asdfg" << "|\t\t\t\tthey don't stick\n";
}

//------------------------------------------------------------------------------

