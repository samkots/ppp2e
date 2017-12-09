
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void concatinate(istream& is1, istream& is2, ostream& os)
{
	for (char c = 0; is1.get(c);)
		os << c;

	for (char c = 0; is2.get(c);)
		os << c;
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter first file name: ";
	string iname1;
	cin >> iname1;
	ifstream fin1{iname1};
	if (!fin1)
		error("can't open input file: ", iname1);

	cout << "Enter second file name: ";
	string iname2;
	cin >> iname2;
	ifstream fin2{iname2};
	if (!fin2)
		error("can't opem input file: ", iname2);

	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname};
	if (!fout)
		error("can't open output file: ", oname);

	concatinate(fin1, fin2, fout);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

