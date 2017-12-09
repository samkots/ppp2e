
#include "ppp/std_lib_facilities.h"


char* strdup(const char* s)
{
	if (!s)
		return nullptr;

	int len = strlen(s);
	char* p = new char[len + 1];
	char* copy = p;
	while (*s) {
		*p = *s;
		++p;
		++s;
	}

	*p = *s;

	return copy;
}


int main() try
{
	const char* s = "Bingo!";
	char* p = strdup(s);

	if (p)
		cout << p << endl;

	delete[] p;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}

