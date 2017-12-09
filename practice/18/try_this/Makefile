
exe		=	a.out
exe2		=	b.out
ppp_sources	=	ppp/std_lib_facilities.h

#source		=	1_645_ctor_dtor.cpp
source		=	2_646_rvalue_assignment.cxx


a.out:	$(source) $(ppp_sources)
	clang++ -std=c++14 -Wall $(source) $(ppp_sources)
	#g++ -std=c++14 -O0 -o $(exe) -Wall $(source) $(ppp_sources)
	#g++ -std=c++14 -O0 -o $(exe2) -Wall $(source) $(ppp_sources) -fno-elide-constructors		// for #1

clean:
	@rm -f $(exe)
	#@rm -f $(exe2)
