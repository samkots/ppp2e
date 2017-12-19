
#include "ppp/std_lib_facilities.h"

using namespace std;

///

template <typename T, typename U>
	// requires: int operator * (T, U)
int sum(const vector<T>& a, const vector<U>& b)
{
	int size = a.size();
	if (b.size() < size)
		size = b.size();

	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += a[i] * b[i];

	return sum;
}

///

int main() try
{
	vector<int> a{1, 2, 3, 4};
	vector<int> b{10, 20, 30, 40, 50};

	cout << "sum: " << sum(a, b) << endl;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return 1;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return 3;
}
catch (...) {
	cerr << "error!\n";
	return 3;
}

// // //
