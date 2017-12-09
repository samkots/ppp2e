
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int maxv(const vector<int>& v)
{
	if (v.size() == 0)
		error("vector empty");

	int max = v[0];
	for (int i = 1; i < v.size(); ++i)
		if (v[i] > max)
			max = v[i];

	return max;
}

//------------------------------------------------------------------------------

int main()
try
{
	vector<int> vec = {1, 7, 9, 3, 7, 0, 4, 2};
	cout << "max element: " << maxv(vec) << '\n';
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

