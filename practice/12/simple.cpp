
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"


int main()
{
	using namespace Graph_lib;

	Point tl{ 100, 100 };					// top left corner
	Simple_window win(tl, 600, 400, "My Window");		// a window
	win.wait_for_button();					// display the window
}

