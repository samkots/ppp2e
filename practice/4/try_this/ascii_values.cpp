
#include "std_lib_facilities.h"


int main()
{
	for (char c = 'a'; c != 'z' + 1; c++) {
		int i = c;
		cout << "char(" << c << "): " << i << "\n";
	}

	for (char c = 'A'; c != 'Z' + 1; c++) {
		int i = c;
		cout << "char(" << c << "): " << i << "\n";
	}

	for (char c = '0'; c != '9' + 1; c++) {
		int i = c;
		cout << "char(" << c << ")" << i << "\n";
	}
}
