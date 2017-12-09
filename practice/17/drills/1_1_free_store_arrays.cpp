
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
	int* array = new int[10] {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	print_array(cout, array);

	int* a2 = new int[10] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	cout << "\na2:" << endl;
	print_array(cout, a2);

	int* a3 = new int[11] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	cout << "\na3:" << endl;
	print_array(cout, a3, 11);

	int* a4 = new int[20];
	for (int i = 0; i < 20; ++i)
		a4[i] = i + 100;
	cout << "\na4:" << endl;
	print_array(cout, a4, 20);

	delete[] array;
	delete[] a2;
	delete[] a3;
	delete[] a4;

	vector<int> v1 {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	vector<int> v2 {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	vector<int> v3(20);
	for (int i = 0; i < v3.size(); ++i)
		v3[i] = i + 100;

	cout << "\nv1:" << endl;
	print_vector(cout, v1);
	cout << "\nv2:" << endl;
	print_vector(cout, v2);
	cout << "\nv3:" << endl;
	print_vector(cout, v3);
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

