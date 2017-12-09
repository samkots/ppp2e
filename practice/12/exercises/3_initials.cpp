
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


// drawing initials...
// each letter 150 pixes in height and 50 pixels in width
// distance of 15 pixels
// Monospace.... you know!
int main()
try
{
	constexpr int height = 150;
	constexpr int width = 50;
	constexpr int distance = 15;
	const Point initials_tl {200, 100};				// top left corner of initials

	Simple_window win {Point{600, 200}, 600, 400, "SAM"};

	Point stl{initials_tl};						// top left corner of 'S'
	Open_polyline s_line;
	s_line.add({Point{stl.x + width, stl.y}});
	s_line.add(stl);
	s_line.add(Point{stl.x, stl.y + height / 2});
	s_line.add(Point{stl.x + width, stl.y + height / 2});
	s_line.add(Point{stl.x + width, stl.y + height});
	s_line.add(Point{stl.x, stl.y + height});
	s_line.set_style(Line_style{Line_style::solid, 5});
	s_line.set_color(Color::red);

	Point atl{Point{stl.x + width + distance, stl.y}};		// top left corner of 'A'
	Closed_polyline a_line;
	a_line.add(Point{atl.x + width / 2, atl.y});
	a_line.add(Point{atl.x , atl.y + height});
	a_line.add(Point{atl.x + width / 2, atl.y + height / 2});
	a_line.add(Point{atl.x + width, atl.y + height});
	a_line.set_style(Line_style{Line_style::solid, 5});
	a_line.set_color(Color::green);

	Point mtl{Point{atl.x + width + distance, atl.y}};		// top left corner of 'M'
	Open_polyline m_line;
	m_line.add(Point{mtl.x, mtl.y + height});
	m_line.add(mtl);
	m_line.add(Point{mtl.x + width / 2, mtl.y + height / 2});
	m_line.add(Point{mtl.x + width, mtl.y});
	m_line.add(Point{mtl.x + width, mtl.y + height});
	m_line.set_style(Line_style{Line_style::solid, 5});
	m_line.set_color(Color::blue);

	win.attach(s_line);
	win.attach(a_line);
	win.attach(m_line);
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

