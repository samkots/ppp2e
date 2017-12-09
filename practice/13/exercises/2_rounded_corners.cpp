
#include "ppp/Graph.h"
#include "ppp/Simple_window.h"


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

struct Box : Shape {		// rectangle with rounded corners
	Box(Point tlp, int w, int h, int r)
		:Box{ tlp, w, h, clamp_radius(w, h, r), deligate_tag{} }
	{}

	void draw_lines() const {
		t.draw();
		b.draw();
		l.draw();
		r.draw();
		tl.draw();
		tr.draw();
		bl.draw();
		br.draw();
	}

private:
	struct deligate_tag{};
	Box(Point tlp, int w, int h, int r, deligate_tag)
		:t( Point{tlp.x + r, tlp.y}, Point{tlp.x + w - r, tlp.y} )
		,b( Point{tlp.x + r, tlp.y + h}, Point{tlp.x + w - r, tlp.y + h} )
		,l( Point{tlp.x, tlp.y + r}, Point{tlp.x, tlp.y + h - r} )
		,r( Point{tlp.x + w, tlp.y + r}, Point{tlp.x + w, tlp.y + h - r} )
		,tl( {tlp.x + r +r, tlp.y + r +r}, r + r, r + r, 90, 180)
		,tr( {tlp.x + r + w -r, tlp.y + r +r}, r + r, r + r, 0, 90)
		,bl( {tlp.x + r +r, tlp.y + r + h -r}, r + r, r + r, 180, 270)
		,br( {tlp.x + r + w -r, tlp.y + r + h -r}, r + r, r + r, 270, 360)
	{
		add(tlp);
	}

	inline int clamp_radius(int w, int h, int r) {
		 int max_rad = (w <= h ? w : h) / 2;		// max radius is half of the minimum side
		 if (r > max_rad)
			 return max_rad;
		 return r;
	}

	Line t, b, l, r;
	Arc tl, tr, bl, br;
};

} // namespace Graph_lib

int main()
try
{
	using namespace Graph_lib;

	Simple_window win{ Point{150, 150}, 1600, 800, "rounded corners" };

	Box box{ Point{100, 100}, 200, 200, 20};
	win.attach(box);

	int r = 300;					// radius will be clamped
	int w{300}, h{200};
	Mark m1 { Point{500 + r, 200 + r}, '1'};
	Mark m2 { Point{500 + w - r, 200 + r}, '2'};
	Mark m3 { Point{500 + w - r, 200 + h - r}, '3'};
	Mark m4 { Point{500 + r, 200 + h - r}, '4'};
	win.attach(m1);
	win.attach(m2);
	win.attach(m3);
	win.attach(m4);

	Box b{ Point{500, 200}, w, h, r};
	win.attach(b);

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

