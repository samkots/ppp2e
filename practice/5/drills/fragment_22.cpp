
#include "std_lib_facilities.h"


int main()
try {
	//string<char> s = "Success!\n";
	string s = "Success!\n";
	//for (int i = 0; i <= 10; ++i)
	for (int i = 0; i <= s.size(); ++i)
		cout <<s[i];
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
