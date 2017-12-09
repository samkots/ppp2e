
#include "ppp/std_lib_facilities.h"


string cat_dot(const string& s1, const string& s2)
{
	return s1 + '.' + s2;
}


int main() try
{
	cout << cat_dot("Niels", "Bohr") << endl;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 2;
}
catch (...) {
	cerr << "error!" << endl;
	return 3;
}


