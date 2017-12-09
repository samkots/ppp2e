
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Result {
	int largest;
	int smallest;
	double mean;
	double median;
};

//------------------------------------------------------------------------------

Result calculate_result(vector<int>& vec)
{
	if (vec.size() == 0)
		error("vector empty");

	Result res;
	int sum = 0;

	sort(vec);
	//sort(vec.begin(), vec.end());

	res.largest = vec[vec.size() - 1];
	res.smallest = vec[0];

	for (int i = 0; i < vec.size(); ++i)
		sum += vec[i];

	res.mean = double(sum) / vec.size();
	if (vec.size() % 2 == 0)		// even
		res.median = vec[double(vec.size() - 1) / 2];
	else
		res.median = vec[double(vec.size()) / 2];

	return res;
}

//------------------------------------------------------------------------------

int main()
{
	vector<int> vec = {1, 5, 3, 7, 8};

	Result r =  calculate_result(vec);

	cout << "largest: " << r.largest << '\n';
	cout << "smallest: " << r.smallest << '\n';
	cout << "mean: " << r.mean << '\n';
	cout << "median: " << r.median << '\n';
}

//------------------------------------------------------------------------------

