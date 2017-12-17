
//
// The palindrome program(array-version) in section 18.7.2 works only on fixed
// size(128) buffer.
// This code fixes it by throwing an error when the input string is too long
// to be held by the buffer
//
// comment on complexity of fixing code:
//	simply throwing an error is simple.
//	few changes were required in the existing code.
//

#include "ppp/std_lib_facilities.h"


bool is_palindrome(const char s[], int n)
{
	int first = 0;
	int last = n - 1;
	while (first < last) {
		if (s[first] != s[last])
			return false;
		++first;
		--last;
	}

	return true;
}

istream& read_word(istream& is, char* buffer, int max)
	// read at most max - 1 characters from is into buffer
{
	int i = 0;
	for (char c; is.get(c); ++i) {
		if (isspace(c))
			break;

		if (i == max - 1)
			error("word too long");

		buffer[i] = c;
	}

	buffer[i] = 0;

	if (i == 0)
		is.clear(ios_base::failbit);

	return is;
}

int main() try
{
	constexpr int max = 4;
	for (char s[max]; read_word(cin, s, max);) {
		cout << s << " is";
		if (!is_palindrome(s, strlen(s)))
			cout << " not";
		cout << " a palindrome\n";
	}
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 2;
}
catch (...) {
	cerr << "error!" << endl;
	return 3;
}


