
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_whitespace(const string& white, char c)
{
	for (char ch : white)
		if (c == ch)
			return true;
	return false;
}

//------------------------------------------------------------------------------

vector<string> split(string s, const string& whitespaces)
{
	for (char& ch : s)
		if (is_whitespace(whitespaces, ch))
			ch = ' ';

	istringstream iss{s};
	vector<string> vec;
	for (string word; iss >> word;)
		vec.push_back(word);
	return vec;
}

//------------------------------------------------------------------------------

int main()
{
	cout << "Enter a string:\n";
	string str;
	getline(cin, str);

	vector<string> vec = split(str, ",.");
	cout << "Split:\n";
	for (const string& x : vec)
		cout << x << '\n';
}

//------------------------------------------------------------------------------

