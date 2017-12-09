
#include "std_lib_facilities.h"


bool exists(const vector<string>& vec, string s)
{
	for (const auto& x : vec)
		if (s == x)
			return true;

	return false;
}

int main()
{
	vector<string> bad_words{"Broccoli", "bad", "worse", "worst"};

	cout << "Enter words...\n";

	for (string word; cin >> word;)
		if (exists(bad_words, word))
			cout << "BLEEP\n";
		else
			cout << word << "\n";
}
