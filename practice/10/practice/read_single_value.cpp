
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void skip_to_int()
{
	if (cin.fail()) {
		cin.clear();
		for (char c; cin >> c; )
			if (isdigit(c) || c == '-') {
				cin.unget();
				return;
			}
	}
	error("no input");		// eof or bad; give up
}

//------------------------------------------------------------------------------

int get_int()
{
	int n = 0;
	while (true) {
		if (cin >> n)
			return n;
		cout << "Sorry, that wasn't a number; please try again\n";
		skip_to_int();
	}
}

//------------------------------------------------------------------------------

int get_int(int low, int high)
{
	cout << "Please enter a number in the range "
		<< low << " to " << high << " (inclusive):\n";

	while (true) {
		int n = get_int();
		if (low <= n && n <= high)
			return n;
		cout << "Sorry " << n
			<< " is not in the [" << low << ":" << high << "] range; "
			<< "please try again\n";
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	cin.exceptions(cin.exceptions() | ios_base::badbit | ios_base::eofbit);
	int n = get_int(1, 10);
	cout << n << endl;
}
catch (const ios_base::failure& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------

