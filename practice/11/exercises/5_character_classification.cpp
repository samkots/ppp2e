
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool contains(const string& str, char ch)
{
	for (char c : str)
		if (ch == c)
			return true;
	return false;
}

//------------------------------------------------------------------------------

string cut_duplicates(const string& str)
{
	string ret;
	for (char c : str) {
		if (!contains(ret, c))
			ret += c;
	}

	return ret;
}

//------------------------------------------------------------------------------

string yes_or_no(int n)
{
	if (0 == n)
		return "no";
	return "yes";
}

//------------------------------------------------------------------------------

void print_classification(char ch, int filed)
{
	cout	<< setw(filed) << ch
		<< setw(filed) << yes_or_no(isspace(ch))
		<< setw(filed) << yes_or_no(isalpha(ch))
		<< setw(filed) << yes_or_no(isdigit(ch))
		<< setw(filed) << yes_or_no(isalnum(ch))
		<< setw(filed) << yes_or_no(isxdigit(ch))
		<< setw(filed) << yes_or_no(isupper(ch))
		<< setw(filed) << yes_or_no(islower(ch))
		<< setw(filed) << yes_or_no(iscntrl(ch))
		<< setw(filed) << yes_or_no(ispunct(ch))
		<< setw(filed) << yes_or_no(isprint(ch))
		<< setw(filed) << yes_or_no(isgraph(ch))
		<< '\n';
}

//------------------------------------------------------------------------------

int main()
try
{
	constexpr int filed = 12;

	cout << "Enter a string:\n";
	string s;
	getline(cin, s);

	// table header
	cout	<< setw(filed) << "char"
		<< setw(filed) << "space"
		<< setw(filed) << "alpha"
		<< setw(filed) << "digit"
		<< setw(filed) << "alnum"
		<< setw(filed) << "xdigit"
		<< setw(filed) << "upper"
		<< setw(filed) << "lower"
		<< setw(filed) << "cntrl"
		<< setw(filed) << "punct"
		<< setw(filed) << "print"
		<< setw(filed) << "graph"
		<< '\n';

	string unique_chars = cut_duplicates(s);
	for (char c : unique_chars)
		print_classification(c, filed);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

