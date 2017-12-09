
#include "std_lib_facilities.h"


int main()
{
	cout << "Enter some strings...\n";

	vector<string> strings;
	for (string s; cin >> s;) {
		strings.push_back(s);
	}

	string min = strings[0];
	string max = strings[0];
	string mode = strings[0];
	int max_count = 0;
	for (int i = 0 ; i < strings.size(); ++i) {
		if (min > strings[i])
			min = strings[i];

		if (max < strings[i])
			max = strings[i];

		int current_count = 0;
		for (int j = 0; j < strings.size(); ++j) {
			if (strings[i] == strings[j])
				++current_count;
		}

		if (current_count > max_count) {
			max_count = current_count;
			mode = strings[i];
		}
	}

	cout << "min: " << min << '\n';
	cout << "max: " << max << '\n';
	cout << "mode: " << mode << '\n';
	cout << "count: " << max_count << '\n';
}

