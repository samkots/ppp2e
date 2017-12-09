
#include <FL/Fl.h>
#include <FL/Fl_Box.h>
#include <FL/Fl_Window.h>
//#include "flk_headers/Point.h"

//using namespace Graph_lib;


int main()
{
	//Point p;

	Fl_Window window(200, 200, "Window Title");
	Fl_Box box(0,0,200,200, "Hey, I mean, Hello, World!");
	window.show();
	return Fl::run();
}

