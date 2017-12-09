
//
// This is actually hanging the whole system(Arch Linux on raptor) rendering it
// unusable! Not yet seen the bad_alloc thrown..
//

#include "ppp/std_lib_facilities.h"



int main() try
{
	cout << "start" << endl;

	constexpr int size = 1024;		// 1024 bytes at a time

	int i = 0;
	for (;; ++i) {
		char* p = new char[size];
		p[0] = 'a';
		p[size - 1] = 'z';
		cout << "written for " << i << endl;
	}

	cout << "done: " << i << endl;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}



