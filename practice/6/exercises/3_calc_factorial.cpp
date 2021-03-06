
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
		"{" Expression "}"
		Number
		Number!				// factorial binds tighter than * and /
						// easy way: instead of adding new rule between Term and Primary.

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
	case '!':	// for factorial
	case '(': case ')': case '{': case '}':
	case '+': case '-': case '*': case '/':
		return Token(ch);	// let each character represent itself

	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val = 0;
		cin >> val;
		return Token('8', val);
	}
	default:
		error("Bad token!");
	}
}

//------------------------------------------------------------------------------

int fact(int n)
{
	if (n == 0)		// 0! == 1 !!
		return 1;

	int factorial = 1;
	for (; n > 0; --n)
		factorial *= n;

	return factorial;
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
	case '(':			// handles ( expr ) of ( expr )!
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error ("')' expected");

		Token next = ts.get();
		if (next.kind != '!') {
			ts.putback(next);
			return d;
		}

		int integer = d;
		return fact(d);
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}')
			error ("'}' expected");

		Token next = ts.get();
		if (next.kind != '!') {
			ts.putback(next);
			return d;
		}

		int integer = d;
		return fact(integer);
	}
	case '8':			// we use '8' to represent a number
	{
		Token next = ts.get();
		if (next.kind != '!') {
			ts.putback(next);
			return t.value;
		}

		int integer = t.value;	// no fact() for floatin-point numbers.
		return fact(integer);
	}

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
		Token t = ts.get();

		if (t.kind == 'q') break;	// q for "quit"
		if (t.kind == ';')		// ; for "print"
			cout << "=" << val << '\n';
		else
			ts.putback(t);

		val = expression();
	}

	//keep_window_open();		// commented for convineance on linux
}
catch (runtime_error x)
{
	cerr << "error: " << x.what() << endl;
	keep_window_open("~1");
	return 1;
}
catch (exception x)
{
	cerr << "error: " << x.what() << endl;
	keep_window_open("~2");
	return 2;
}
catch(...)
{
	cerr << "error!" << endl;
	keep_window_open("~3");
	return 3;
}

