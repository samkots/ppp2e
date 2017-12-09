
#include "std_lib_facilities.h"


int main()
{
	cout << "Enter words...\n";

	string disliked_1 = "Broccoli";
	string disliked_2 = "bad";
	string disliked_3 = "worse";
	string disliked_4 = "worst";

	for (string word; cin >> word;) {
		if (word == disliked_1 || word == disliked_2 || word == disliked_3 || word == disliked_4)
			cout << "BLEEP\n";
		else
			cout << word << "\n";
	}
}

