
#include "ppp/Graph.h"
#include "ppp/Simple_window.h"


int main()
try
{
	using namespace Graph_lib;

	Simple_window win {Point{600, 200}, 600, 400, "Rectangle and polygon"};

	Rectangle rect {Point{50, 50}, 400, 200};
	rect.set_color(Color::blue);
	win.attach(rect);

	Polygon poly_rect;
	poly_rect.add(Point{500, 50});
	poly_rect.add(Point{550, 50});
	poly_rect.add(Point{550, 250});
	poly_rect.add(Point{500, 250});
	poly_rect.set_color(Color::red);
	win.attach(poly_rect);

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

