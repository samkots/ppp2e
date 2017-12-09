
#include "ppp/std_lib_facilities.h"


bool is_palindrome(const string& s)
{
	string b = s;					// copy
	for (int i = 0; i < b.size() / 2; ++i) {	// reverse
		char tmp = b[b.size() - 1 - i];
		b[b.size() - 1 - i] = b[i];
		b[i] = tmp;
	}

	for (int i = 0; i < s.size(); ++i)		// compare
		if (s[i] !=  b[i])
			return false;

	return true;
}

istream& read_word(istream& is, char* buffer, int max)
	// read at most max - 1 characters from is into buffer
{
	is.width(max);		// read at most max - 1 characters in the next >>
	is >> buffer;		// read white space terminated word
				// add zero after the last character read into buffer
	return is;
}

bool is_palindrome(const char s[], int n)
{
	char* p = new char[n];

	for (int i = 0; i < n; ++i)			// reverse copy
		p[i] = s[n - 1 - i];

	for (int i = 0; i < n; ++i)			// compare
		if (s[i] != p[i]) {
			delete[] p;
			return false;
		}

	delete[] p;
	return true;
}

bool is_palindrome(char* first, char* last)		// [first, last] instead of [first, last)
{
	if (!first || !last)
		return false;

	char* p = new char[last - first + 1];

	char* pp = p;
	char* ll = last;
	while (ll >= first) {				// reverse copy
		*pp = *ll;
		++pp;
		--ll;
	}

	pp = p;
	while (first != last) {				// compare
		if (*first != *pp) {
			delete[] p;
			return false;
		}

		++first;
		++pp;
	}

	return true;
	delete[] p;
}

int main() try
{
	//for (string s; cin >> s;) {
	//	cout << s << " is";
	//	if (!is_palindrome(s)) cout << " not";
	//	cout << " a palindrome\n";
	//}

	//constexpr int max = 128;
	//for (char s[max]; read_word(cin, s, max);) {
	//	cout << s << " is";
	//	if (!is_palindrome(s, strlen(s))) cout << " not";
	//	cout << " a palindrome\n";
	//}

	const int max = 128;
	for (char s[max]; read_word(cin, s, max);) {
		cout << s << " is";
		if (!is_palindrome(&s[0], &s[strlen(s) - 1])) cout << " not";
		cout << " a palindrome\n";
	}
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return 3;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 2;
}
catch (...) {
	cerr << "error!" << endl;
	return 1;
}


