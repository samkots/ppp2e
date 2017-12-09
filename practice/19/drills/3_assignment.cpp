
#include "ppp/std_lib_facilities.h"



template <typename T>
struct S {
	S(const T& v)
		:val{v} {}

	S& operator = (const S<T>& o) {
		val = o.val;
		return *this;
	}

	const T get() const;
	T get();
	void set(const T& v);

private:
	T val;
};

template <typename T>
const T S<T>::get() const { return val; }

template <typename T>
T S<T>::get() { return val; }

template <typename T>
void S<T>::set(const T& v) { val = v; }



template <typename T>
void read_val(T& v)
{
	cin >> v;
}


int main() try
{
	S<int>		si{1};
	S<char>		sc{'s'};
	S<double>	sd{1.2};
	S<string>	ss{"hello!"};
	S<vector<int>>	sv{ vector<int>{1, 2, 3, 4} };

	int n = si.get();
	cout << "int:\t\t" << n << '\n';

	char c = sc.get();
	cout << "char:\t\t" << c << '\n';

	double d = sd.get();
	cout << "double:\t\t" << d << '\n';

	string s = ss.get();
	cout << "string:\t\t" << s << '\n';

	cout << "vec:\t\t";
	for (int n : sv.get())
		cout << n << ' ';
	cout << '\n';

	// read from cin
	cout << "Enter an int: ";
	read_val(n);
	cout << "int:\t\t" << n << '\n';

	cout << "Enter a char: ";
	read_val(c);
	cout << "char:\t\t" << c << '\n';

	cout << "Enter a double: ";
	read_val(d);
	cout << "double:\t\t" << d << '\n';

	cout << "Enter a string: ";
	read_val(s);
	cout << "string:\t\t" << s << '\n';

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


