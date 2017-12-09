
#include "std_lib_facilities.h"


//------------------------------------------------------------------------------

int compose_integer(vector<int> vec)
{
	int sum = vec[0];
	for (int i = 1 ; i < vec.size(); ++ i) {
		sum *= 10;
		sum += vec[i];
	}

	return sum;
}

//------------------------------------------------------------------------------

int main()
try
{
	vector<string> places;
	places.push_back("ones");
	places.push_back("tens");
	places.push_back("hundreds");
	places.push_back("thousands");
	places.push_back("tens of thousands");
	places.push_back("hundreds of thousand");
	places.push_back("milliions");
	places.push_back("tens of milliions");
	places.push_back("hundreds of milliions");

	cout << "Enter some digits followed by a ';': ";

	vector<int> digits;
	for (char ch; cin >> ch;) {
		if (ch == ';')
			break;

		if (ch < '0' || '9' < ch)
			error("invalid digit");

		digits.push_back(ch - '0');
	}

	if (digits.size() == 0)
		error("no digits");

	if (digits.size() > places.size()) {
		cout	<< "Please enter no more than "
			<< places.size() << " digits\n";
		return -1;
	}

	cout << compose_integer(digits) << " ";
	for (int i = 0; i < digits.size(); ++i) {
		cout << digits[i] << ' ' << places[digits.size() - 1 - i] << ' ';
	}
	cout << '\n';
}
catch (runtime_error x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "oops!\n";
	return -1;
}

//------------------------------------------------------------------------------

