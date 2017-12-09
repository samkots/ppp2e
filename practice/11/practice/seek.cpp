
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
	string file_name = "sample_file";
	fstream fs {file_name};
	if (!fs)
		error("can't open ", file_name);

	fs.seekg(5);
	char ch;
	fs >> ch;
	cout << "character[5] is " << ch << '(' << int(ch) << ")\n";

	fs.seekp(1);
	fs << 'y';
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------

