
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

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v.push_back(x);
	v.push_back(y);
	for (int i = 2; i < n; ++i)
		v.push_back(v[i-1] + v[i-2]);
}

//------------------------------------------------------------------------------

int main()
{
	cout << "Enter max number of fibonacci numbers you want(at least 2): ";
	int n;
	cin >> n;
	vector<int> fibs;
	fibonacci(1, 2, fibs, n);
	print("Some fionacci numbers", fibs);
}

//------------------------------------------------------------------------------

