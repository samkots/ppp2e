
#include "../std_lib_facilities.h"
#include "money.h"

//------------------------------------------------------------------------------

using namespace bank;

//------------------------------------------------------------------------------

int main()
{
	bank::money some{1200};
	cout << "> " << some << endl;
	money m;
	cout << "enter money: ";
	cin >> m;
	cout << "> " << m << endl;
}

//------------------------------------------------------------------------------
