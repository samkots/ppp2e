
//
// ppp chapter 9 exercise 5, pg 340
//

//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_isbn(const string& isbn)
	// validate an isbn number represented as string
	// isbn form: n-n-n-x ;where n is and integer and x is a digit or a letter
	// Example: 978-0-321-99278-9		// ppp's isbn
{
	int dash_count = 0;		// number of '-' have we encountered yet

	for (int i = 0; i < isbn.size(); ++i) {
		if (isbn[i] == '-') {
			++dash_count;
			++i;
		}

		if (dash_count == 4) {			// now only one digit of a letter is expected
			if (i != (isbn.size() - 1))
				return false;

			if (!isdigit(isbn[i]) && !isalpha(isbn[i]))
				return false;

			return true;
		}
		else if (dash_count < 4) {		// integer is expected
			int integer_starting_pos = i;

			while (isdigit(isbn[i]))	// check if its digit or not
				++i;

			if (i == integer_starting_pos)	// there is no integer
				return false;

			if (isbn[i] != '-')		// after digits, there must be a '-'
				return false;
			--i;				// putback
		}
		else if (dash_count > 4)
			return false;
	}
}

//------------------------------------------------------------------------------

class Book {
public:
	class Bad_book {};
	Book(string s, string t, string auth, string d)
		:isbn{s}, title{t}, author{auth}, copyright_date{d}, checked_out{false}
	{
		if (!is_isbn(isbn))
			throw Bad_book();
	}
	string get_isbn() const { return isbn; }
	string get_title() const { return title; }
	string get_author() const { return author; }
	string get_copyright_date() const { return copyright_date; }

	void check_out();
	void check_in();

private:
	string isbn;
	string title;
	string author;
	string copyright_date;
	bool checked_out;
};

//------------------------------------------------------------------------------

void Book::check_out()
{
	if (checked_out)
		error("already checked out");

	checked_out = true;
}

//------------------------------------------------------------------------------

void Book::check_in()
{
	if (!checked_out)
		error("already in");

	checked_out = false;
}

//------------------------------------------------------------------------------

bool operator==(const Book& b, const Book& bb)
{
	return b.get_isbn() == bb.get_isbn();
}

//------------------------------------------------------------------------------

bool operator!=(const Book& b, const Book& bb)
{
	return !(b == bb);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Book& b)
{
	return os << '{'
		<< b.get_title() << ", "
		<< b.get_author() << ", "
		<< b.get_isbn()
		<< '}';
}

//------------------------------------------------------------------------------

int main()
try
{
	Book ppp {
		"978-0-321-99278-9",
		"Programming Principles and practice using C++",
		"Bjarne Stroustrup",
		"May 2014"
	};

	Book tcppstl {
		"012-3-456-789-a",		// not real!
		"the c++ standard library",
		"Alexander Stepanov",
		"Jun 1996"			// not real!
	};

	cout << (ppp == tcppstl) << '\n';
	cout << ppp << '\n';
}
catch (const Book::Bad_book& x) {
	cerr << "error: incorrect book information!\n";
	return -1;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "error!\n";
	return -1; }

//------------------------------------------------------------------------------

