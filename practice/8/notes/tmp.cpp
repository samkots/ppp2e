
#include "../std_lib_facilities.h"

class box {
public:
	box(string s): content(s) {
		cout << "ctor: " << content << '\n';
	}

	~box() {
		cout << "dtor: " << content << '\n';
	}

private:
	string content;
};

//const box default_box()
//{
//	return box("box");			// Constructed at every function call.
//}


const box& default_box()
{
	static const box b("box");		// Initialized only the first time the function is called
	return b;
}


int main()
{
	const box& x = default_box();
}

