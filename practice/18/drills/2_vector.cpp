
#include "ppp/std_lib_facilities.h"


vector<int> gv{1, 2, 4, 8, 16, 6, 12, 14};


void f(const vector<int>& v)
{
	vector<int> lv(v.size());

	// copy
	for ( int i = 0; i < lv.size(); ++i)
		lv[i] = v[i];

	// print
	cout << "[ ";
	for (int i = 0; i < lv.size(); ++i) {
		cout << lv[i];
		if (i != lv.size() - 1)
			cout << ", ";
	}
	cout << " ]\n";

	// local
	vector<int> lv2(v);

	// print
	cout << "[ ";
	for (int i = 0; i < lv2.size(); ++i) {
		cout << lv2[i];
		if (i != lv2.size() - 1)
			cout << ", ";
	}
	cout << " ]\n";
}

//template <int n>											// :p
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
	f(gv);

	//vector<int> vv { fact<1>::val, fact<2>::val, fact<3>::val, fact<4>::val, fact<5>::val,	// :p
	//	fact<6>::val, fact<7>::val, fact<8>::val, fact<9>::val, fact<10>::val };

	vector<int> vv { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };
	f(vv);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}


