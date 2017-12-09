
#include "std_lib_facilities.h"

int main()
{
	vector<double> nums;
	for (double d; cin >> d;)
		nums.push_back(d);

	int mode = 1;
	int max_count = 0;
	for (int i = 0; i < nums.size(); ++i) {
		int current_count = 0;

		for (int j = i ; j < nums.size(); ++j)
			if (nums[i] == nums[j])
				++current_count;

		if (max_count < current_count) {
			max_count = current_count;
			mode = nums[i];
		}
	}

	cout << "mode: " << mode << '\n';
	cout << "max_count: " << max_count << '\n';
}

