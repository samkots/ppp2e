
#include "ppp/Graph.h"
#include "ppp/Simple_window.h"

using namespace Graph_lib;


int main()
try
{
	Simple_window win{Point{600, 200}, 600, 400, "Canvas"};

	Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
		// starting at (20, 300)
		// 280 pixels long
		// 10 notches
		// label the axis "x asix"

	Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
		// starting at (20, 300)
		// 280 pixels long
		// 10 notches
		// label the axis "y axis"

	//ya.set_color(Color::cyan);

	Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
		// plot sin() in the range [0:100) with (0, 0) at (20, 150)
		// using 1000 points; scane x values *50, scane y values *50

	Polygon poly;
	poly.add(Point{300, 200});
	poly.add(Point{350, 100});
	poly.add(Point{400, 200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);

	Rectangle r {Point{200, 200}, 100, 50};

	Polygon poly_rect;
	poly_rect.add(Point{100, 50});
	poly_rect.add(Point{200, 50});
	poly_rect.add(Point{200, 100});
	poly_rect.add(Point{100, 100});

	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);

	win.set_label("Canvas #6.1");
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

