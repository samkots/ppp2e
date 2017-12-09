
exe		=	a.out
ppp_sources	=	ppp/Graph.cpp ppp/GUI.cpp ppp/Window.cpp

#source		=	1_simple_window.cpp
#source		=	2_grid.cpp
#source		=	3_diagonal.cpp
#source		=	4_image_copies.cpp
source		=	5_moving_image.cpp


a.out:	$(source) $(ppp_sources)
	g++ -std=c++14 -o $(exe) -Wall $(source) $(ppp_sources) -lfltk -lfltk_images

clean:
	@rm -f $(exe)

