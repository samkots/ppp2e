
exe		=	a.out
ppp_sources	=	ppp/Graph.cpp ppp/GUI.cpp ppp/Window.cpp

source		=	1_rectangle_n_polygon.cpp
#source		=	2_text_in_rect.cpp
#source		=	3_initials.cpp
#source		=	4_tic_tac_toe_board.cpp
#source		=	5_frame.cpp
#source		=	6_oversized.cpp
#source		=	7_house.cpp
#source		=	8_olympic_five_rings.cpp
#source		=	9_image.cpp
#source		=	10_file_digram.cpp
#source		=	11_polygons_inside_poligons.cpp


a.out:	$(source) $(ppp_sources)
	g++ -std=c++14 -o $(exe) -Wall $(source) $(ppp_sources) -lfltk -lfltk_images

clean:
	@rm -f $(exe)

