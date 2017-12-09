
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


int main()
try
{
	Simple_window win {Point{400, 100}, 800, 650, "The Lord Bjarne Stroustrup"};

	Image img {Point{100, 100}, "Bjarne.jpg"};

	Text t {Point{90, 600}, "The Lord Bjarne Stroustrup"};
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(40);

	win.attach(img);
	win.attach(t);

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

