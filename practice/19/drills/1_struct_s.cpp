
#include "ppp/std_lib_facilities.h"



template <typename T>
struct S {
	T val;

	S(const T& v)
		:val{v} {}
};


int main() try
{
	S<int>		si{1};
	S<char>		sc{'s'};
	S<double>	sd{1.2};
	S<string>	ss{"hello!"};
	S<vector<int>>	sv{ vector<int>{1, 2, 3, 4} };

	int n = si.val;
	cout << "int:\t\t" << n << '\n';

	char c = sc.val;
	cout << "char:\t\t" << c << '\n';

	double d = sd.val;
	cout << "double:\t\t" << d << '\n';

	string s = ss.val;
	cout << "string:\t\t" << s << '\n';

	cout << "vec:\t\t";
	for (int n : sv.val)
		cout << n << ' ';
	cout << '\n';
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


