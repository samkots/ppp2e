
#include "ppp/std_lib_facilities.h"


char* cat_dot(const char* s1, const char* s2, const char* separator = ".")
{
	if (!s1 || !s2 || !separator)
		return nullptr;

	int sz1 = strlen(s1);
	int szs = strlen(separator);
	int sz2 = strlen(s2);

	char* cat = new char[sz1 + szs + sz2 + 1];

	auto copy = [] (char*& p, const char* s) {
		while (*s) {
			*p = *s;
			++p;
			++s;
		}
	};

	char* p = cat;
	copy(p, s1);
	copy(p, separator);
	copy(p, s2);

	p = 0;		// terminating 0

	return cat;
}


int main() try
{
	char* p = cat_dot("Niels", "Bohr");
	cout << p << endl;
	delete[] p;

	p = cat_dot("Sam", "Kots", " `Sam' ");
	cout << p << endl;
	delete[] p;
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


