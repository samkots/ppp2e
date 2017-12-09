
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void count_chars(const vector<string>& vec, vector<int>& chars)
{
	if (chars.size() != 0)
		error("resulting vector must be empty");

	for (const string& s : vec)
		chars.push_back(s.size());
}

//------------------------------------------------------------------------------

string longest_string(const vector<string>& vec)
{
	string longest = vec[0];
	for (int i = 0; i < vec.size(); ++i)
		if (longest.size() < vec[i].size())
			longest = vec[i];
	return longest;
}

//------------------------------------------------------------------------------

string shortest_string(const vector<string>& vec)
{
	string shortest = vec[0];
	for (int i = 0; i < vec.size(); ++i)
		if (shortest.size() > vec[i].size())
			shortest = vec[i];
	return shortest;
}

//------------------------------------------------------------------------------

int main()
try
{
	vector<string> colors {
		"red", "blue", "yellow", "green", "orange"
	};

	vector<int> chars;
	count_chars(colors, chars);

	for (int i = 0; i < colors.size(); ++i)
		cout << colors[i] << ": " << chars[i] << '\n';

	cout << "longest: " << longest_string(colors) << '\n';
	cout << "shortest: " << shortest_string(colors) << '\n';

	sort(colors);

	cout << "lexicographically first: " << colors[0] << '\n';
	cout << "lexicographically last: " << colors[colors.size() - 1] << '\n';
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

