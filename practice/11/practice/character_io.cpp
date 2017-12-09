
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin{iname};
	if (!fin)
		error("Can't open input file: ", iname);
	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname};
	if (!fout)
		error("Can't open output file:", oname);

	vector<int> vec;

	for (int n = 0; fin >> n;)
		vec.push_back(n);
	// no need of end_of_input() here

	for (int x : vec)
		fout << x << ' ';
}

//------------------------------------------------------------------------------

