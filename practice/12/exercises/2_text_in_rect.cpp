
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;

int main()
{
	Simple_window win {Point{600, 200}, 600, 400, "Text in rectangle"};

	Point rect_location {250, 150};
	Rectangle rect {rect_location, 100, 30};

	Point text_location {rect_location.x + 22, rect_location.y + rect.height() - 10};
	Text t {text_location, "Howdy!"};

	win.attach(rect);
	win.attach(t);
	win.wait_for_button();
}

