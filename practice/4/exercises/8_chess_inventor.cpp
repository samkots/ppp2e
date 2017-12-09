
#include "std_lib_facilities.h"


int main()
{
	int constexpr atleast = 1000000000;

	for (int i = 1, grains = 1; grains <= atleast; ++i) {
		grains *= 2;
		cout << i << ". "<< grains << '\n';
	}
}

