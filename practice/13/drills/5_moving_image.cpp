
#include "ppp/Simple_window.h"


int main()
try
{
	using namespace Graph_lib;

	Simple_window win {Point{600, 200}, 1000, 800, "Simple window"};

	const int xmax = 800;
	const int ymax = win.y_max();
	constexpr int n = 8;
	constexpr int len = 100;

	Lines grid;
	for (int i = 0; i <= n * 100; i += len)
		grid.add( Point{i, 0}, Point{i, ymax} );
	for ( int i = 0; i <= n * len; i += len)
		grid.add( Point{0, i}, Point{xmax, i} );

	win.attach(grid);

	Vector_ref<Rectangle> rects;
	for (int i = 0; i < n * len; i += len)
		rects.push_back( new Rectangle{Point{i, i}, len, len });

	for (unsigned i = 0; i < rects.size(); ++i) {
		rects[i].set_color(Color::invisible);
		rects[i].set_fill_color(Color::red);
		win.attach(rects[i]);
	}

	Image img1{ Point{0, 3 * len}, "st_magdalena_200p.jpg" };
	win.attach(img1);

	Image img2{ Point{0, 6 * len}, "st_magdalena_200p.jpg" };
	win.attach(img2);

	Image img3{ Point{3 * len, 6 * len}, "st_magdalena_200p.jpg" };
	win.attach(img3);

	Image img{ Point{0, 0}, "contra_100p.gif" };
	win.attach(img);

	win.put_on_top(grid);

	win.wait_for_button();

	int curx = 0;						// current x
	int cury = 0;						// current y
	for (int i = 0; i < n * len; i += len) {
		for (int j = 0; j < n * len; j += len) {
			if (i == 0 && j == 0)			// just to avoid first time case of
				j = len;			// moving to the current location
			img.move(-(curx - j), -(cury - i));
			curx = j;
			cury = i;
			win.wait_for_button();
		}
	}
}
catch (const exception& x) {
	cout << " error: " << x.what() << endl;
	return 1;
}

