
//
// Implementing a small subset of the English grammar.
// Auther: Sam Kots
//

//------------------------------------------------------------------------------

/*
	Subset of English grammar:

	Statement:
		Sentence '.'

	Sentence:
		Noun verb			// e.g. C++ rules
		Sentence Conjunction Sentence	// e.g. Bird fly but fish swim

	Conjunction:
		"and"
		"or"
		"but"

	Noun:
		"birds"
		"fish"
		"C++"
		Article "birds"
		Article "fish"
		Article "C++"

	Article
		"the"

	Verb:
		"rules"
		"fly"
		"swim"
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Word_stream {
public:
	Word_stream();
	string get();
	void putback(string s);

private:
	bool full;
	string buffer;
};

//------------------------------------------------------------------------------

Word_stream::Word_stream()
	:full(false)
{
}

//------------------------------------------------------------------------------

string Word_stream::get()		// Get the next word from input
{
	if (full) {
		full = false;
		return buffer;
	}

	string word;
	cin >> word;
	return word;
}

//------------------------------------------------------------------------------

void Word_stream::putback(string s) {
	if (full)
		error("double putback!");

	buffer = s;
	full = true;
}

//------------------------------------------------------------------------------

Word_stream word_stream;

//------------------------------------------------------------------------------

bool conjunction()
{
	string c = word_stream.get();
	if (c != "and" && c != "or" && c != "but") {
		word_stream.putback(c);
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------

bool article()
{
	string a = word_stream.get();
	if (a != "the") {
		word_stream.putback(a);
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------

bool noun()
{
	article();

	string n = word_stream.get();
	if (n != "birds" && n != "fishes" && n != "C++") {
		word_stream.putback(n);
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------

bool verb()
{
	string n = word_stream.get();
	if (n != "rules" && n != "fly" && n != "swim") {
		word_stream.putback(n);
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------

bool sentence()
{
	if (!noun())
		return false;
	if (!verb())
		return false;

	while (true) {
		if (!conjunction())
			return true;
		else {
			if (!noun())
				return false;
			if (!verb())
				return false;
		}
	}
}

//------------------------------------------------------------------------------

bool statement()
{
	if (!sentence())
		return false;

	string next = word_stream.get();
	if (next != ".") {
		word_stream.putback(next);
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------

int main()
{
	while (cin) {
		if (statement())
			cout << "OK\n";
		else 
			//cout << "not OK\n";
			cout << "not OK: " << word_stream.get() << '\n';
	}
}

//------------------------------------------------------------------------------

