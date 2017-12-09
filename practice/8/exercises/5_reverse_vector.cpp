
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print(const string& label, const vector<int>& vec)
	// from exercise 2
{
	cout << label << ":\n";
	for (const int n : vec)
		cout << n << '\n';
}

//------------------------------------------------------------------------------

void reverse_vector(const vector<int>& vec, vector<int>& reversed)
{
	if (reversed.size() != 0)
		error("Resulting vector must be empty");

	for (int i = vec.size() - 1; i >= 0; --i)
		reversed.push_back(vec[i]);
}

//------------------------------------------------------------------------------

void reverse_vector(vector<int>& vec)
{
	for (int i = 0, j = vec.size() -1; i < j; ++i, --j)
		swap(vec[i], vec[j]);
}

//------------------------------------------------------------------------------

int main()
try
{
	vector<int> v = {1, 3, 5, 7, 9};
	print("a vector", v);

	vector<int> reversed;
	reverse_vector(v, reversed);
	print("reversed copy", reversed);

	reverse_vector(v);
	print("reversed in place", v);
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

