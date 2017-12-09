
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


int main()
try
{
	Simple_window win{Point{600, 200}, 600/*0*/, 400, "Oversized window!"};	// oversized window gets squized (in KDE & GNOME)!

	Rectangle rect {Point{100, 100}, 2000, 200};				// oversized shapes are clipped (in KDE & GNOME)

	win.attach(rect);

	win.wait_for_button();
}
catch (exception& x) {
	cerr << "error: " << x.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "error!\n";
	return 2;
}

