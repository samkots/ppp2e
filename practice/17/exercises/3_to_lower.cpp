
#include "ppp/std_lib_facilities.h"

int str_size(const char* str)
{
	if (!str)
		return 0;

	int i = 0;
	for (;str[i]; ++i);
	return i;
}

void to_lower(char* str)
{
	if (!str)
		return;

	for (int i = 0; i < str_size(str); ++i)
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';
}

int main() try
{
	//const char* p = "Hello, World!";
	//const char* p = nullptr;
	const char* p = "Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz 0123456789";
	int size = str_size(p);
	cout << size << endl;
	cout << strlen(p) << endl;
	char* str = new char[size];
	for (int i = 0; i < size; ++i)
		str[i] = p[i];
	to_lower(str);
	cout << str << endl;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}

