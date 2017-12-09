
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct reading {
	int hour;		// [0:23]
	double temperature;	// in Fahrenheit
};

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin(iname);
	if (!fin)
		error("failed to open input file ", iname);

	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout(oname);
	if (!fout)
		error("failed to open output file ", oname);

	vector<reading> readings;
	int hour = 0;
	double temperature = 0;
	while (fin >> hour >> temperature) {
		if (hour < 0 || 23 < hour)
			error("invalid hour");
		readings.push_back(reading{hour, temperature});
	}

	for (const reading& r : readings)
		fout << '(' << r.hour << ", " << r.temperature << ")\n";
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------

