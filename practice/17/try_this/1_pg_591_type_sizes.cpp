
#include "ppp/std_lib_facilities.h"


int sizes(char ch, int i, int* p)
{
	cout << "the size of char is: " << sizeof(char) << ' ' << sizeof(ch) << '\n';			// 1
	cout << "the size of int is: " << sizeof(int) << ' ' << sizeof(i) << '\n';			// 4
	cout << "the size of int* is: " << sizeof(int*) << ' ' << sizeof(p) << '\n';			// 8
}

int main()
{
	char ch;
	int i;
	int* p;
	sizes(ch, i, p);

	bool b;
	float f;
	double d;

	cout << "the size of bool is: " << sizeof(bool) << ' ' << sizeof(b) << '\n';			// 1
	cout << "the size of float is: " << sizeof(float) << ' ' << sizeof(f) << '\n';			// 4
	cout << "the size of double is: " << sizeof(double) << ' ' << sizeof(d) << '\n';		// 8
}

