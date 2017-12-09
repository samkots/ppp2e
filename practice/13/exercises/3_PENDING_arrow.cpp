
#include "ppp/Graph.h"
#include "ppp/Simple_window.h"


namespace Graph_lib {

struct Arrow : Line {
	Arrow(Point p1, Point p2)
		:Line{ p1, p2 }, arrow_head_ {p2, 4}
	{
		// compute arrow head
	}

	void draw_lines() const override {
		Line::draw_lines();
		arrow_head_.draw();
	}

private:
	Circle arrow_head_;
};

} // namespace Graph_lib


int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{150, 50}, 1600, 800, "Arrow"};

	Arrow a{ Point{200, 200}, Point{400, 200} };
	win.attach(a);

	win.wait_for_button();
}

