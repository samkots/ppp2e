
#include "ppp/std_lib_facilities.h"


const char* findx(const char* s, const char* x)			// finds x in s
{
	if (!s) return nullptr;
	if (!x) return nullptr;

	const char* substr = s;
	while (*substr) {
		const char* p = substr;
		const char* q = x;
		while (*p && *q) {
			if (*p != *q)
				break;
			++p;
			++q;
			if (!*q)
				return substr;
		}

		++substr;
	}

	return nullptr;
}

int main() try
{
	const char* s = "Hello, World!";
	//s = nullptr;
	//s = "Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789";
	const char* x = "World!";
	//x = "01234";

	const char* p = findx(s, x);
	if (p) {
		for (int i = 0; i < strlen(x); ++i)
			cout << p[i];
		cout << endl;
	}
	else
		cout << "not fount!" << endl;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}


