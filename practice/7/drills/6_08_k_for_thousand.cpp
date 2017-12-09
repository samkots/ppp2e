
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

// Above comment is kept as it is.

/*
	Simple calculator.

	Revision history:

		Fixed by Sam Kots Jan 2015

	This program implements a basic calculator.
	Input from cin; output to cout;
	The grammar for input is:

	Calculation:
		Statement
		Print
		Quit
		Calculation Statement

	Statement:
		Declaration
		Expression

	Declaration:
		"let" Name "=" Expression

	Expression:
		Term
		Expression "+" Term
		Expression "-" Term

	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
		Term "%" Primary

	Primary:
		Number
		Name
		'(' Expression ')'
		"-" Primary
		"+" Primary

	Number:
		floating-point-literal

	Print:
		';'

	Quit:
		'q'

	Input comes from cin through a Token_stream called ts.
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {									// There was a strange word "struct" it stilled compiled!
public:										// There was no public
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token (char ch, string s) :kind(ch), name(s) { }			// added constructor
};

//------------------------------------------------------------------------------

class Token_stream {
private:
	bool full;		// is the buffer full?
	Token buffer;		// temporary place to hold a Token
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) {
		if (full)
			error("double unget()");				// added the error check

		buffer = t;
		full = true;
	}

	void ignore(char);
};

//------------------------------------------------------------------------------

// following are kinds of 
const char let = 'L';		// token representing the "let" keyword
const char quit = 'q';		// token to print result			// s/Q/q/
const char print = ';';		// a print token
const char number = '8';	// a number token
const char name = 'a';		// a token of type name

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print:								// s/';'/print/
	case quit:								// was missing
	case '=':								
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':			// put numbers on same line
	case '5': case '6': case '7': case '8': case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {						// is ch a letter?
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;					// s/=/+=/

			cin.unget();

			if (s == "let")
				return Token(let);	
			if (s[0] == quit && s.size() == 1)			// it was (s == "quit")
				return Token(quit);				// s/Token(name)/Token(quit)/

			return Token{name,s};					// just {} instead of ()
		}
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------

class Variable {								// s/struct/class/
public:										// there was no public!
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

//------------------------------------------------------------------------------

vector<Variable> names;	

//------------------------------------------------------------------------------

double get_value(string s)
	// get value ot Variable named s
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

//------------------------------------------------------------------------------

void set_value(string s, double d)
	// set the Variable named s to value d
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

//------------------------------------------------------------------------------

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

//------------------------------------------------------------------------------

void define_name(string var, double val)					// function defined
	// adds Variable(var, val) to names
{
	if (is_declared(var))
		error (var, " declared twice");
	names.push_back(Variable(var, val));
}

//------------------------------------------------------------------------------

Token_stream ts;		// this is where the input comes from

//------------------------------------------------------------------------------

double expression();		// forward declaration

//------------------------------------------------------------------------------

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");		// s/'('/')'/
		return d;						// return statement was missing !
	}
	case '-':
		return - primary();
	case '+':					// '+' case was missing
		return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("devide by 0");
			left = fmod(left, d);
			return left;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double declaration()
	// we got "let"
	// now searching the input for Name = Expression
{
	Token t = ts.get();
	if (t.kind != 'a')
		error ("name expected in declaration");
	string name = t.name;

	//if (is_declared(name))
	//	error(name, " declared twice");					// checked not needed since define_name()
	Token t2 = ts.get();

	if (t2.kind != '=')
		error("= missing in declaration of " ,name);

	double d = expression();
	//names.push_back(Variable(name,d));					// replaced with following line
	define_name(name, d);
	return d;
}

//------------------------------------------------------------------------------

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

const string prompt = "> ";
const string result = "= ";

//------------------------------------------------------------------------------

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()
try {
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("k", 1000);
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	//char c;
	//while (cin >>c&& c!=';');						// commented instead of removing
	return 1;
}
catch (...) {
	cerr << "exception\n";
	//char c;
	//while (cin>>c && c!=';');						// commented instead of removing

	return 2;
}

//------------------------------------------------------------------------------

