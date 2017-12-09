
/*
	Remove all the vowels from the given file.

	algo:

	open input file
	open output file
	read each character.
	if it's not a vowel, write to the output file
*/


#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void disemvowels(istream& in, ostream& os)
{
	for (char c = 0; in.get(c);) {
		c = tolower(c);
		if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
			os << c;
	}
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
		error("can't open output file ", oname);

	disemvowels(fin, fout);
}

//------------------------------------------------------------------------------

