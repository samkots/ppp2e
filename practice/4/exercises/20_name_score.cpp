
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter name value pairs...\n";

	vector<string> names;
	vector<int> scores;

	string name;
	int score;
	while (cin >> name >> score && name != "NoName" && score != 0) {
		names.push_back(name);
		scores.push_back(score);
	}

	for (int i = 0; i < names.size(); ++i)
		for (int j = i + 1; j < names.size(); ++j)
			if (names[j] == names[i]) {
				cout << "error: duplicate name \"" << names[i] << "\"!\n";
				exit(-1);
			}

	cout << "Enter score to lookup the names: ";
	cin >> score;

	bool found = false;
	for (int i = 0; i < names.size(); ++i)
		if (scores[i] == score) {
			cout << names[i] << '\n';
			found = true;
		}

	if (not found)
		cout << "Score Not Found!\n";
}

