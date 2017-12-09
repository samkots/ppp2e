
#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Patron {
public:
	Patron(string s, int n, int d):
		name{s}, card_number{n}, fees{d}
	{
	}

	string get_name() const { return name; }
	int get_card_number() const { return card_number; }
	double get_fees() const { return fees; }

	void set_fees(double fees);

private:
	string name;
	int card_number;
	int fees;
};

//------------------------------------------------------------------------------

bool owes_fees(const Patron& patron)
{
	if (patron.get_fees() == 0)
		return false;
	return true;
}

//------------------------------------------------------------------------------

