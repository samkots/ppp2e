
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin{iname, ios_base::binary};
	if (!fin)
		error("Can't open input file: ", iname);

	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname, ios_base::binary};
	if (!fout)
		error("Can't open output file:", oname);

	vector<int> vec;

	for (int n = 0; fin.read(as_bytes(n), sizeof(int));)
		vec.push_back(n);

	cout << "read " << vec.size() << " numbers.\n";

	for (int x : vec)
		fout.write(as_bytes(x), sizeof(int));
}

//------------------------------------------------------------------------------

