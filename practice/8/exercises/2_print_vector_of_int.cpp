
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print(const string& label, const vector<int>& vec)
{
	cout << label << ":\n";
	for (const int n : vec)
		cout << n << '\n';
}

//------------------------------------------------------------------------------

int main()
{
	vector<int> vec = {1,2,3,4,5};
	print("Some numbers", vec);
}

//------------------------------------------------------------------------------

