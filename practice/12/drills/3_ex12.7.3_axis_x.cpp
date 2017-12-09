
#include "ppp/Graph.h"
#include "ppp/Simple_window.h"

using namespace Graph_lib;


int main()
try
{
	Simple_window win{Point{600, 200}, 600, 400, "Canvas"};

	Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
		// starting at (20, 300)
		// 280 pixels long
		// 10 notches
		// label "x asix"

	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();
}
catch (exception& x)
{
	cerr << "error: " << x.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "error!\n";
	return 2;
}

