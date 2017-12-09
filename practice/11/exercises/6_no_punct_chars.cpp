
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_punct(char c)
{
	switch (c) {
	case '.':
	case ',':
	case '?':
	case '-':
	case '\'':
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------

void toggle_quotes(bool& in_quotes)
{
	if (in_quotes)
		in_quotes = false;
	else
		in_quotes = true;
}

//------------------------------------------------------------------------------

string cut_punct(string str)		// yes! copy of the string
{
	bool in_quotes = false;
	for (char& ch : str) {
		if (ch == '"')
			toggle_quotes(in_quotes);

		if (!in_quotes && ch != '"' && is_punct(ch))
			ch = ' ';
	}

	return str;
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin{iname};
	if (!fin)
		error("can't open input file ", iname);

	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname};
	if (!fout)
		error("can't open output file ", oname);

	for (string s; getline(fin, s);)
		fout << cut_punct(s);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

