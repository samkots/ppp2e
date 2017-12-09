
//
// Simple Calculator
// Author: Sam Kots 
//

//------------------------------------------------------------------------------

/*
	Grammar of the calculator:

	Expression:
		Term
		Expression "+" Term
		Expression "-" Term

	Term:
		Primary
		Term '*' Primary
		Term '/' Primary

	Primary:
		"(" Expression ")"
		Number

	Number:
		floating-point-literal
*/

//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

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
	Token get();
	void putback(Token T);

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
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;			// Lets see what we get on the stream

	switch (ch) {
	case ';':	// for "print"
	case 'q':	// for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token(ch);	// let each character represent itself

	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val = 0;
		cin >> val;
		return Token('8', val);		// kind '8'A means a number
	}
	default:
		error("Bad token!");
	}
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
	case '8':			// we use '8' to represent a number
		return t.value;		// return the number's value

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

int main()
try
{
	double val = 0;
	while (cin) {
		cout << "> ";			// print prompt
		Token t = ts.get();

		if (t.kind == 'q') break;	// q for "quit"
		if (t.kind == ';')		// ; for "print"
			cout << "= " << val << '\n';
		else
			ts.putback(t);

		val = expression();
	}

	//keep_window_open();
}
catch (runtime_error& x) {
	cerr << "error: " << x.what() << endl;
	//keep_window_open("~1");
	return 1;
}
catch (exception& x) {
	cerr << "error: " << x.what() << endl;
	//keep_window_open("~2");
	return 2;
}
catch(...) {
	cerr << "error!" << endl;
	//keep_window_open("~3");
	return 3;
}

