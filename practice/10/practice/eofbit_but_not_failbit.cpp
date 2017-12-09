
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	ifstream input("int_file");		// must contain only an int followed by eof
	if (!input)
		return -1;

	int i = 1234;
	input >> i;
	cout << i << endl;

	if (input)
		cout << "good" << endl;
	if (input.eof())
		cout << "eof" << endl;
	if (input.fail())
		cout << "fail" << endl;
	if (input.bad())
		cout << "bad" << endl;
}

