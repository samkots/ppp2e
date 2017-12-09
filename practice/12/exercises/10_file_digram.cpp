
#include "ppp/Simple_window.h"
#include "ppp/Graph.h"

using namespace Graph_lib;

// File diagram...
// ppp, pg 436


//------------------------------------------------------------------------------

struct Box {
	Box(Point tl, const string s1, const string s2 = "", const string s3 = ""):
		r {tl, get_width(s1, s2, s3),  get_height(s2, s3)},
		t1 {Point{tl.x + 10, tl.y + 20}, s1},			// assuming character height to be 10 to 12
		t2 {Point{tl.x + 10, tl.y + 40}, s2},
		t3 {Point{tl.x + 10, tl.y + 60}, s3}
	{
		r.set_fill_color(Color::yellow);
		t1.set_font(Graph_lib::Font::times);
		t2.set_font(Graph_lib::Font::times);
		t3.set_font(Graph_lib::Font::times);
	}

	Rectangle r;
	Text t1, t2, t3;

private:
	int get_width (const string& s1, const string& s2, const string& s3) {
		unsigned int width = s1.size();

		if (width < s2.size())
			width = s2.size();

		if (width < s3.size())
			width = s3.size();

		width *= 10;			// assuming average 8 pixels of character width and 2 pixels distance between 'em
		width += 20;			// 20 pixels of margin left/right
		return width;
	}

	int get_height(const string& s2, const string& s3) {
		int height = 30;

		if (s2.size() != 0)
			height += 20;

		if (s3.size() != 0)
			height += 20;

		return height;
	}
};

//------------------------------------------------------------------------------

struct Arrow {					// just a line for now...
	Arrow(Point beg, Point end)
	{
		line.add(beg);
		line.add(end);
		// points for head
	}

	Open_polyline line;
	//Polygon head;
};

//------------------------------------------------------------------------------

void attach(Simple_window& win, Box& box)
{
	win.attach(box.r);
	win.attach(box.t1);
	win.attach(box.t2);
	win.attach(box.t3);
}

//------------------------------------------------------------------------------

void attach(Simple_window& win, Arrow& arrow)
{
	win.attach(arrow.line);
	//win.attach(arrow.head);
}

//------------------------------------------------------------------------------

