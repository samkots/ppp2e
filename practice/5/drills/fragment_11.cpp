
#include "std_lib_facilities.h"


int main()
try {
	//string s = "ape";
	string s = "fool";
	if (s == "fool")
		cout << "Success!\n";
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
