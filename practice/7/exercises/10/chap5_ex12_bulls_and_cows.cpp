/*
	Program that implements the game of Bulls and Cows.
*/

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class answer {
public:
	int count_bulls(vector<int> vec);
	int count_cows(vector<int> vec);

private:
	vector<int> ans{1, 2, 3, 4};
};

//------------------------------------------------------------------------------

int answer::count_bulls(vector<int> vec)
{
	int bulls = 0;
	for (int i = 0; i < 4; ++i)
		if (vec[i] == ans[i])
			++bulls;

	return bulls;
}

//------------------------------------------------------------------------------

int answer::count_cows(vector<int> vec)
{
	int cows = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (vec[i] == ans[j])
				++cows;

	return cows - count_bulls(vec);
}

//------------------------------------------------------------------------------

void game_loop()
{
	int attempts = 0;
	answer ans;
	while (1) {
		cout << "> ";
		vector<int> input;
		for (int i = 0, n; i < 4; ++i) {
			cin >> n;
			input.push_back(n);
		}

		++attempts;

		int bulls = ans.count_bulls(input);
		int cows = ans.count_cows(input);

		cout << bulls;
		if (bulls == 1) cout << " bull";
		else cout << " bulls";
		cout << " and ";
		cout << cows;
		if (cows == 1) cout << " cow";
		else cout << " cows";
		cout << '\n';

		if (bulls == 4 and cows == 0) {
			cout << "Congo!\n";
			cout << "attempts: " << attempts << '\n';
			break;
		}
	}
}

//------------------------------------------------------------------------------

int main()
{
	cout << "start guessing." << endl;
	cout << "Keep entering 4 digits..." << endl;

	game_loop();
}

//------------------------------------------------------------------------------

