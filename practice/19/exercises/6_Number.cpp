
//
// There is no operator % for doubles.
// So Number<T>::operator %() uses fmod().
// But this gives a warning for Number<int>::operatr %().
// This can be solbed with template specialization, but that feature is not
// covered in the book so far.
//

#include "ppp/std_lib_facilities.h"

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

	Number operator + (const Number& n) { return Number{val_ + n.val_}; }
	Number operator - (const Number& n) { return Number{val_ - n.val_}; }
	Number operator * (const Number& n) { return Number{val_ * n.val_}; }
	Number operator / (const Number& n) { return Number{val_ / n.val_}; }
	Number operator % (const Number& n) { return Number{fmod(val_, n.val_)}; }

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

int main() try
{
	// ints
	Number<int> ni{8};
	Number<int> nni{2};

	cout << ni << " + " << nni << " = " << ni + nni << '\n';
	cout << ni << " - " << nni << " = " << ni - nni << '\n';
	cout << ni << " * " << nni << " = " << ni * nni << '\n';
	cout << ni << " / " << nni << " = " << ni / nni << '\n';
	cout << ni << " % " << nni << " = " << ni % nni << '\n';

	// doubles
	Number<double> nd{8};
	Number<double> nnd{2};

	cout << nd << " + " << nnd << " = " << nd + nnd << '\n';
	cout << nd << " - " << nnd << " = " << nd - nnd << '\n';
	cout << nd << " * " << nnd << " = " << nd * nnd << '\n';
	cout << nd << " / " << nnd << " = " << nd / nnd << '\n';
	cout << nd << " % " << nnd << " = " << nd % nnd << '\n';
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