int main()
try
{
	Simple_window win {Point{400, 100}, 1000, 800, "File diagram"};

	Box fltk_headers {Point{400, 50}, "FLTK headers", " "};
	Rectangle fltk_headers_back1 {Point{390, 40}, fltk_headers.r.width(), fltk_headers.r.height()};
	fltk_headers_back1.set_fill_color(Color::yellow);
	Rectangle fltk_headers_back2 {Point{395, 45}, fltk_headers.r.width(), fltk_headers.r.height()};
	fltk_headers_back2.set_fill_color(Color::yellow);
	win.attach(fltk_headers_back1);
	win.attach(fltk_headers_back2);
	attach(win, fltk_headers);

	Box fltk_code {Point{700, 90}, "FLTK code", " "};
	Rectangle fltk_code_back1 {Point{690, 80}, fltk_code.r.width(), fltk_code.r.height()};
	fltk_code_back1.set_fill_color(Color::yellow);
	Rectangle fltk_code_back2 {Point{695, 85}, fltk_code.r.width(), fltk_code.r.height()};
	fltk_code_back2.set_fill_color(Color::yellow);
	win.attach(fltk_code_back1);
	win.attach(fltk_code_back2);
	attach(win, fltk_code);

	Text point_h_lable {Point{100, 100}, "Point.h:"};
	point_h_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box point_box {Point{100, 110}, "struct Point { ... };"};
	point_box.t1.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(point_h_lable);
	attach(win, point_box);

	Text window_h_lable {Point{370, 180}, "Window.h:"};
	window_h_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box window_h_box {Point{370, 190}, "// window interface:", "class Window {...};", "..."};
	window_h_box.t2.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(window_h_lable);
	attach(win, window_h_box);

	Text graph_h_lable {Point{100, 230}, "Graph.h:"};
	graph_h_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box graph_h_box {Point{100, 240}, "// graphing interface:", "struct Shape { ... };", "..."};
	graph_h_box.t2.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(graph_h_lable);
	attach(win, graph_h_box);

	Text gui_h_lable {Point{540, 300}, "GUI.h:"};
	gui_h_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box gui_h_box {Point{540, 310}, "// GUI interface:", "struct In_box { ... };", "..."};
	gui_h_box.t2.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(gui_h_lable);
	attach(win, gui_h_box);

	Text window_cpp_lable {Point{250, 350}, "window.cpp:"};
	window_cpp_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box window_cpp_box {Point{250, 360}, "Window code"};
	window_cpp_box.t1.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(window_cpp_lable);
	attach(win, window_cpp_box);

	Text graph_cpp_lable {Point{50, 430}, "Graph.cpp:"};
	graph_cpp_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box graph_cpp_box {Point{50, 440}, "Graph code"};
	graph_cpp_box.t1.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(graph_cpp_lable);
	attach(win, graph_cpp_box);

	Text simple_window_h_lable {Point{280, 440}, "Simple_window.h:"};
	simple_window_h_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box simple_window_h_box {Point{280, 450}, "// window interface:", "class Simple_window {...};", "..."};
	simple_window_h_box.t2.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(simple_window_h_lable);
	attach(win, simple_window_h_box);

	Text gui_cpp_lable {Point{580, 425}, "GUI.cpp:"};
	gui_cpp_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box gui_cpp_box {Point{580, 435}, "GUI code"};
	gui_cpp_box.t1.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(gui_cpp_lable);
	attach(win, gui_cpp_box);

	Text chap12_cpp_lable {Point{110, 560}, "chapter12.cpp:"};
	chap12_cpp_lable.set_font(Graph_lib::Font::helvetica_bold);
	Box chap12_cpp_box {Point{110, 570}, "#include \"Graph.h\"", "#include \"Simple_window.h\"", "int main() { ... }"};
	chap12_cpp_box.t1.set_font(Graph_lib::Font::helvetica_bold);
	chap12_cpp_box.t2.set_font(Graph_lib::Font::helvetica_bold);
	chap12_cpp_box.t3.set_font(Graph_lib::Font::helvetica_bold);
	win.attach(chap12_cpp_lable);
	attach(win, chap12_cpp_box);


	// now for the arrows(I mean lines(for now))

	Arrow window_h_2_fltk_headers {
		Point {370 + window_h_box.r.width() / 2, 190},
		Point {400 + fltk_headers.r.width() / 2, 50 + fltk_headers.r.height()}
	};
	attach(win, window_h_2_fltk_headers);

	Arrow graph_h_2_fltk_headers {
		Point {100 + graph_h_box.r.width() / 2, 240},
		Point {410, 50 + fltk_headers.r.height()}
	};
	attach(win, graph_h_2_fltk_headers);

	Arrow fltk_code_2_fltk_headers {
		Point {690, 92},
		Point {400 + fltk_headers.r.width(), 50 + fltk_headers.r.height() / 2}
	};
	attach(win, fltk_code_2_fltk_headers);

	Arrow gui_h_box_2_fltk_headers {
		Point {540 + gui_h_box.r.width() / 2 + 20, 310},
		Point {400 + fltk_headers.r.width() - 15, 50 + fltk_headers.r.height()}
	};
	attach(win, gui_h_box_2_fltk_headers);

	Arrow graph_h_box_2_point {
		Point {100 + graph_h_box.r.width() / 2, 240},
		Point {100 + point_box.r.width() / 2, 110 + point_box.r.height()}
	};
	attach(win, graph_h_box_2_point);

	Arrow window_h_box_2_point {
		Point {375, 190},
		Point {100 + point_box.r.width() - 20, 110 + point_box.r.height()}
	};
	attach(win, window_h_box_2_point);

	Arrow gui_h_box_2_window_h {
		Point {540 + gui_h_box.r.width() / 2 + 20, 310},
		Point {370 + window_h_box.r.width() - 10, 190 + window_h_box.r.height()}
	};
	attach(win, gui_h_box_2_window_h);

	Arrow window_cpp_2_gui_h {
		Point {250 + window_cpp_box.r.width() - 20, 360},
		Point {390, 190 + window_h_box.r.height()}
	};
	attach(win, window_cpp_2_gui_h);

	Arrow simple_win_2_win_h {
		Point {280 + simple_window_h_box.r.width() - 70, 450},
		Point {370 + window_h_box.r.width() / 2, 190 + window_h_box.r.height()}
	};
	attach(win, simple_win_2_win_h);

	Arrow simple_win_2_gui_h {
		Point {280 + simple_window_h_box.r.width() - 70, 450},
		Point {540 + 10, 310 + gui_h_box.r.height()}
	};
	attach(win, simple_win_2_gui_h);

	Arrow gui_cpp_2_gui_h {
		Point {580 + gui_cpp_box.r.width() - 10, 435},
		Point {540 + gui_h_box.r.width() / 2 + 20, 310 + gui_h_box.r.height()},
	};
	attach(win, gui_cpp_2_gui_h);

	Arrow graph_cpp_2_graph_h {
		Point {50 + graph_cpp_box.r.width() - 10, 440},
		Point {100 + graph_h_box.r.width() / 2 - 5, 240 + graph_h_box.r.height()}
	};
	attach(win, graph_cpp_2_graph_h);

	Arrow chap12_2_graph_h {
		Point {110 + chap12_cpp_box.r.width() / 2, 570},
		Point {100 + graph_h_box.r.width() / 2 + 5, 240 + graph_h_box.r.height()}
	};
	attach(win, chap12_2_graph_h);

	Arrow chap12_2_simple_win_h {
		Point {110 + chap12_cpp_box.r.width() / 2, 570},
		Point {280 + 40, 450 + simple_window_h_box.r.height()}
	};
	attach(win, chap12_2_simple_win_h);

	win.wait_for_button();
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!\n";
	return 1;
}

//------------------------------------------------------------------------------

