
#include "std_lib_facilities.h"


class Name_value {
public:
	string name;
	double value;
};


bool exists(vector<Name_value> vec, string name)
{
	for (auto x : vec)
		if (name == x.name)
			return true;

	return false;
}

int main()
try
{
	vector<Name_value> vec;

	for (Name_value nv; cin >> nv.name >> nv.value;) {
		if (exists(vec, nv.name))
			error(nv.name, " already exists");

		if (nv.name == "NoName" && nv.value == 0)
			break;

		vec.push_back(nv);
	}

	cout << "--------------------\n";

	for (auto x : vec)
		cout << x.name << ": " << x.value << '\n';
}
catch (runtime_error x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "oops! unknown error" << '\n';
}

