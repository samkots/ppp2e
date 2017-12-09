
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double compute_index(
	const vector<double>& prices,
	const vector<double>& weights
	)
{
	if (prices.size() != weights.size())			// ensure that the sizes are equal
		error ("sizes of prices and weights mismatch");

	double index = 0;
	for (int i = 0; i < prices.size(); ++i)
		index += prices[i] * weights[i];

	return index;
}

//------------------------------------------------------------------------------

int main()
{
	vector<double> prices = {2, 3};
	vector<double> weights = {4, 5};

	cout << "index computed: " << compute_index(prices, weights) << '\n';
}

//------------------------------------------------------------------------------

