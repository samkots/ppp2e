
//
// CRAZY OBSERVATION !!!
// 
// We define a function with the same name as std::strcmp in global namespace.
// This compiles.
// but when our strcmp throws, it is NOT catched !!
// instead, std::terminate() is called straight away !!!
//
// Why so?
// Compiler doesn't seem to have any problem..
// Is it the linker?
//

#include "ppp/std_lib_facilities.h"


int strcmp(const char* s1, const char* s2)		// SAME name as std::strcmp()
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

	a = nullptr;					// this will cause the function to throw
	b = nullptr;

	cout << strcmp(a, b) << endl;			// even if the exception is thrown
}
catch (const runtime_error& x) {			// it is NOT cached...!!
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 2;
}
catch (...) {						// not even here...!!!
	cerr << "error!" << endl;
	return 3;
}


