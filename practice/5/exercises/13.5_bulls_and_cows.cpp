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

void print_bulls(int bulls)
{
		cout << bulls;
		if (bulls == 1)
			cout << " bull";
		else 
			cout << " bulls";
}

void print_cows(int cows)
{
		cout << cows;
		if (cows == 1)
			cout << " cow";
		else
			cout << " cows";
}

void print_bulls_and_cows(int bulls, int cows)
{
	print_bulls(bulls);
	cout << " and ";
	print_cows(cows);
	cout << '\n';
}

void run_game_loop(vector<int> vec)
{
	int attempts = 0;

	while (1) {
		cout << "> ";
		vector<int> input;
		for (int i = 0, n = 0; i < 4; ++i) {
			cin >> n;
			input.push_back(n);
		}

		++attempts;

		int bulls = count_bulls(vec, input);
		int cows = count_cows(vec, input);

		print_bulls_and_cows(bulls, cows);

		cout << '\n';

		if (bulls == 4 and cows == 0) {
			cout << "Congo!\n";
			cout << "attempts: " << attempts << '\n';
			break;
		}
	}
}

vector<int> get_vec(int n)
{
	srand(n);
	return vector<int> {
		randint(n),
		randint(n),
		randint(n),
		randint(n)
	};			// may repeat values and break the precondition	!!!
}

int main()
{
	cout << "Enter randome number seed: ";
	int n = 0;
	cin >> n;

	cout << "start guessing." << endl;
	cout << "Keep entering 4 digits..." << endl;

	while (1) {
		vector<int> vec = get_vec(n);
		run_game_loop(vec);

		cout << "Do you want to continue?(y/n): ";
		char to_continue = 0;
		cin >> to_continue;
		if (to_continue == 'n')
			break;
		else if (to_continue != 'y')
			cerr << "I'll take that for a \"yes\"!" << endl;
	}

	cout << "Bye! :)" << endl;
}

