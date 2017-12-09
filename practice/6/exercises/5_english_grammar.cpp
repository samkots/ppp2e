
//
// Implementing a small subset of the English grammar.
// Auther: Sam Kots
//

//-----------------------------------------------------------------------------

/*
	The original subset of English grammar:

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

	Verb:
		"rules"
		"fly"
		"swim"
*/

//-----------------------------------------------------------------------------

/*
	Adding the article "the" to the grammar...

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

//-----------------------------------------------------------------------------

