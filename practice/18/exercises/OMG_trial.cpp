
#include <iostream>
#include <stdexcept>
#include <cstring>


using namespace std;


int strcmp(const char* s, const char* ss)
{
	throw runtime_error("whoa!");
	return 0;
}


int main() try
{
	cout << strcmp(nullptr, nullptr) << endl;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return 3;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 2;
}
catch (...) {
	cerr << "error!" << endl;
	return 1;
}


