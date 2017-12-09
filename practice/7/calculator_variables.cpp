/*
	Simple calculator

	Revision History:

		Revised by Sam Kots January 2014
		Originally created by Sam Kots
			(sam@gmail.com) Winter 2014.

	This program implements a basic expression calculator.
	Input from cin; output to cout.
	The grammar for input is:

	Grammar of the calculator:

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

	Print:
		";"

	Quit:
		"q"

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
		"(" Expression ")"
		"+" Primary
		"-" Primary

	Number:
		floating-point-literal.

	Input comes from cin through the Token_stream called ts.
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
	Token(char token_kind, double token_val = 0)
		:kind(token_kind), value(token_val) { }

	Token(char token_kind, string token_name)
		:kind(token_kind), name(token_name) { }

	char kind;
	double value;
	string name;
};

//------------------------------------------------------------------------------

const char let = 'L';
const char name = 'a';
const char quit = 'q';
const char print = ';';
const char number = '8';
const string prompt = "> ";
const string result = "= ";
const string declkey = "let";

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char ch);
private:
	bool full;
	Token buffer;
};

//------------------------------------------------------------------------------

Token_stream::Token_stream()
	:full(false), buffer(0)
{
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
	if (full)
		error("double putback()");

	buffer = t;
	full = true;
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch = 0;
	cin >> ch;

	switch (ch) {
	case print:
	case '+': case '-':
	case '*': case '/': case '%':
	case '(': case ')':
	case '=':
		return Token(ch);

	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double d;
			cin >> d;
			return Token(number, d);
		}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.putback(ch);

			if (s[0] == quit && s.size() == 1);
				return Token(quit);
			if (s == declkey)
				return Token(let);
			else
				return Token{name, s};
		}

		error("bad token");
	}
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
	// c represents the kind of Token
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	// now search input
	for (char ch = 0; cin >> ch;)
		if (ch == c)
			return;
}

//------------------------------------------------------------------------------

class Variable {
public:
	Variable(string s, double d)
		:name(s), value(d) { }

	string name;
	double value;
};

//------------------------------------------------------------------------------

vector<Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s)
	// get value of a variable
{
	for (const Variable& var : var_table)
		if (var.name == s)
			return var.value;

	error("get_value: undefined variable ", s);
}

//------------------------------------------------------------------------------

void set_value(string s, double value)
	// set the Variable named s to value
{
	for (Variable& var : var_table)
		if (var.name == s) {
			var.value = value;
			return;
		}
	error("set_value: undefined variable ", s);
}

//------------------------------------------------------------------------------

bool is_declared(string var)
	// is var already in the var_table?
{
	for (const Variable& v : var_table)
		if (v.name == var)
			return true;
	return false;
}

//------------------------------------------------------------------------------

double define_name(string var, double val)
	// add (var, val) to var_table
{
	if (is_declared(var))
		error(var, " declared twice");

	var_table.push_back(Variable(var, val));
	return val;
}

//------------------------------------------------------------------------------

Token_stream ts;

//------------------------------------------------------------------------------

double expression();

//------------------------------------------------------------------------------

/*
	Primary:
		Number
		"(" Expression ")"
		"+" Primary
		"-" Primary
*/

double primary()
{
	Token t = ts.get();

	switch (t.kind) {
	case number:
		return t.value;
	case '(':
		{
			double expression_val = expression();
			Token tt = ts.get();
			if (tt.kind != ')')
				error("')' expected");

			return expression_val;
		}
	case '+':
		return primary();

	case '-':
		return - primary();

	case name:
		return get_value(t.name);

	default:
		error("Primary expected");
	}
}

//------------------------------------------------------------------------------

/*
	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
		Term "%" Primary

*/
double term()
{
	double val = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			val *= primary();
			t = ts.get();
			break;

		case '/':
			{
				double d = primary();
				if (d == 0)
					error("devide by 0");
				val /= d;
				t = ts.get();
				break;
			}
		case '%':
			{
				double d = primary();
				if (d == 0)
					error("devide by 0");
				val = fmod(val, d);
				t = ts.get();
				break;
			}
		default:
			ts.putback(t);
			return val;
		}
	} // while (true)
}

//------------------------------------------------------------------------------

/*
	Expression:
		Term
		Expression "+" Term
		Expression "-" Term

*/
double expression()
{
	double val = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			val += term();
			t = ts.get();
			break;

		case '-':
			val -= term();
			t = ts.get();
			break;

		default:
			ts.putback(t);
			return val;
		}
	} // while (true)
}

//------------------------------------------------------------------------------

double declaration()
	// We found "let"
	// Now looking for Name "=" Expression
{
	Token t = ts.get();
	if (t.kind != name)
		error("name expected");

	string var_name = t.name;

	t = ts.get();
	if (t.kind != '=')
		error("'=' missing from declaration");

	double val = expression();
	return define_name(var_name, val);
}

//------------------------------------------------------------------------------

double statement()
	// A Declaration or an Expression
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();

	default:
		ts.putback(t);
		return expression();
	}
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
	ts.ignore(';');
}

//------------------------------------------------------------------------------

void calculate()
{
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();

			while (t.kind == print)
				t = ts.get();			// eat ';'

			if (t.kind == quit)
				return;

			ts.putback(t);

			cout << result << statement() << '\n';
		}
		catch (runtime_error& x) {
			cerr << "error: " << x.what() << '\n';
			clean_up_mess();
		}
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);

	calculate();
}
catch (exception& e) {
	cerr << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "Oops! Unknown error!" << '\n';
	return -1;
}

//------------------------------------------------------------------------------

