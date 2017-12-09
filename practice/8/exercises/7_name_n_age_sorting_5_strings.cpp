
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print_name_age(const vector<string>& names, const vector<int>& ages)
	// pritn the names with their ages
{
	if (names.size() != ages.size())
		error("sizes of names and ages mismatch!");

	for (int i = 0; i < names.size(); ++i)
		cout << names[i] << '(' << ages[i] << ")\n";
}

//------------------------------------------------------------------------------

int search(const vector<string>& vec, string s)
	// return index of the string
{
	for (int i = 0; i < vec.size(); ++i)
		if (vec[i] == s)
			return i;

	error (s, " not fond in the vector");
}

//------------------------------------------------------------------------------

void sort(vector<string>& names, vector<int>& ages)
	// sort both vectors with respect to names
{
	vector<string> names_copy = names;		// make a copy of both
	vector<int> ages_copy = ages;

	sort(names.begin(), names.end());		// sort the names

	for (int i = 0; i < names.size(); ++i) {	// one bye one,
		int pos = search(names_copy, names[i]);	// search sorted string's old position
		ages[i] = ages_copy[pos];		// take old age at that position and copy into new ages
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	const int size = 5;
	vector<string> names;

	cout << "Enter " << size << " names:\n";
	for (int i = 0; i < size; ++i) {
		string name;
		cin >> name;			// get some names
		names.push_back(name);
	}

	vector<int> ages(size);			// store their ages of each person
	cout << "Now ente their ages:\n";
	for (int i = 0, age = 0; i < size; ++i) {
		cin >> age;
		ages[i] = age;
	}

	sort(names, ages);				// sort both with respect to names

	print_name_age(names, ages);			// print both
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------

