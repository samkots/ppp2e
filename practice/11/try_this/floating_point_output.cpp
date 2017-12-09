
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

/*

   precision is defined as:
	defaultfloat:	total number of digits
	scientific:	number of digits after decimal point
	fixed:		number of digits after decimal point

*/

//------------------------------------------------------------------------------

int main()
{
	cout	<< setprecision(10);
	cout	<< 1234567.89 << '\n'
		<< fixed << 1234567.89 << '\n'
		<< scientific << 1234567.89 << '\n';

	cout	<< "---------------------------------------------------------\n";

	cout	<< 1234.56789 << '\t'
		<< fixed << 1234.56789 << '\t'
		<< scientific << 1234.56789 << '\n';

	cout	<< defaultfloat << setprecision(5) << '\t'				// defaultfloat not working -- /!\ --
		<< 1234.56789 << '\t'
		<< fixed << 1234.56789 << '\t'
		<< scientific << 1234.56789 << '\n';

	cout	<< defaultfloat << setprecision(8) << '\t'
		<< 1234.56789 << '\t'
		<< fixed << 1234.56789 << '\t'
		<< scientific << 1234.56789 << '\n';
}

//------------------------------------------------------------------------------

