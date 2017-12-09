
#include "ppp/std_lib_facilities.h"


static int gstatic1 = 10;					// lower
static int gstatic2 = 20;					// higher

int main() try
{
	static int lstatic1 = 1;				// lower
	static int lstatic2 = 2;				// higher

	int stack1 = 100;					// lower
	int stack2 = 200;					// higher

	int* fs1 = new int{100};
	int* fs2 = new int{200};

	cout << "&gstatic1: " << &gstatic1 << endl;
	cout << "&gstatic2: " << &gstatic2 << endl;
	cout << "---\n";
	cout << "&lstatic1: " << &lstatic1 << endl;
	cout << "&lstatic2: " << &lstatic2 << endl;

	cout << &gstatic2 - &gstatic1 << endl;
	cout << &gstatic2 - &gstatic1 << endl;

	cout << "---\n";
	cout << "&stack1: " << &stack1 << endl;
	cout << "&stack2: " << &stack2 << endl;

	cout << &stack2 - &stack1 << endl;

	cout << "---\n";
	cout << "&fs1: " << &fs1 << endl;			// lower
	cout << "&fs2: " << &fs2 << endl;			// higher

	cout << &fs2 - &fs1 << endl;

	delete fs2, fs1;

	int* a = new int[10]{0};				// lower to higher

	cout << "a <<: " << a << endl;
	cout << "&a[10]: " << &a[10] << endl;

	cout << "---\n";
	cout << &a[1] - a << endl;
	cout << &a[10] - a << endl;
	cout << a - &a[10] << endl;
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


