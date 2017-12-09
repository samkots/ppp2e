
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


// drawing 3-by-3 tic-tac-toe board

int main()
try
{
	const Point btl {150, 50};			// top left corner of the board
	constexpr int cell_size = 100;			// each cell ~ 100 * 100

	Simple_window win {Point{600, 200}, 600, 400, "tic-tac-toe board"};

	Rectangle cell_00 {Point{btl.x + 0 * cell_size, btl.y + 0 * cell_size}, cell_size, cell_size};
	Rectangle cell_01 {Point{btl.x + 1 * cell_size, btl.y + 0 * cell_size}, cell_size, cell_size};
	Rectangle cell_02 {Point{btl.x + 2 * cell_size, btl.y + 0 * cell_size}, cell_size, cell_size};
	Rectangle cell_10 {Point{btl.x + 0 * cell_size, btl.y + 1 * cell_size}, cell_size, cell_size};
	Rectangle cell_11 {Point{btl.x + 1 * cell_size, btl.y + 1 * cell_size}, cell_size, cell_size};
	Rectangle cell_12 {Point{btl.x + 2 * cell_size, btl.y + 1 * cell_size}, cell_size, cell_size};
	Rectangle cell_20 {Point{btl.x + 0 * cell_size, btl.y + 2 * cell_size}, cell_size, cell_size};
	Rectangle cell_21 {Point{btl.x + 1 * cell_size, btl.y + 2 * cell_size}, cell_size, cell_size};
	Rectangle cell_22 {Point{btl.x + 2 * cell_size, btl.y + 2 * cell_size}, cell_size, cell_size};
	cell_00.set_fill_color(Color::white);
	cell_01.set_fill_color(Color::red);
	cell_02.set_fill_color(Color::white);
	cell_10.set_fill_color(Color::red);
	cell_11.set_fill_color(Color::white);
	cell_12.set_fill_color(Color::red);
	cell_20.set_fill_color(Color::white);
	cell_21.set_fill_color(Color::red);
	cell_22.set_fill_color(Color::white);
	win.attach(cell_00);
	win.attach(cell_01);
	win.attach(cell_02);
	win.attach(cell_10);
	win.attach(cell_11);
	win.attach(cell_12);
	win.attach(cell_20);
	win.attach(cell_21);
	win.attach(cell_22);

	win.wait_for_button();
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "error!\n";
	return 2;
}

