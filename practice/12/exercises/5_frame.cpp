
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


int main()
try
{
	const int width = x_max() * (2.0 / 3);		// two-third of the width
	const int height = y_max() * (3.0 / 4);		// three-quarters the height
	constexpr int thickness = 80;

	// frame's top left corner so that the frame fits in the centre
	Point frame_tl = {
		x_max() / 2 - width / 2,
		y_max() / 2 - height / 2
	};

	Mark x {Point{frame_tl.x, y_max() / 2}, 'x'};
	Mark y {Point{x_max() / 2, frame_tl.y}, 'y'};

	Rectangle frame {frame_tl, width, height};
	frame.set_style(Line_style{Line_style::solid, thickness});
	frame.set_color(Color::red);

	Simple_window win {Point{0, 0}, x_max(), y_max(), "Frame"};
	win.attach(frame);
	win.attach(x);
	win.attach(y);
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

