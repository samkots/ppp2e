
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	int a, b, c, d;
	a = b = c = d = 1234;

	cin.unsetf(ios::dec);
	cin.unsetf(ios::oct);
	cin.unsetf(ios::hex);
	cin >> a >>  b >> c >> d;

	//cin >> a >> hex >> b >> oct >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}

//------------------------------------------------------------------------------

