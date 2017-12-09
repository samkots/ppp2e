
#include "ppp/Simple_window.h"


int main()
try
{
	using namespace Graph_lib;

	Simple_window win {Point{600, 200}, 1000, 800, "Simple window"};
	win.wait_for_button();
}
catch (const exception& x) {
	cout << " error: " << x.what() << endl;
	return 1;
}
