
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

	vector<int> numbers;
	for (int num = 0; fin >> num;)
		numbers.push_back(num);

	sort(numbers);

	// :o
	for (int i = 0, count = 0; i < numbers.size(); ++i) {
		if (i != 0 && numbers[i] != numbers[i - 1]) {
			cout << numbers[i - 1] << '\t';
			(count > 1) ? cout << count << '\n' : cout << '\n';
			count = 1;
		} else {
			++count;
		}

		if (i == numbers.size() - 1) {
			cout << numbers[i];
			(count > 1) ? cout << count << '\n' : cout << '\n';
		}
	}
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

