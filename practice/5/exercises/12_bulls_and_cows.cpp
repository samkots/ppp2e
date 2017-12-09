/*
	Program that implements the game of Bulls and Cows.
*/

#include "std_lib_facilities.h"


int count_bulls(vector<int> vec, vector<int> input)
{
	int bulls = 0;
	for (int i = 0; i < 4; ++i)
		if (input[i] == vec[i])
			++bulls;

	return bulls;
}

int count_cows(vector<int> vec, vector<int> input)
{
	int cows = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (input[i] == vec[j])
				++cows;

	return cows - count_bulls(vec, input);
}

int main()
{
	vector<int> vec {1, 2, 3, 4};

	cout << "start guessing." << endl;
	cout << "Keep entering 4 digits..." << endl;

	int attempts = 0;
	while (1) {
		cout << "> ";
		vector<int> input;
		for (int n = 0; i < 4;) {
			cin >> n;
			input.push_back(n);
		}

		++attempts;

		int bulls = count_bulls(vec, input);
		int cows = count_cows(vec, input);

		cout << bulls;
		if (bulls == 1)
			cout << " bull";
		else 
			cout << " bulls";

		cout << " and ";
		cout << cows;
		if (cows == 1)
			cout << " cow";
		else
			cout << " cows";

		cout << '\n';

		if (bulls == 4 and cows == 0) {
			cout << "Congo!\n";
			cout << "attempts: " << attempts << '\n';
			break;
		}
	}
}

