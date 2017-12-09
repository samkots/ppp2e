
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

	int sum = 0;
	for (int n = 0; fin >> n;)
		sum += n;
	if (fin.fail() && sum == 0)
		error("bad file");

	cout << "sum of all numbers: " << sum << '\n';
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

