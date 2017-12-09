
//
// The palindrome program(array-version) in section 18.7.2 works only on fixed
// size(128) buffer.
// This code is fixes it by reallocating the buffer into a bigger one.
//
// comment on complexity of fixing code:
//	New function added for reallocating the buffer.
//	Unlike previous solution, more changes int the existing code were
//	requred.
//	Had to deal with pointer details.
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

char* relocate(char* buffer, int n, int* new_n)
{
	if (!buffer)
		error("relocate(): invalid argument: buffer");

	if (!new_n)
		error("relocate(): invalid argument: new_n");

	char* p = new char[*new_n = n + 4];

	for (int i = 0; i < n; ++i)
		p[i] = buffer[i];

	p[n] = 0;

	delete[] buffer;
	return p;
}

istream& read_word(istream& is, char** buffer, int max)
	// read at most max - 1 characters from is into buffer
{
	if (!buffer|| !(*buffer))
		error("invalid argument: buffer");

	int i = 0;
	for (char c; is.get(c); ++i) {
		if (isspace(c))
			break;

		if (i == max - 1) {
			(*buffer) = relocate(*buffer, max, &max);
		}

		(*buffer)[i] = c;
	}

	(*buffer)[i] = 0;

	if (i == 0)
		is.clear(ios_base::failbit);

	return is;
}

int main() try
{
	constexpr int max = 4;
	char* s = new char[max];
	while (read_word(cin, &s, max)) {
		cout << s << " is";
		if (!is_palindrome(s, strlen(s)))
			cout << " not";
		cout << " a palindrome\n";
	}

	delete[] s;
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


