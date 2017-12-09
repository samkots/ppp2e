
std		=	-std=c++11
flags		=	-Wall
ppp_sources	=	ppp/Graph.cpp ppp/GUI.cpp ppp/Window.cpp


simple:	simple.cpp $(sources)
	g++ $(std) -o simple $(flags) $(ppp_sources) simple.cpp -lfltk -lfltk_images

trial:	trial.cpp
	g++ $(std) -o trial $(flags) trial.cpp -lfltk

clean:
	@rm -f simple
	@rm -f trial

