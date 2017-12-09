
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_punct(char c)
{
	switch (c) {
	case '.':
	case ',':
	case '?':
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

string cut_punct(string str)
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

string cut_isolated_dashes(string str)		// work on a copy of the string
{
	if (str[0] == '-')
		str[0] = ' ';

	if (str[str.size() - 1] == '-')
		str[str.size() - 1] = ' ';

	for (int i = 1; i < str.size() - 1; ++i)
		if (str[i] == '-' && !isalnum(str[i - 1]) && !isalnum(str[i + 1]))
			str[i] = ' ';

	return str;
}

//------------------------------------------------------------------------------

string replace(const string& str)
{
	if (str == "don't")
		return "do not";
	else if (str == "can't")
		return "cannot";
	else if (str == "isn't")
		return "is not";
	else if (str == "hasn't")
		return "has not";
	else if (str == "won't")
		return "will not";
	else
		return str;
}

//------------------------------------------------------------------------------

string replace_apostroph(const string& s)
{
	istringstream iss{s};

	string ret;
	for (char c = 0; iss.get(c);) {
		if (!isspace(c)) {
			iss.putback(c);
			string word;
			iss >> word;
			word = replace(word);
			ret += word;
		} else 
			ret += c;
	}

	return ret;
}

//------------------------------------------------------------------------------

string cut_punct_smart(string str)
{
	str = cut_punct(str);
	str = cut_isolated_dashes(str);
	str = replace_apostroph(str);
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
		fout << cut_punct_smart(s) << '\n';
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

