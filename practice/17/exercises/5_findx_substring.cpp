
#include "ppp/std_lib_facilities.h"


int string_size(const char* str)
{
	if (!str)
		return 0;

	int i = 0;
	for (; str[i]; ++i);
	return i;
}

const char* findx(const char* s, const char* x)		// find x in s
{
	int s_size = string_size(s);
	int x_size = string_size(x);

	cout << s_size << endl;
	cout << x_size << endl;

	if (s_size < x_size)
		return nullptr;

	for (int i = 0; i < s_size; ++i)
		for (int j = 0; j < x_size; ++j) {
			cout << x[j] << " - " << s[i + j] << "\t";
			cout << j << " - " << x_size << endl;
			if (x[j] != s[i + j])
				break;
			else if (j == x_size - 1)
				return &s[i];
		}

	cout << "huh????" << endl;
	return nullptr;
}

int main() try
{
	const char* s = "Hello, World!";
	//s = nullptr;
	//s = "Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789";
	const char* x = "World!";

	const char* p = findx(s, x);
	if (p) {
		for (int i = 0; i < string_size(x); ++i)
			cout << x[i];
		cout << endl;
	}
	else
		cout << "not found!" << endl;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}



