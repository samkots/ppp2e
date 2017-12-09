
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Entry {
	string last_name;
	string first_name;
	long int phone;
	string email;
};

//------------------------------------------------------------------------------

int main()
{
	vector<Entry> table;
	table.push_back(Entry{"Kots", "Sam", 9876543210, "sam@gmail.com"});
	table.push_back(Entry{"Sule", "Shashi", 9876543211, "djshashi@yahoo.com"});
	table.push_back(Entry{"Tejas", "Josh", 9876543212, "teja@bheja.com"});
	table.push_back(Entry{"Rohit", "Kulux", 9876543213, "rhk@linux.com"});
	table.push_back(Entry{"Pranav", "Awaratade", 9876543214, "pran_aw@tade.com"});

	cout	<< setw(15) << "last name"
		<< setw(15) << "first name"
		<< setw(15) << "phone"
		<< setw(25) << "email"
		<< '\n';

	cout << '\n';

	for (const Entry& e: table)
		cout	<< setw(15) << e.last_name
			<< setw(15) << e.first_name
			<< setw(15) << e.phone
			<< setw(25) << e.email
			<< '\n';
}

//------------------------------------------------------------------------------

