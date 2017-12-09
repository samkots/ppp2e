
#ifndef POINT_GUARD
#define POINT_GUARD

//typedef void (*Callback)(void*,void*);

namespace Graph_lib {

struct Point {
	int x,y;
	Point(int xx, int yy) : x(xx), y(yy) { }						// Sam: uncommented
	Point() :x(0), y(0) { }											// Sam: uncommented

	Point& operator+=(Point d) { x+=d.x; y+=d.y; return *this; }	// Sam: uncommented
};

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; }

inline bool operator!=(Point a, Point b) { return !(a==b); }


}
#endif
