
//------------------------------------------------------------------------------

#include "../std_lib_facilities.h"
#include "Reading.h"

//------------------------------------------------------------------------------

int main()
try
{
	// open a file for writting
	ofstream fout{"raw_temps.txt"};
	if (!fout)
		error("can't open output file ");

	// write some temperatures to the file
	double randome = 4.7;
	for (int i = 0; i < 50; ++i) {
		Reading r{i % 24, randome * ((i+1) / 3.0) * 6, 'c'};	// calculate "randome" temperature
		fout << r << '\n';
	}
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

