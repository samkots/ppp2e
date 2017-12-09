
#include "ppp/std_lib_facilities.h"


//
// Hmmm...
// Stack does grow downwords on intel cpu
// but, as checked in assembly, the compiler is allocating the variables in reverse order!
// thus address are increasing!
// Don't know why...
//


int string_size(const char* str)
{
	if (!str)
		return 0;

	int i = 0;
	for (; str[i]; ++i);
	return i;
}

void copy_string(const char* a, char* b, int a_size)		// assuming b is big enought!
{
	if (a == b)
		return;

	for (int i = 0; i < a_size; ++i)
		b[i] = a[i];
}

int main() try
{
	cout << "Enter text('!' to stop): ";

	string s;
	for (char c = 0; cin.get(c) && c != '!';)
		s.append(string{c});

	cout << "You entered: " << s << endl;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}



