
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void end_of_loop(istream& is, char terminator = 0, const string& error_msg = {})
{
cerr << "..." << endl;
	if (is.good())
cerr << "goodbit" << endl;

	if (is.eof())
cerr << "eofbit" << endl;

	if (is.fail()) {
cerr << "failbit" << endl;
		is.clear();
		if (terminator == 0)
			return;
		char ch;
		if (is >> ch && ch == terminator) return;		// fine
		error(error_msg);
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	ifstream fin("ints");
	fin.exceptions(fin.exceptions() | ios_base::badbit);
	//cin.exceptions(cin.exceptions() | ios_base::badbit);

	vector<int> vec;
	for (int i; fin >> i;) {
		//vec.emplace_back(i);
		cout << ">> " << i << endl;
		cout << ">>>>>>>>>>>>>>> " << fin.eof() << endl;
	}
	end_of_loop(fin, 0, "bad terminator");

	// eof; carry on...

	for (int x : vec)
		cout << x << endl;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------

