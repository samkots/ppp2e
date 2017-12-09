
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

/*
	This program takes several numbers in any combination of octal, decimal
	or hexadecimal and them using the 0 and 0x base suffix; interprets the
	numbers correctly; and converts them to decimal form
*/

//------------------------------------------------------------------------------

int to_number(const string& s)
{
	istringstream iss{s};
	iss.unsetf(ios_base::dec);
	iss.unsetf(ios_base::hex);
	iss.unsetf(ios_base::oct);
	int n;
	iss >> n;
	if (!iss)
		error("number format error: ", s);
	return n;
}

//------------------------------------------------------------------------------

string base(const string& s)
{
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		return "hexadecimal";
	if (s[0] == '0')
		return "octal";
	return "decimal";
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter numbers in decimal, octal of hexadecimal form:\n";

	vector<string> numbers;

	for (string num; cin >> num;)
		numbers.push_back(num);

	for (string s : numbers) try {
		cout	<< s << '\t' << base(s)
			<<"\tconverts to\t" << to_number(s) << " decimal\n";
	} catch(const runtime_error& x) {
		cerr << x.what() << '\n';
	}
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

