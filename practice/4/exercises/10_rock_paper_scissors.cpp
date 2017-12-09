
#include "std_lib_facilities.h"


int main()
{
	cout << "Welcome to Rock -- Paper -- Scissors game!\n";
	vector<char> moves;
	int constexpr max_moves = 10;

	cout << "Enter some randome moves...\n";
	for (int i = 0; i < 10; ++i) {
		char c;
		cin >> c;
		if (c != 'r' and c != 'p' and c != 's')
			cout << ":|\n";
		else
			moves.push_back(c);
	}

	for (int i = 0; i < moves.size(); ++i) {
		cout << "Your move(r/p/s): ";
		char c;
		cin >> c;

		cout << "My move: " << moves[i] << '\n';
		switch (c) {
		case 'r':
			switch (moves[i]) {
			case 'r':
				cout << "tie!\n";
				break;
			case 'p':
				cout << "I win, You loose! :)\n";
				break;
			case 's':
				cout << "I loose, You win! :(\n";
			}
			break;
		case 'p':
			switch (moves[i]) {
			case 'r':
				cout << "I loose, You win! :(\n";
				break;
			case 'p':
				cout << "tie!\n";
				break;
			case 's':
				cout << "I win, You loose! :)\n";
			}
			break;
		case 's':
			switch (moves[i]) {
			case 'r':
				cout << "I win, You loose! :)\n";
				break;
			case 'p':
				cout << "I loose, You win! :(\n";
				break;
			case 's':
				cout << "tie!\n";
			}
			break;
		default:
			cout << ":|\n";
		}
	}
}

