
#include "money.h"

//------------------------------------------------------------------------------

namespace bank {

//------------------------------------------------------------------------------

ostream& operator << (ostream& os, money m)
{
	double dollars = m.cents() / 100.0;
	return os << '$' << dollars;
}

//------------------------------------------------------------------------------

istream& operator >> (istream& is, money& m)
{
	double dollars;
	char currency_sign;
	is >> currency_sign >> dollars;
	if (!is || currency_sign != '$') {
		is.clear(ios::failbit);
		return is;
	}

	m = money{narrow_cast<long int>(dollars * 100)};
	return is;
}

//------------------------------------------------------------------------------

} // namespace bank

//------------------------------------------------------------------------------

