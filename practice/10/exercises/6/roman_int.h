
#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Roman_int {
public:
	int as_int();

public:
	int n;
};

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Roman_int& ri);
ostream& operator << (ostream& os, const Roman_int& ri);

//------------------------------------------------------------------------------

