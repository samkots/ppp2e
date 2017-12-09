
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	cout << 1234 << "\t(decimal)\n"
		<< hex << 1234 << "\t(hexadecimal)\n"
		<< oct << 1234 << "\t(octal)\n";
	cout << 1234 << "\tmanipulators oct, hex and dec persist\n\n" << dec;

	cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
	cout << "showbase\t\t\tthis as well persists\n" << showbase << dec;
	cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
	cout << "noshowbase\t\t\tand this too\n" << noshowbase << dec;
	cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
}

//------------------------------------------------------------------------------

