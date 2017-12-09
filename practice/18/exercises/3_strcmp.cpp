
#include "ppp/std_lib_facilities.h"


int str_cmp(const char* s1, const char* s2)
{
	if (!s1) error("First string is null");
	if (!s2) error("Second string is null");

	while (true) {
		if (*s1 < *s2)
			return -1;
		if (*s1 > *s2)
			return 1;
		if (*s1 == 0 && *s2 == 0)
			return 0;

		++s1;
		++s2;
	}

	error("Something went wrong!");
}


int main() try
{
	const char* a = "Hello, World!";
	const char* b = "Hello, World!";

	cout << str_cmp(a, b) << endl;
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


