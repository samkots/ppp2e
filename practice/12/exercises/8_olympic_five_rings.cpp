
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


int main()
try
{
	constexpr int ring_radius = 100;
	constexpr int top_row_y = 200;
	constexpr int ring_thickness = 15;
	constexpr int distance = ring_thickness;

	const Point tl {200, top_row_y};					// top left corner

	Circle blue {tl, ring_radius};
	blue.set_color(Color::blue);
	blue.set_style(Line_style(Line_style::solid, ring_thickness));

	Point black_tl {tl.x + 2 * ring_radius + ring_thickness + distance, top_row_y};
	Circle black {black_tl, ring_radius};
	black.set_style(Line_style(Line_style::solid, ring_thickness));

	Point red_tl {black_tl.x + 2 * ring_radius + ring_thickness + distance, top_row_y};
	Circle red {red_tl, ring_radius};
	red.set_color(Color::red);
	red.set_style(Line_style(Line_style::solid, ring_thickness));

	Point yellow_tl {tl.x + ring_radius + ring_thickness, tl.y + ring_radius};
	Circle yellow {yellow_tl, ring_radius};
	yellow.set_color(Color::yellow);
	yellow.set_style(Line_style(Line_style::solid, ring_thickness));

	Point green_tl {yellow_tl.x + 2 * ring_radius + ring_thickness + distance, yellow_tl.y};
	Circle green {green_tl, ring_radius};
	green.set_color(Color::green);
	green.set_style(Line_style(Line_style::solid, ring_thickness));

	Simple_window win {Point{400, 100}, 1000, 600, "The Olympic five rings"};
	win.attach(blue);
	win.attach(black);
	win.attach(red);
	win.attach(yellow);
	win.attach(green);
	win.wait_for_button();
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!\n";
	return 2;
}

