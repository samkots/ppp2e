
#include "ppp/std_lib_facilities.h"

using namespace std;

///

template <typename T>
void print(const vector<T>& v)
{
	cout << "{";
	for (int i = 0; i < v.size(); ++i) {
		cout << ' ' << v[i];
		if (i != v.size() - 1) cout << ",";
	}
	cout << " }\n";
}

///

template <typename T>
void f(vector<T>& a, const vector<T>& b)
{
	int size = a.size();
	if (b.size() < a.size())
		size = b.size();

	for (int i = 0; i < size; ++i)
		a[i] += b[i];
}

///

int main() try
{
	vector<int> a{1, 2, 3, 4};
	vector<int> b{10, 20};

	f(a, b);
	print(a);

	f(b, a);
	print(b);
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 2;
}
catch (...) {
	cerr << "error!" << endl;
	return 3;
}


