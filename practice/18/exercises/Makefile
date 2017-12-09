
exe		=	a.out
ppp_sources	=	ppp/std_lib_facilities.h

#source		=	1_strdup.cpp
#source		=	2_findx_sub_string.cpp
#source		=	3_strcmp.cpp
#source		=	4_non_c_style_strings.cpp
#source		=	5_cat_dot.cpp
#source		=	6_cat_dot_string_separator.cpp
#source		=	7_cat_dot_c_style.cpp
#source		=	8_palindrome_backward_copy_compare.cpp
#source		=	9_memory_layout.cpp
#source		=	10_palindrome_array_fix_a.cpp
source		=	10_palindrome_array_fix_b.cpp


a.out:	$(source) $(ppp_sources)
	g++ -std=c++14 -o $(exe) -Wall $(source) $(ppp_sources)
	#clang++ -std=c++14 -Wall $(source) $(ppp_sources)

clean:
	@rm -f $(exe)
