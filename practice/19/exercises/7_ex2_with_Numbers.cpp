
#include "ppp/std_lib_facilities.h"

using namespace std;

///

template <typename T>
	// requires Numeric<T>()
class Number {
public:
	explicit Number(T val)
		:val_{val} {}

	Number& operator = (const Number& n) {
		val_ = n.val_;
		return *this;
	}

	Number operator + (const Number& n) const { return Number{val_ + n.val_}; }
	Number operator - (const Number& n) const { return Number{val_ - n.val_}; }
	Number operator * (const Number& n) const { return Number{val_ * n.val_}; }
	Number operator / (const Number& n) const { return Number{val_ / n.val_}; }
	Number operator % (const Number& n) const { return Number{fmod(val_, n.val_)}; }

	//
	// friend functions aren't yet introduced in the book. But a beginner
	// programmer would look for "how to write << & >> for a class with
	// private members" and he would reach to friend functions.
	//
	friend ostream& operator << (ostream& os, const Number<T>& n) {
		return os << n.val_;
	}

	friend istream& operator >> (istream& is , Number<T>& n) {
		return is >> n.val_;
	}

private:
	T val_;
};

///

//
// FIXME: I am using decltype, auto & and new function-return-type syntax.
// These features aren't covered so far in the book.
// But sum() would be extremely ugly/specific without these..
// May be a novice programmer will look for a solution and reach to these..
//
// Nevertheless, this exercise must _will_ make you appreciate these features!!
//
template <typename T, typename U>
	// requires: int operator * (T, U)
auto sum(const vector<T>& a, const vector<U>& b) -> decltype(a[0] * b[0])
{
	int size = a.size();
	if (b.size() < size)
		size = b.size();

	decltype(a[0] * b[0]) sum = decltype(a[0] * b[0]){0};
	for (int i = 0; i < size; ++i)
		sum = sum + a[i] * b[i];

	return sum;
}

///

int main() try
{
	vector<Number<int>> a{Number<int>{1}, Number<int>{2}, Number<int>{3}, Number<int>{4}};
	vector<Number<int>> b{Number<int>{10}, Number<int>{20}, Number<int>{30}, Number<int>{40}, Number<int>{50}};

	cout << "sum: " << sum(a, b) << endl;				// == 300

	vector<Number<double>> ad{Number<double>{1.1}, Number<double>{2.2}, Number<double>{3.3}};
	vector<Number<double>> bd{Number<double>{10.1}, Number<double>{20.2}, Number<double>{30.3}};

	cout << "sum: " << sum(ad, bd) << endl;				// == 155.54

	// The following shouldn't work as Number<T>{} * Number<U>{} is not
	// allowed(Such operators won't be generated from the template).
	//cout << "sum: " << sum(a, bd) << endl;
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
