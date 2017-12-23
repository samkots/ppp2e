
#include "ppp/std_lib_facilities.h"

using namespace std;

///

template <typename T, typename U>
struct Pair {
	T	first;
	U	second;
};

///

class Symbol_table {
public:
	void define_name(const string& name, double val = 0.0);
	bool is_declared(const string& name) const;
	double get_value(const string& name) const;
	void set_value(const string& name, double val = 0.0);

	void print() const;

private:
	vector<Pair<string, double>> tab_;
};

///

void Symbol_table::define_name(const string& name, double val)
{
	if (is_declared(name))
		error("redefined: ", name);
	tab_.push_back({name, val});
}

///

bool Symbol_table::is_declared(const string& name) const
{
	for (int i = 0; i < tab_.size(); ++i)
		if (tab_[i].first == name)
			return true;
	return false;
}

///

double Symbol_table::get_value(const string& name) const
{
	for (int i = 0; i < tab_.size(); ++i)
		if (tab_[i].first == name)
			return tab_[i].second;

	error("undefined name: ", name);
}

///

void Symbol_table::set_value(const string& name, double val)
{
	for (int i = 0; i < tab_.size(); ++i)
		if (tab_[i].first == name) {
			tab_[i].second = val;
			return;
		}
	error("undefined name: ", name);
}

///

void Symbol_table::print() const
{
	for (int i = 0; i < tab_.size(); ++i)
		cout << tab_[i].first << "\t\t" << tab_[i].second << '\n';
}

///

int main() try
{
	//Pair<string, int> p {"Hello, World", 10};
	//cout << p.first <<'\n';
	//cout << p.second <<'\n';

	Symbol_table symtab;

	symtab.define_name("abc", 1.2);
	symtab.define_name("def", 2.4);
	symtab.define_name("xyz", 3.6);

	symtab.set_value("xyz", 9.9);
	cout << "xyz: " << symtab.get_value("xyz") << '\n';

	//double boom = symtab.get_value("boom!");
	//symtab.set_value("bang!", 0.0);
	//symtab.define_name("xyz");

	symtab.print();
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return 3;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return 2;
}
catch (...) {
	cerr << "error!\n";
	return 1;
}

// // //
