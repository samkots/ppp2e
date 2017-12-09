
#include "std_lib_facilities.h"


int main()
{
	int constexpr squares = 64;

	for (int i = 1, grains = 1; i <= squares; ++i) {
		grains *= 2;
		cout << i << ". "<< grains << '\n';
	}
}

