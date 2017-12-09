
#include "std_lib_facilities.h"


int main()
try {
	//cin << "Success!\n";		// This one is really the last on... the boss of all !!!
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
