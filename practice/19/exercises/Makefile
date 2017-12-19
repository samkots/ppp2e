
exe		=	a.out
ppp_sources	=	ppp/std_lib_facilities.h

#source		=	1_vector_add_equal.cpp
source		=	2_vector_sum_of_products.cpp


a.out:	$(source) $(ppp_sources)
	@g++ -std=c++14 -o $(exe) -Wall $(source) $(ppp_sources)
	@#clang++ -std=c++14 -Wall $(source) $(ppp_sources)

clean:
	@rm -f $(exe)
