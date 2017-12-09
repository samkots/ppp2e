
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void reverse_put(istream& is, ostream& os)
{
	string s;
	for (char c = 0; is.get(c);)
		s += c;

	for (int i = s.size() - 1; i >= 0; --i)
		os << s[i];
}

//------------------------------------------------------------------------------

int main()
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
	ofstream fout{oname};
	if (!fout)
		error("can't open input file ", oname);

	reverse_put(fin, fout);
}

//------------------------------------------------------------------------------

