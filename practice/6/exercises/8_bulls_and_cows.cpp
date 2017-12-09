
#include "std_lib_facilities.h"


//------------------------------------------------------------------------------

constexpr int max_chars = 4;

//------------------------------------------------------------------------------

class game {
public:
	game(char a, char b, char c, char d);
	int bulls(vector<char> guess);
	int cows(vector<char> guess);

private:
	vector<char> vec;
};

//------------------------------------------------------------------------------

game::game(char a, char b, char c, char d)
{
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vec.push_back(d);
}

//------------------------------------------------------------------------------

int game::bulls(vector<char> guess)
{
	int bulls = 0;
	for (int i = 0; i < vec.size(); ++i)
		if (guess[i] == vec[i])
			++bulls;

	return bulls;
}

//------------------------------------------------------------------------------

int game::cows(vector<char> guess)
{
	int cows = 0;
	for (auto x : vec)
		for (auto y : guess)
			if (y == x)
				++cows;

	return cows - bulls(guess);
}

//------------------------------------------------------------------------------

vector<char> get_input()
{
	vector<char> res;
	for (int i = 0; i < max_chars; ++i) {
		char c = 0;
		cin >> c;
		res.push_back(c);
	}

	return res;
}

//------------------------------------------------------------------------------

int main()
try
{
	game g('s', 'a', 'm', 'e');
	cout << "Welcome to __bulls_and_cows__ for 4 letters!\n";
	cout << "Start guessing...\n";

	int attempts = 0;
	while (true) {
		cout << "> ";
		vector<char> guess = get_input();

		++attempts;

		int bulls = g.bulls(guess);
		int cows = g.cows(guess);
		
		cout << bulls << " bull(s) and " << cows << " cow(s)\n";

		if (bulls == max_chars && cows == 0) {
			cout << "Congo!\n";
			cout << "Your attempts: " << attempts << '\n';
			break;
		}
	}
}
catch (runtime_error x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (exception x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "oops! Unknown error!!" << '\n';
	return -1;
}

//------------------------------------------------------------------------------

