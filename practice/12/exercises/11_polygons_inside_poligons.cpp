
// Series of reqular polygons, one inside the other. The innermost being an
// equilateral triangle, enclosed by a square, enclosed by a pentagon etc.

#include <cmath>
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;


//------------------------------------------------------------------------------

vector<Point> vertices_coordinates(int radius, int nverts, Point center)
{
	constexpr double pi = 3.14159265;
	const double angle = 2 * pi / nverts;			// angle at the vertices

	vector<Point> vcoords;
	for (int i = 0; i < nverts; ++i)
		vcoords.push_back( Point {
			center.x + radius * cos(i * angle),
			center.y + radius * sin(i * angle)
		});

	return vcoords;
}

//------------------------------------------------------------------------------

void add_vertices(Polygon& p, const vector<Point>& vcoords)
{
	for (Point v : vcoords)
		p.add(v);
}

//------------------------------------------------------------------------------

int main()
try
{
	constexpr int radius = 200;
	constexpr int width = 600;
	constexpr int height = 400;
	const Point center{width / 2, height / 2};

	Simple_window win{Point{600, 200}, width, height, "Canvas"};

	Polygon triangle;
	add_vertices(triangle, vertices_coordinates(radius, 3, center));

	Polygon square;
	add_vertices(square, vertices_coordinates(radius, 4, center));

	Polygon pentagon;
	add_vertices(pentagon, vertices_coordinates(radius, 5, center));

	win.attach(triangle);
	win.attach(square);
	win.attach(pentagon);

	win.wait_for_button();
}
catch (exception& x)
{
	cerr << "error: " << x.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "error!\n";
	return 2;
}

//------------------------------------------------------------------------------

