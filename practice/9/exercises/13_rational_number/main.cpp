
#include "../std_lib_facilities.h"
#include "rational.h"

using namespace Math;


//------------------------------------------------------------------------------

int main()
try
{
	cout << "decimal: "		<< Math::Rational{5, 6}.decimal()	<< endl;

	Math::Rational r1{2, 3};
	Math::Rational r2{4, 6};

	cout << "rational numer 1: "	<< r1		<< endl;
	cout << "rational numer 2: "	<< r2		<< endl;
	cout << "addition: "		<< r1 + r2	<< endl;
	cout << "subtraction: "		<< r1 - r2	<< endl;
	cout << "multiplication: "	<< r1 * r2	<< endl;
	cout << "division: "		<< r1 / r2	<< endl;
	cout << "equality: "		<< (r1 == r2)	<< endl;
	cout << "inequality: "		<< (r1 != r2)	<< endl;
	cout << "decimal 1: "		<< r1.decimal()	<< endl;
	cout << "decimal 2: "		<< r2.decimal()	<< endl;

	Rational r = {3, 5};
	cout << "Enter a rational: ";
	Rational rr;
	cin >> rr;
	r = rr;
	cout << ">>> " << r << endl;
}
catch (const Math::Rational::Invalid& x) {
	cerr << "error: invalid rational number!" << endl;
	return -1;
}

//------------------------------------------------------------------------------

