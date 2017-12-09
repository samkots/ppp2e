
exe		=	a.out
ppp_sources	=	ppp/Graph.cpp ppp/GUI.cpp ppp/Window.cpp

#source		=	1_arc.cpp
#source		=	2_rounded_corners.cpp
source		=	3_arrow.cpp


a.out:	$(source) $(ppp_sources)
	g++ -std=c++14 -o $(exe) -Wall $(source) $(ppp_sources) -lfltk -lfltk_images

clean:
	@rm -f $(exe)
