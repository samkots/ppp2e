
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter input file name:\n";
	string iname;
	cin >> iname;
	ifstream fin{iname};
	if (!fin)
		error("can't open input file ", iname);
	fin.exceptions(fin.exceptions() | ios_base::badbit);

	cout << "Enter output file name:\n";
	string oname;
	cin >> oname;
	ofstream fout{oname};
	if (!fout)
		error("can't open output file ", oname);
	fout.exceptions(fout.exceptions() | ios_base::badbit);

	for (char c = 0; fin.get(c);) {
		c = tolower(c);
		fout << c;
	}
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

