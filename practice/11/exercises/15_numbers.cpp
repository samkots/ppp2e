
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

	vector<double> vec;
	for (double d = 0; fin >> d;)
		vec.push_back(d);

	fout << scientific << setprecision(8);
	for (int i = 0; i < vec.size(); ++i) {
		if (i % 4 == 0)
			fout << '\n';
		fout << setw(20) << vec[i];
	}
	fout << '\n';
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

