
/*
Grammar in section 7.6.4 pg 238:

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
	Term % Primary

Primary:
	Number
	( Expression )
	- Primary
	+ Primary

Number:
	floating-point-literal
*/

// Above grammar is just for reference.
// Following grammar is a try to fix

/*
	Simple calculator.

	Revision history:

		Fixed by Sam Kots Jan 2015

	This program implements a basic calculator.
	Input from cin; output to cout;
	The grammar for input is:

	Calculation:
		Print
		Quit
		Help
		Statement Print
		Calculation Calculation

	Statement:
		Declaration
		Expression

	Declaration:
		let Name = Expression
		const Name = Expression

	Expression:
		Term
		Expression + Term
		Expression - Term

	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary

	Primary:
		Number
		Name
		Name = Expression
		( Expression )
		- Primary
		+ Primary

	Name:
		identifier starting with an alphabate or '-' and containing
		any of the alphabates, numbers or '-'

	Number:
		floating-point-literal

	Print:
		a newline character

	Help:
		help

	Quit:
		quit

	Input comes from cin through a Token_stream called ts.

	Three improvements to the calculator(Not in the book):
		1. storing result of the last calculation.
		2. Increment operators
		3. Adding Functions

	This calculator keeps a predefined name called "last" which stores
	the result of the last calculation. Initial value of last is 0.
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
const char constant = 'C';	// a token of type const
const char quit = 'q';		// token to print result			// s/Q/q/
const char print = '\n';	// a print token
const char number = '8';	// a number token
const char name = 'a';		// a token of type name
const char assg = '=';
const char help = 'H';
const char last = 'l';		// last result
const string quit_key = "quit";
const string help_key = "help";
const string declkey = "let";
const string constkey = "const";
const string last_key = "last";

double last_res = 0;		// stores the result of the last operation
//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch = 0;
	while (cin.get(ch)) {
		if (ch == print)
			return Token(print);

		if (!isspace(ch))
			break;
	}

	switch (ch) {
	case '(': case ')':
	case '+': case '-':
	case '*': case '/': case '%':
	case print:
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
		if (isalpha(ch) || ch == '_') {						// is ch a letter?
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;					// s/=/+=/

			cin.unget();

			if (s == quit_key)
				return Token(quit);
			if (s == help_key)
				return Token(help);
			if (s == declkey)
				return Token(let);	
			if (s == constkey)
				return Token(constant);
			if(s == last_key)
				return Token(number, last_res);
			if (s[0] == quit && s.size() == 1)
				return Token(quit);

			return Token{name,s};
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
	while (cin.get(ch)) {
		if (ch == c) return;
	}
}

//------------------------------------------------------------------------------

class Variable {								// s/struct/class/
public:										// there was no public!
	string name;
	double value;
	bool is_const;
	Variable(string n, double v) :name(n), value(v), is_const(false) { }
	Variable(string n, double v, bool b) :name(n), value(v), is_const(b) { }
};

//------------------------------------------------------------------------------

class Symbol_table {
public:
	bool is_declared(string name);
	double get_value(string name);
	void set_value(string name, double value);
	void define_name(string name, double val, bool is_const = false);

private:
	vector<Variable> names;
};

//------------------------------------------------------------------------------

bool Symbol_table::is_declared(string s)
{
	for (const Variable& sym : names)
		if (sym.name == s) return true;
	return false;
}

//------------------------------------------------------------------------------

double Symbol_table::get_value(string s)
	// get value ot Variable named s
{
	for (const Variable& sym : names)
		if (sym.name == s) return sym.value;
	error("get: undefined name ",s);
}

//------------------------------------------------------------------------------

void Symbol_table::set_value(string s, double d)
	// set the Variable named s to value d
{
	for (Variable& name : names)
		if (name.name == s) {
			if (name.is_const)
				error(name.name, " is const");
			name.value = d;
			return;
		}
	error("set: undefined name ",s);
}

//------------------------------------------------------------------------------

void Symbol_table::define_name(string name, double val, bool is_const)
{
	if (is_declared(name))
		error(name, " declared twice");

	names.push_back(Variable(name, val, is_const));
}

//------------------------------------------------------------------------------

Symbol_table symtab;

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
	{
		Token tt = ts.get();
		if (tt.kind == assg) {			// Its an assignment
			double val = expression();
			symtab.set_value(t.name, val);
			return val;
		}
		ts.unget(tt);
		return symtab.get_value(t.name);
	}
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

double declaration(bool is_const)
	// we got "let" or const
	// now searching the input for Name = Expression
{
	Token t = ts.get();
	if (t.kind != 'a')
		error ("name expected in declaration");
	string name = t.name;

	if (symtab.is_declared(name))
		error(name, " declared twice");
	Token t2 = ts.get();

	if (t2.kind != '=')
		error("= missing in declaration of " ,name);

	double d = expression();
	symtab.define_name(name, d, is_const);
	return d;
}

//------------------------------------------------------------------------------

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration(false);	// false: declare non-const
	case constant:
		return declaration(true);	// true: declare const
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

void print_help()
{
	cout << "help!\n";
}

//------------------------------------------------------------------------------

void calculate()
{
	while(true) try {
		//cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit)
			return;
		if (t.kind == 'h' || t.kind == 'H') {
			print_help();
			//ts.get();			// eat the new line after h
			continue;			// continueuing will automatically ignore next prints
		}
		else
			ts.unget(t);

		last_res = statement();
		cout << result << last_res << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()
try {
	symtab.define_name("pi", 3.1415926535, true);
	symtab.define_name("e", 2.7182818284, true);
	symtab.define_name("k", 1000, true);
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

