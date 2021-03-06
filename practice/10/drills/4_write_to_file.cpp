
//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Point {
	int x;
	int y;
};

//------------------------------------------------------------------------------

istream& operator >> (istream& is, Point& p)
	// reads a Point in format: (x,y)
	// example: (3,4)
{
	char ch = 0;
	is >> ch;
	if (ch != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char term = 0;
	int x;
	int y;

	is >> x >> ch >> y >> term;
	if (!is || ch != ',' || term != ')')
		error("bad point");

	p.x = x;
	p.y = y;
	return is;
}

//------------------------------------------------------------------------------

ostream& operator << (ostream& os, const Point& p)
	// writes a point in format: (x, y)
	// example: (3, 4)
{
	return os << '(' << p.x << ", " << p.y << ')';
}

//------------------------------------------------------------------------------

const string file_name = "mydata.txt";

//------------------------------------------------------------------------------

int main()
try
{
	ofstream ofs {file_name};
	if (!ofs)
		error("can't open output file: ", file_name);

	cout << "Enter 7 points (x, y)\n";
	vector<Point> points;
	for (int i = 0; i < 7; ++i) {
		Point p;
		cin >> p;
		points.push_back(p);
	}

	for (const Point& x : points)
		ofs << x << '\n';

}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

