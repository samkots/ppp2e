
#include "ppp/std_lib_facilities.h"


int string_size(const char* str)
{
	if (!str)
		return 0;

	int i = 0;
	for (; str[i]; ++i);
	return i;
}

void copy_string(const char* s1, char* s2)
{
	if (s1 == s2)
		return;

	int size = string_size(s1);
	for (int i = 0; i < size; ++i)
		s2[i] = s1[i];
}

int main() try
{
	//const char* p = "Hello, World!";
	//const char* p = nullptr;
	const char* p = "Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789";
	int size = string_size(p);
	char* str = new char[size + 1];

	copy_string(p, str);

	cout << str << endl;

	delete[] str;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}


