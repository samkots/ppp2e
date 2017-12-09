
#ifndef _MONEY_H
#define _MONEY_H

#include "../std_lib_facilities.h"
#include "money.h"

//------------------------------------------------------------------------------

namespace bank {

//------------------------------------------------------------------------------

class money {				// instead of Money
public:
	money() { }
	money(long int amt)
		:ammount{amt} { }

	money& operator = (const money& m) { ammount = m.ammount; }
	long int cents() const { return ammount; }

private:
	long int ammount{};		// in cents
};

//------------------------------------------------------------------------------

ostream& operator << (ostream& os, money m);
istream& operator >> (istream& is, money& m);

//------------------------------------------------------------------------------

} // namespace bank

//------------------------------------------------------------------------------

#endif // _MONEY_H
