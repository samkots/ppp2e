
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


int main()
try	
{
	Simple_window win {Point(600, 200), 600, 400, "House"};

	// drawing parts of house...

	Point base_tl {150, 200};
	constexpr int base_width = 300;
	constexpr int base_height = 170;
	Rectangle base {base_tl, base_width, base_height};
	base.set_fill_color(Color::white);

	constexpr int window_side = 50;
	constexpr int window_top_margin = 50;
	constexpr int window_side_margin = 35;
	Point window1_tl {base_tl.x + window_side_margin, base_tl.y + window_top_margin};
	Rectangle window1 {window1_tl, window_side, window_side};
	window1.set_fill_color(Color::yellow);

	Point window2_tl {
		base_tl.x + base_width - window_side - window_side_margin,
		base_tl.y + window_top_margin
	};
	Rectangle window2 {window2_tl, window_side, window_side};
	window2.set_fill_color(Color::yellow);

	constexpr int door_width = 65;
	constexpr int door_height = 120;
	Point door_tl {base_tl.x + base_width / 2 - door_width / 2, base_tl.y + base_height - door_height};
	Rectangle door {door_tl, door_width, door_height};
	door.set_fill_color(Color::dark_red);

	Closed_polyline roof;
	roof.add(Point{base_tl.x - 50, base_tl.y});
	roof.add(Point{base_tl.x + base_width + 50, base_tl.y});
	roof.add(Point{base_tl.x + base_width / 2, base_tl.y - 150});
	roof.set_fill_color(Color::dark_red);

	constexpr int chimney_width = 40;
	constexpr int chimney_height = 120;
	Point chimney_tl {base_tl.x + 20, base_tl.y - chimney_height};
	Rectangle chimney {chimney_tl, chimney_width, chimney_height};
	chimney.set_fill_color(Color::dark_red);

	// details...
	// smoke from the chimney

	Point smoke1_tl {chimney_tl.x + 10, chimney_tl.y - 10};
	Open_polyline smoke1;
	smoke1.add(Point{smoke1_tl.x , smoke1_tl.y - 5});
	smoke1.add(Point{smoke1_tl.x - 10, smoke1_tl.y - 15});
	smoke1.add(Point{smoke1_tl.x, smoke1_tl.y - 25});
	smoke1.add(Point{smoke1_tl.x - 10, smoke1_tl.y - 35});

	Point smoke2_tl {chimney_tl.x + chimney_width - 10, chimney_tl.y - 10};
	Open_polyline smoke2;
	smoke2.add(Point{smoke2_tl.x, smoke2_tl.y - 5});
	smoke2.add(Point{smoke2_tl.x - 10, smoke2_tl.y - 15});
	smoke2.add(Point{smoke2_tl.x, smoke2_tl.y - 25});
	smoke2.add(Point{smoke2_tl.x - 10, smoke2_tl.y - 35});

	Point smoke3_tl {chimney_tl.x + chimney_width / 2, chimney_tl.y - 10};
	Open_polyline smoke3;
	smoke3.add(Point{smoke3_tl.x, smoke3_tl.y - 5});
	smoke3.add(Point{smoke3_tl.x - 10, smoke3_tl.y - 15});
	smoke3.add(Point{smoke3_tl.x, smoke3_tl.y - 25});
	smoke3.add(Point{smoke3_tl.x - 10, smoke3_tl.y - 35});

	win.attach(base);
	win.attach(window1);
	win.attach(window2);
	win.attach(door);
	win.attach(chimney);
	win.attach(roof);
	win.attach(smoke1);
	win.attach(smoke2);
	win.attach(smoke3);

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

