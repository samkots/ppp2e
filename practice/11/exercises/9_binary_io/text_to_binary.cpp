
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin{iname};
	if (!fin)
		error("can't open input file ", iname);

	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname, ios_base::binary};
	if (!fout)
		error("can't open input file ", oname);

	for (int n; fin >> n;)
		fout.write(as_bytes(n), sizeof(int));
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

