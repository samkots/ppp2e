
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"


namespace Graph_lib {

struct Arc : Shape {
	Arc (Point center, int ww, int hh, int ab, int ae):
		w{ww}, h{hh}, a_beg{ab}, a_end{ae}
	{
		add( Point{ center.x - ww, center.y - ww } );
	}

	void draw_lines() const {
		if (color().visibility())
			fl_arc(point(0).x, point(0).y, w, h, a_beg, a_end);
	}

private:
	int w, h;		// width & height
	int a_beg, a_end;	// begin & end angles
};

} // namespace Graph_lib

int main()
try
{
	using namespace Graph_lib;

	Simple_window win { Point{400, 100}, 1000, 800, ""};

	Arc a {Point{400, 400}, 350, 450, 60, 315};
	win.attach(a);

	Point center{600, 600};
	Arc arc {center, 200, 100, 195, 280};
	win.attach(arc);

	arc.set_color(Color::red);
	arc.set_fill_color(Color::red);

	win.wait_for_button();
	arc.move(200, 0);
	win.wait_for_button();
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}

