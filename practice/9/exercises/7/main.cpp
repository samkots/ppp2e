
#include "../std_lib_facilities.h"
#include "book.h"

//------------------------------------------------------------------------------

int main()
try
{
	Book ppp {
		"978-0-321-99278-9",
		"Programming Principles and practice using C++",
		"Bjarne Stroustrup",
		"May 2014",
		Book::Genre::cplusplus
	};

	Book tcppstl {
		"012-3-456-789-a",		// not real!
		"The C++ Standard Template Library",
		"Alexander Stepanov",
		"Jun 1996",			// not real!
		Book::Genre::cplusplus
	};

	cout << ppp << '\n';
	cout << tcppstl << '\n';
}
catch (const Book::Bad_book& x) {
	cerr << "error: incorrect book information!\n";
	return -1;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "error!\n";
	return -1; }

