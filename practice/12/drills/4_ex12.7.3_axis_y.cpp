
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
		// label the axis "x asix"

	Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
		// starting at (20, 300)
		// 280 pixels long
		// 10 notches
		// label the axis "y axis"

	ya.set_color(Color::cyan);

	win.attach(xa);
	win.attach(ya);
	win.set_label("Canvas #3");
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

