
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct reading {		// a termperature reading
	int hour;		// hours after midnight [0:23]
	double temperature;	// in Fahrenheit
};

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist {iname};	// ist reads from the file named `iname`
	if (!ist)
		error("can't open input file ", iname);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ost {oname};	// ost writes to a file named `oname`
	if (!ost)
		error("can't open output file ", oname);

	vector<reading> temps;	// store the readings here
	int hour;
	double temperature;
	while (ist >> hour >> temperature) {
		if (hour < 0 || 23 < hour)
			error("hour out of range");
		temps.push_back(reading{hour, temperature});
	}

	for (int i = 0; i < temps.size(); ++i)
		ost << '(' << temps[i].hour << ", " << temps[i].temperature << ")\n";
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return -1;
}

//------------------------------------------------------------------------------

