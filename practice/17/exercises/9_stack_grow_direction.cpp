
#include "ppp/std_lib_facilities.h"


int main() try
{
	char a = 'a';
	int i = 20;
	char b = 'b';
	int j = 20;
	char c = 'c';
	char d = 'd';

	cout << &i << endl;
	cout << &j << endl;

	cout << "&a: " << static_cast<void*>(&a) << endl;
	cout << "&b: " << static_cast<void*>(&b) << endl;
	cout << "&c: " << static_cast<void*>(&c) << endl;
	cout << "&d: " << static_cast<void*>(&d) << endl;

	char* p = new char;
	char* q = new char;
	char* r = new char;
	char* s = new char;

	cout << "p: " << static_cast<void*>(p) << endl;
	cout << "q: " << static_cast<void*>(q) << endl;
	cout << "r: " << static_cast<void*>(r) << endl;
	cout << "s: " << static_cast<void*>(s) << endl;

	delete p;
	delete q;
	delete r;
	delete s;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}

