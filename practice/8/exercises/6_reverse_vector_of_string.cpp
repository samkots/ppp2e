
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print(const string& label, vector<string>& vec)
	// print the label and then the strings...
{
	cout << label << ":\n";
	for (const string& s: vec)
		cout << s << '\n';
}

//------------------------------------------------------------------------------

void reverse(const vector<string>& vec, vector<string>& reversed)
	// copy strings in vec to reversed in reversed order...
{
	if (reversed.size() != 0)
		error("resulting vector must e empty");

	for (int i = vec.size() - 1; i >= 0; --i)
		reversed.push_back(vec[i]);
}

//------------------------------------------------------------------------------

void reverse(vector<string>& vec)
	// reverse the strings in vec in reversed orded...
{
	for (int i = 0, j = vec.size() - 1; i < j; ++i, --j)
		swap(vec[i], vec[j]);
}

//------------------------------------------------------------------------------

int main()
try
{
	vector<string> countries = {
		"India", "France", "Italy", "Germany", "Denmark"
	};

	print("some countries", countries);

	vector<string> reversed;
	reverse(countries, reversed);
	print("reversed copy", reversed);

	reverse(countries);
	print("reversed in place", countries);
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

