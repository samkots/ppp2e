
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin{iname, ios_base::binary};
	if (!fin)
		error("can't open input file ", iname);

	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname};
	if (!fout)
		error("can't open input file ", oname);

	for (int n; fin.read(as_bytes(n), sizeof(int));)
		fout << n << ' ';
	fout << '\n';
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

