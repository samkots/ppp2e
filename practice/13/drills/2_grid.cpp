
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

	win.wait_for_button();
}
catch (const exception& x) {
	cout << " error: " << x.what() << endl;
	return 1;
}
