/*
	Simple Calculator

	Revision history:
		Revised by Sam Kots January 2015
		Revised by Sam Kots December 2014
		Originally written by Sam Kots
			(sam@gmail.com) Winter 2014.

	This program implements a basic expression calculator.
	Input from cin; output from cout.
	The grammar for input is:

	Statement:
		Espression
		Print
		Quit

	Print:
		;

	Quit:
		q

	Expression:
		Term
		Expression + Term
		Expression - Term

	Term:
		Primary
		Term * Primary
		Term / Primary

	Primary:
		( Expression )
		Number

	Number:
		floating-point-literal

	Input comes from through the Token_stream called ts.
*/

//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const char number = '8';	// t.kind == number means that t is a number Token
const char print = ';';		// t.kind == print means that t is a print Token
const char quit = 'q';		// t.kind == quit means that t is a quit Token
const string prompt = "> ";
const string result = "= ";	// used to indicate that following is a result

//------------------------------------------------------------------------------

class Token {		// Represents kinds operator number or parentheses
public:
	Token(char k)
		:kind(k), value(0) { }

	Token(char k, double val)
		:kind(k), value(val) { }

	char kind;
	int value;	// used for number only
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();
	Token get();			// get a Token
	void putback(Token T);		// put a Token back
	void ignore(char c);		// discard characters up to and including a c

private:
	bool full;
	Token buffer;
};

//------------------------------------------------------------------------------

// constructor just sets the full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)		// No token in buffer
{
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
	if (full)
		error("Double putback!");

	full = true;
	buffer = t;
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {		// check if we already have a Token ready
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;			// Lets see what we get on the stream

	switch (ch) {
	case quit:
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return Token{ch};	// let each character represent itself

	case '.':		// a floating-point-literal can start with a dot
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val = 0;
		cin >> val;
		return Token(number, val);
	}
	default:
		error("Bad token!");
	}
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
	// c represents the kind of Token
{
	// first look in buffer:
	if (full && c == buffer.kind) {
		full = false;
		return;
	}

	full = false;

	// now search input
	for (char ch = 0; cin >> ch;)
		if (ch == c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;		// provides get() andputback()

//------------------------------------------------------------------------------

double expression();		// declaration so primary can call expression

//------------------------------------------------------------------------------

// deals with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error ("')' expected");
		return d;
	}
	case number:
		return t.value;		// return the number's value

	case '-':
		return - primary();

	case '+':
		return primary();

	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deals with * and /
double term()
{
	double left = primary();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;

		case '/':
		{
			double d = primary();
			if (d == 0)
				error ("devide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0)
				error("%: devide by 0");
			left = fmod(left, d);
			t = ts.get();
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deals with + and -
double expression()
{
	double left = term();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;

		case '-':
			left -= term();
			t = ts.get();
			break;

		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate ()		// expression evaluation loop
{
	while (cin)
	try {
		cout << prompt;			// print prompt
		Token t = ts.get();

		while (t.kind == print)		// first discard all prints
			t = ts.get();

		if (t.kind == quit)
			return;

		ts.putback(t);
		cout << result << expression() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';	// write error message
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	calculate();
	keep_window_open();
	return 0;
}
catch (runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	keep_window_open("~~");
	return 1;
}
catch (exception& x) {
	cerr << "error: " << x.what() << endl;
	keep_window_open("~~");
	return 2;
}
catch(...) {
	cerr << "error!" << endl;
	keep_window_open("~~");
	return 3;
}

//------------------------------------------------------------------------------

