
#include "ppp/std_lib_facilities.h"


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
	int size = 4;
	char* p = new char[size];

	char c = 0;
	for (int i = 0; cin.get(c) && c != '!'; ++i) {
		if (i == size) {
			char* q = new char[size += 4];
			copy_string(p, q, size);
			delete p;
			p = q;
		}

		p[i] = c;
	}

	cout << "You entered: " << p << endl;
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



