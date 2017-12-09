
//
// ppp, chapter 9 exercise 2, pg 339
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// simple class that maintains names of people with their ages
class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print();
	void sort_names();

private:
	vector<string> names;		// set of names
	vector<double> ages;		// respective ages
};

//------------------------------------------------------------------------------

void Name_pairs::read_names()
{
	cout << "Enter names of people (x to stop)...\n";
	for (string name; cin >> name;) {
		if (name == "x")
			break;

		names.push_back(name);
	}
}

//------------------------------------------------------------------------------

void Name_pairs::read_ages()
{
	cout << "Enter age for each person:\n";
	for (int i = 0; i < names.size(); ++i) {
		cout << names[i] << ": ";
		int age = 0;
		cin >> age;
		ages.push_back(age);
	}
}

//------------------------------------------------------------------------------

void Name_pairs::print()
	// pre-condition: names.size() == ages.size()
{
	if (names.size() != ages.size())
		error("invald state");

	cout << "Names of people with their ages....\n";
	for (int i = 0; i < names.size(); ++i)
		cout << names[i] << "(" << ages[i] << ")\n";
}

//------------------------------------------------------------------------------

int find_name(const vector<string>& names, string name);	// forward declaration

//------------------------------------------------------------------------------

void Name_pairs::sort_names()
	// pre-condition: names.size() == ages.size()
{
	if (names.size() != ages.size())
		error("invalid state");

	vector<string> names_copy = names;		// take backup of old order
	vector<double> ages_copy = ages;
	sort(names.begin(), names.end());

	//
	// algo:
	//
	// for each name in sorted vector,
	//	ages of that name = ages of the name in old copy 
	//
	for (int i = 0; i < names.size(); ++i) {
		int pos = find_name(names_copy, names[i]);	// get the old position of the name
		ages[i] = ages_copy[pos];			// get the ages at old position
	}
}

//------------------------------------------------------------------------------

int find_name(const vector<string>& names, string name)
{
	for (int i = 0; i <names.size(); ++i)
		if (name == names[i])
			return i;

	error("name not found");
}

//------------------------------------------------------------------------------

int main()
try
{
	Name_pairs pairs;
	pairs.read_names();
	pairs.read_ages();
	pairs.print();
	pairs.sort_names();
	cout << '\n';
	pairs.print();
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << "!\n";
	return -1;
}

//------------------------------------------------------------------------------

