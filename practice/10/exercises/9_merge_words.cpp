
//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void merge(istream& is1, istream& is2, ostream& os)
{
	while (true) {
		string word;
		is1 >> word;
		//if (is1.eof()) {
		//	write(is2, os);
		//	return;
		//}

		os << word << ' ';

		is2 >> word;
		//if(is2.eof()) {
		//	write(is1, os);
		//	return;
		//}

		os << word << ' ';

		if (is1.eof() && is2.eof())
			return;
	}
}

//------------------------------------------------------------------------------

int main()
{
	cout << "enter file 1: ";
	string iname1;
	cin >> iname1;
	ifstream fin1{iname1};
	if (!fin1)
		error("can't open input file ", iname1);

	cout << "enter file 2: ";
	string iname2;
	cin >> iname2;
	ifstream fin2{iname2};
	if (!fin2)
		error("can't open input file ", iname2);

	cout << "enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname};
	if (!fout)
		error("can't open output file ", oname);

	fin1.exceptions(fin1.exceptions() | ios_base::badbit);
	fin2.exceptions(fin2.exceptions() | ios_base::badbit);
	fout.exceptions(fout.exceptions() | ios_base::badbit);

	merge(fin1, fin2, fout);
}

//------------------------------------------------------------------------------

