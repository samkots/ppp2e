
#include "../std_lib_facilities.h"
#include "rational.h"

//------------------------------------------------------------------------------

namespace Math {

//------------------------------------------------------------------------------

Rational& Rational::operator = (Rational r)
{
	numer = r.numer;
	denom = r.denom;
}

//------------------------------------------------------------------------------

Rational operator + (Rational a, Rational b)
{
	return Rational {
		a.numerator() * b.denominator() + b.numerator() * a.denominator(),
		a.denominator() * b.denominator()
	};
}

//------------------------------------------------------------------------------

Rational operator - (Rational a, Rational b)
{
	return Rational {
		a.numerator() * b.denominator() - b.numerator() * a.denominator(),
		a.denominator() * b.denominator()
	};
}

//------------------------------------------------------------------------------

Rational operator * (Rational a, Rational b)
{
	return Rational {
		a.numerator() * b.numerator(),
		a.denominator() * b.denominator()
	};
}

//------------------------------------------------------------------------------

Rational operator / (Rational a, Rational b)
{
	return Rational {
		a.numerator() * b.denominator(),
		a.denominator() * b.numerator()
	};
}

//------------------------------------------------------------------------------

bool operator == (Rational a, Rational b)
{
	return a.numerator() * b.denominator() == a.denominator() * b.numerator();
}

//------------------------------------------------------------------------------

bool operator != (Rational a, Rational b)
{
	return !(a == b);
}

//------------------------------------------------------------------------------

ostream& operator << (ostream& os, Rational r)
{
	return os << r.numerator() << '/' << r.denominator();
}

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Rational& r)
{
	int n, d;
	string sep;
	cin >> n >> sep >> d;
	if (!cin)
		return cin;

	if (d == 0)
		throw Rational::Invalid{};

	r = Rational{n, d};
	return is;
}

//------------------------------------------------------------------------------

} // namespace Math

//------------------------------------------------------------------------------

