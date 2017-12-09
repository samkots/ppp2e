
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<string> split(const string& s)
{
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

	vector<string> vec = split(str);
	cout << "Split:\n";
	for (const string& x : vec)
		cout << x << '\n';
}

//------------------------------------------------------------------------------

