
#include "ppp/std_lib_facilities.h"


class Vec {
	int sz;
	double* elem;

public:
	Vec()
		:sz{10}, elem{new double[10]} { }

	~Vec() {
		delete[] elem;
	}

	double operator[](int n) {
		return elem[n];
	}
};


int main()
{
	Vec v;
	double x = v[2];
	v[3] = x;		// error
}

// g++: lvalue required as left operand of assignment
// clang:
//	expression is not assignable
//	v[3] = x;
//	~~~~ ^
