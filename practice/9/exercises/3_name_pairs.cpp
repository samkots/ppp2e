
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
	const vector<string>& get_names() const { return names; }
	const vector<double>& get_ages() const { return ages; }
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

ostream& operator<<(ostream& os, const Name_pairs& pairs)
	// pre-condition: names.size() == ages.size()
{
	if (pairs.get_names().size() != pairs.get_ages().size())
		error("invalid state");

	for (int i = 0; i < pairs.get_names().size(); ++i)
		os << pairs.get_names()[i] << "(" << pairs.get_ages()[i] << ")\n";

	return os;
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
	cout << "names you entered:\n";
	cout << pairs << '\n';
	pairs.sort_names();
	cout << "sorted names:\n";
	cout << pairs << '\n';
	cout << pairs << '\n';
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << "!\n";
	return -1;
}

//------------------------------------------------------------------------------

