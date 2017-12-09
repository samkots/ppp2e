
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double str_to_double(const string& s)
{
	stringstream ss{s};
	double d;
	ss >> d;
	if (!ss)
		error("double format error: ", s);
	return d;
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << str_to_double("12.4") << '\n';
	cout << str_to_double("1.34e-3") << '\n';
	cout << str_to_double("twelve point three") << '\n';
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

