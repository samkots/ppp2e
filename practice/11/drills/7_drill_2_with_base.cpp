
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	int birth_year = 1992;
	int age = 22;

	cout	<< "My birth year:\n"
		<< showbase << birth_year << '\n'
		<< hex << birth_year << '\n'
		<< oct << birth_year << '\n';

	cout << "age: " << dec << age << '\n';
}

//------------------------------------------------------------------------------

