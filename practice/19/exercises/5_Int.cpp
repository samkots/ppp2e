
#include "ppp/std_lib_facilities.h"

///

class Int {
public:
	explicit Int(int n = 0)
		:n_{n} {}

	Int& operator = (const Int& o) {
		n_ = o.n_;
		return *this;
	}

	int operator + (Int n) { return n_ + n.n_; }
	int operator - (Int n) { return n_ - n.n_; }
	int operator * (Int n) { return n_ * n.n_; }
	int operator / (Int n) { return n_ / n.n_; }

	//
	// friend functions aren't yet introduced in the book. But a beginner
	// programmer would look for "how to write << & >> for a class with
	// private members" and he would reach to friend functions.
	//
	friend ostream& operator << (ostream& os, const Int& n);
	friend istream& operator >> (istream& is, Int& n);

private:
	int n_;
};

ostream& operator << (ostream& os, const Int& n)
{
	return os << n.n_;
}

istream& operator >> (istream& is, Int& n)
{
	return is >> n.n_;
}

///

int main() try
{
	Int i{8};
	Int ii{i};

	ii = Int{2};

	cout << i << ' ' << ii << '\n';
	cout << i << " + " << ii << " = " << i + ii << '\n';
	cout << i << " - " << ii << " = " << i - ii << '\n';
	cout << i << " * " << ii << " = " << i * ii << '\n';
	cout << i << " / " << ii << " = " << i / ii << '\n';
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return 3;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return 2;
}
catch (...) {
	cerr << "error!\n";
	return 1;
}

// // //
