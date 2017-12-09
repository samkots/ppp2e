
#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

namespace Math {

//------------------------------------------------------------------------------

class Rational {
public:
	class Invalid {};				// excepion

	Rational() { }
	Rational(int numerator): numer{numerator} { };
	Rational(int numerator, int denominator):
		numer{numerator}, denom{denominator} {
		if (denominator == 0)
			throw Invalid{};
	}

	Rational& operator = (Rational r);

	int numerator() const { return numer; };
	int denominator() const { return denom; };
	double decimal() const { return double(numer) / denom; };

private:
	int numer {0};
	int denom {1};
};

//------------------------------------------------------------------------------

Rational operator + (Rational a, Rational b);
Rational operator - (Rational a, Rational b);
Rational operator * (Rational a, Rational b);
Rational operator / (Rational a, Rational b);

bool operator == (Rational a, Rational b);
bool operator != (Rational a, Rational b);

ostream& operator << (ostream& os, Rational r);
istream& operator >> (istream& is, Rational& r);

//------------------------------------------------------------------------------

} // namespace Math

//------------------------------------------------------------------------------

#endif // RATIONAL_H_

