

exe	=	simple_win
#source	=	1_simple_window.cpp
#source	=	2_ex12.7.2_almost_black.cpp
#source	=	3_ex12.7.3_axis_x.cpp
#source	=	4_ex12.7.3_axis_y.cpp
#source	=	5_ex12.7.4_function_sine.cpp
#source	=	6_ex12.7.5_polygons.cpp
#source	=	7_ex12.7.6_rectangles.cpp
#source	=	8_ex12.7.6_poly_rect.cpp
#source	=	9_ex12.7.6_no_more_rect.cpp
#source	=	10_ex12.7.7_fill.cpp
#source	=	11_ex12.7.8_text.cpp
#source	=	12_ex12.7.8_text_bold.cpp
#source	=	13_ex12.7.9_images.cpp
#source	=	14_ex12.7.9_move_image.cpp
source	=	15_ex12.7.10_and_much_more.cpp

simple:
	g++ -std=c++11 -o $(exe) -Wall $(source) ppp/Graph.cpp ppp/GUI.cpp ppp/Window.cpp -lfltk -lfltk_images

log:
	g++ -std=c++11 -o $(exe) -g -Wall $(source) ppp/Graph.cpp ppp/GUI.cpp ppp/Window.cpp -lfltk -lfltk_images

clean:
	@rm -f $(exe)

