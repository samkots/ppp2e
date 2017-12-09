
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print_until_s(const vector<string>& v, const string& quit)
{
	for (const string& s : v) {
		if (s == quit)
			return;
		cout << s << '\n';
	}
}

//------------------------------------------------------------------------------

void print_until_ss(const vector<string>& v, const string& quit)
{
	int count = 0;
	for (const string& s : v) {
		if (s == quit) {
			++count;
			if (count == 2)
				return;
		}
		cout << s << '\n';
	}
}

//------------------------------------------------------------------------------

int main()
{
	vector<string> colors {
		"orange", "yellow", "red", "black", "blue",
		"pink", "green", "violet", "red", "black", "gold", "brown"
	};

	print_until_s(colors, "black");
	cout << "-----\n";
	print_until_ss(colors, "black");
}

//------------------------------------------------------------------------------

