
#include "ppp/std_lib_facilities.h"


void print_array(ostream& os, int* array)		// assuming 10 elements
{
	for (int i = 0; i < 10; ++i)
		os << array[i] << endl;
}

void print_array(ostream& os, int* array, int n)
{
	for (int i = 0; i < n; ++i)
		os << array[i] << endl;
}

void print_vector(ostream& os, const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		os << vec[i] << endl;
}

int main() try
{
	int* p1 = new int{7};

	cout << "p1: " << p1 << endl;
	cout << "*p1: " << *p1 << endl;

	int* p2 = new int[7]{1, 2, 4, 8};
	cout << "p2: " << p2 << endl;
	print_array(cout, p2, 7);

	int* p3 = p2;
	p2 = p1;
	p2 = p3;

	cout << "----1----" << endl;
	cout << "p1: " << p1 << endl;
	print_array(cout, p1, 1);

	cout << "p2: " << p2 << endl;
	print_array(cout, p2, 7);

	delete p1;
	delete[] p2;

	cout << "----2----" << endl;
	p1 = new int[10]{1, 2, 4, 8, 7, 6, 5, 3, 9, 10};
	p2 = new int[10];

	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];

	cout << "p1: " << p1 << endl;
	print_array(cout, p1, 10);

	cout << "p2: " << p2 << endl;
	print_array(cout, p2, 10);

	delete[] p1;
	delete[] p2;

	cout << "----3----" << endl;
	vector<int> v1{1, 2, 4, 8, 7, 6, 5, 3, 9, 10};
	vector<int> v2(10);

	for (int i = 0; i < v2.size(); ++i)
		v2[i] = v1[i];

	cout << "v1:" << endl;
	print_vector(cout, v1);

	cout << "v2:" << endl;
	print_vector(cout, v2);
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 2;
}
catch (...) {
	cerr << "error!" << endl;
	return 3;
}

