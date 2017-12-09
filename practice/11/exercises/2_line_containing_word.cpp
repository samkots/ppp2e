
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

/*
	algo:

	open the file
	get the word
	count = 1
	for each line
		if word is in line
			print count
			print line
		++count
*/

//------------------------------------------------------------------------------

bool contains_word(const string& str, const string& word)
{
	istringstream iss{str};
	for (string s; iss >> s;)
		if (word == s)
			return true;
	return false;
}

//------------------------------------------------------------------------------

void print_lines(istream& is, const string& word)
{
	int line_number = 1;
	for (string line; getline(is, line); ++line_number)
		if (contains_word(line,word))
			cout << line_number << ':' << line << '\n';
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter the file name:\n";
	string fname;
	cin >> fname;
	ifstream fin{fname};
	if (!fin)
		error("can't open file ", fname);

	cout << "enter word to find:\n";
	string word;
	cin >> word;

	print_lines(fin, word);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

