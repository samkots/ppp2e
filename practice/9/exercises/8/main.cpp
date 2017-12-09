
#include "../std_lib_facilities.h"
#include "patron.h"


//------------------------------------------------------------------------------

int main()
{
	Patron belle{"Belle", 512, 20};
	cout	<< "patron:\n"
		<< "name: " << belle.get_name() << '\n'
		<< "library card number: " << belle.get_card_number() << '\n'
		<< "owes fees: " << owes_fees(belle) << '\n';
}

//------------------------------------------------------------------------------

