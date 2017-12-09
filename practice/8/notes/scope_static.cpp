
/*
	Reference: ppp2e 8.6, pg 292
	"Please note that compilers (and linkers) are clever beasts
	and they are allowed to - and do - optimized code as long as
	the results are equivalent to what we have described here"
*/

#include "../std_lib_facilities.h"

class scope_checker {
public:
	scope_checker(string s): name(s) {
		cout << "ctor: " << name << '\n';
	}

	~scope_checker() {
		cout << "dtor: " << name << '\n';
	}

private:
	string name;
};


scope_checker global("global");						// from start of the program to the end
static scope_checker global_static("global_static");

int main()
{
	scope_checker local("local");					// till there is main
	static scope_checker local_static("local_static");

	int n;
	cout << "1 or 0 ?: ";
	cin >> n;

	if (n) {
		scope_checker if_local("if_local");			// if entered in if
		static scope_checker if_local_static("if_local_static");
	}

	cout << '\n';
	for (int i = 0; i < 3; ++i) {
		scope_checker for_local("for_local");			// ctor and dtor for each iteration!
	}
	cout << '\n';

	static scope_checker local_static2("local_static2");
}

