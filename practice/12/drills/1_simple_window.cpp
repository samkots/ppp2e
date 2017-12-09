
#include "ppp/Graph.h"
#include "ppp/Simple_window.h"

using namespace Graph_lib;


int main()
try
{
	Simple_window swin{Point{100, 100}, 600, 400, "My window"};
	swin.wait_for_button();
}
catch (exception& x)
{
	cerr << "error: " << x.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "error!\n";
	return 2;
}

