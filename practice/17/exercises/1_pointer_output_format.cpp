
#include "ppp/std_lib_facilities.h"


int main()
{
	int* p = new int{10};
	cout << "p: " << p << endl;
	cout << "*p: " << *p << endl;

	delete p;
}

