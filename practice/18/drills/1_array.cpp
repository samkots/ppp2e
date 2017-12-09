
#include "ppp/std_lib_facilities.h"


int ga[10] {1, 2, 4, 8, 16, 6, 12, 14};


void f(int* a, int n)
{
	int la[10];

	// copy
	for (int i = 0; i < n; ++i)
		la[i] = a[i];

	// print
	cout << "local array:\n";
	cout << "[ ";
	for (int i = 0; i < n; ++i) {
		cout << la[i];
		if (i != n - 1)
			cout << ", ";
	}
	cout << " ]\n";

	// on the free store
	int* p = new int[n];

	// copy
	for (int i = 0; i < n; ++i)
		p[i] = a[i];

	// print
	cout << "array on the free store:\n";
	cout << "[ ";
	for (int i = 0; i < n; ++i) {
		cout << p[i];
		if (i != n - 1)
			cout << ", ";
	}
	cout << " ]\n";

	// deallocate
	delete[] p;
}


//template <int n>										// :p
//struct fact {
//	static constexpr int val = n * fact<n - 1>::val;
//};
//
//template<>
//struct fact<1> {
//	static constexpr int val = 1;
//};
//
//template<>
//struct fact<0> {
//	static constexpr int val = 1;
//};

int main() try
{
	f(ga, 10);

	//int aa[10] { fact<1>::val, fact<2>::val, fact<3>::val, fact<4>::val, fact<5>::val,	// :p
	//	fact<6>::val, fact<7>::val, fact<8>::val, fact<9>::val, fact<10>::val };

	int aa[10] { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };

	f(aa, 10);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}


