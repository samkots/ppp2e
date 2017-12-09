
#include "ppp/Graph.h"
#include "ppp/Simple_window.h"

using namespace Graph_lib;


int main()
try
{
	Simple_window win {Point{600, 200}, 600, 400, "Canvas"};

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

	ya.set_color(Color::cyan);

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
	poly_rect.add(Point{50, 75});

	Text t {Point{150, 150}, "Hello, graphical world!"};
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(20);

	//Image ii {Point{100, 50}, "image.jpg"};		// 400*212-pixel jpg
	//ii.move(100, 200);					// Seg fault in move		/!\ !!!
	Image ii {Point(200, 250), "image.jpg"};

	Circle c {Point{100, 200}, 50};
	Ellipse e {Point{100, 200}, 75, 25};
	e.set_color(Color::dark_red);
	Mark m {Point {100, 200}, 'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100, 20}, oss.str()};

	Image cal {Point{225, 225}, "snow_cpp.gif"};		// 320*240-pixel gih
	cal.set_mask(Point{40, 40}, 200, 150);			// display center part of image

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);

	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(ii);

	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
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

