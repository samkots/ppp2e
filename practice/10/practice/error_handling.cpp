
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
	cin.exceptions(cin.exceptions() | ios_base::badbit);

	vector<int> v;
	for (int n = 0; cin >> n; )
		v.push_back(n);
	if (!cin.eof())
		return 1;

	cin.clear();
	char c;
	cin >> c;
	if (c != '*') {
		cin.unget();
		cin.clear(ios_base::failbit);
	}
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------
