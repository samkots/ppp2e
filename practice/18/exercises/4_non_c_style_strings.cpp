
#include "ppp/std_lib_facilities.h"


char* strdup(const char* s, int size)				// non-c-style version
{
	if (!s || size == 0)
		return nullptr;

	char* p = new char[size];
	char* copy = p;
	for (int i = 0; i < size; ++i)
		p[i] = s[i];

	return copy;
}

int findx(const char* s, const char* x, int szs, int szx)	// finds x in s, non-c-style version
{
	if (!s || szs == 0) return -1;
	if (!x || szx == 0) return -1;

	for (int i = 0; i <= szs - szx; ++i) {			// yes... <=
		for (int j = 0; j < szx; ++j) {
			if (s[i + j] != x[j])
				break;
			if (j == szx - 1)
				return i;
		}
	}

	return -1;
}

int str_cmp(const char* s1, const char* s2, int szs, int szx)			// non-c-style version
{
	if (!s1) error("First string is null");
	if (!s2) error("Second string is null");

	int sz = szs;								// sz = smaller_of(szs, szx);
	if (szx < sz)
		sz = szx;

	for (int i = 0; i < sz; ++i) {
		if (s1[i] < s2[i])		// compare char-by-char
			return -1;
		if (s1[i] > s2[i])
			return 1;

		// here, one string starts with the other
		if (i == sz - 1 && szs == szx)	// szme size => they are equal
			return 0;
		if (i == sz - 1 && szs < szx)	// ex. "ab" & "abcd"
			return -1;
		if (i == sz - 1 && szs > szx)	// ex. "abcd" & "ab"
			return 1;
	}

	error("Something went wrong!");
}

int main() try
{
	// actual strings that we want to use: ss and xx
	// but they are C-style 0-terminated which we don't want
	char ss[] = "Hello, World!";						// size 13
	char xx[] = "World!";							// size 6

	//char ss[] = "aaa";							// for testing str_cmp()
	//char xx[] = "aaa";

	constexpr int szs = sizeof(ss) - 1;
	constexpr int szx = sizeof(xx) - 1;

	// so late's make non-0-terminated strings from ss and xx
	// namely s and x

	// size + 5 for making fake non-0-terminated array
	char s[szs + 5];							// non C-style
	{
		// initialize s with non-0 chars
		for (int i = 0; i < szs + 5; ++i)
			s[i] = 'A' + i;

		// initialize with ss
		char* p = s;
		for (const char* q = ss; *q; ++p, ++q)
			*p = *q;
	}

	// size + 5 for making fake non-0-terminated array
	char* x = new char[szx + 5];						// non C-style
	{
		// initialize x with non-0 chars
		for (int i = 0; i < szx + 5; ++i)
			x[i] = 'a' + i;

		// initialize with xx
		char* p = x;
		for (const char* q = xx; *q; ++p, ++q)
			*p = *q;
	}

	// now late's use x and x...

	// strdup
	const char* dup = strdup(s, szs);
	cout << "duplicate: " << dup << endl;
	delete[] dup;

	// findx
	int idx = findx(s, x, szs, szx);
	if (idx == -1)
		cout << "not found!" << endl;
	else {
		for (int i = idx; i < szs; ++i)
			cout << s[i];
		cout << endl;
	}

	// str_cmp
	cout << "comparison: " << str_cmp(s, x, szs, szx) << endl;

	delete[] x;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}


