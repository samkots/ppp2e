
#include "ppp/std_lib_facilities.h"

struct a {
	a() {
		cout << "a ctor" << endl;
	}

	~a() {
		cout << "a dtor" << endl;
	}
};

struct b : a {
	b() {
		cout << "b ctor" << endl;
	}

	~b() {
		cout << "b dtor" << endl;
	}
};



int main()
{
	b b;			// constructs a then b
}

