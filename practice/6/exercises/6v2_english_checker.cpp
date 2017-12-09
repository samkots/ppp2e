
//
// Implementing a small subset of the English grammar.	The Lord style.
// Auther: Sam Kots
//

//------------------------------------------------------------------------------

/*
	Subset of English grammar:

	Sentence:
		Noun verb '.'				// e.g. C++ rules
		Sentence Conjunction Sentence '.'	// e.g. Bird fly but fish swim

	Conjunction:
		"and"
		"or"
		"but"

	Noun:
		"birds"
		"fish"
		"C++"

	Verb:
		"rules"
		"fly"
		"swim"
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector <string> nouns;
vector <string> conjunctions;
vector <string> verbs;

//------------------------------------------------------------------------------

void init()
{
	nouns.push_back("C++");
	nouns.push_back("birds");
	nouns.push_back("fishes");
	conjunctions.push_back("and");
	conjunctions.push_back("or");
	conjunctions.push_back("but");
	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.emplace_back("swim");				// B|
}

//------------------------------------------------------------------------------

bool is_conjunction(string s)
{
	for (auto x : conjunctions)
		if (s == x)
			return true;

	return false;
}

//------------------------------------------------------------------------------

bool is_noun(string s)
{
	for (auto x : nouns)
		if (s == x)
			return true;

	return false;
}

//------------------------------------------------------------------------------

bool is_verb(string s)
{
	for (auto x : verbs)
		if (s == x)
			return true;

	return false;
}

//------------------------------------------------------------------------------

bool sentence()
{
	string word;
	cin >> word;
	if (!is_noun(word))
		return false;

	cin >> word;
	if (!is_verb(word))
		return false;

	cin >> word;
	if (word == ".")
		return true;
	else if (is_conjunction(word))
		return sentence();
}

//------------------------------------------------------------------------------

int main()
{
	init();
	while (cin)
		if (sentence())
			cout << "OK\n";
		else
			cout << "not OK\n";
}

//------------------------------------------------------------------------------

