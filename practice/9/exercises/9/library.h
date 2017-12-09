
//------------------------------------------------------------------------------

#include "book.h"
#include "date.h"
#include "patron.h"

//------------------------------------------------------------------------------

class Library {
public:
	struct Transaction {
		Transaction(const Book& b, const Patron& p, const Date& d)
			:book{b}, patron{p}, date{d} { }

		Book book;
		Patron patron;
		Date date;
	};

	void add_book(const Book& b);
	void add_patron(const Patron& p);
	void check_out(const Patron& p, const Book& book);
	vector<Patron> patrons_owining_fees() const;

private:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;

	bool exists(const Book&);
	bool exists(const Patron&);
};

//------------------------------------------------------------------------------

bool Library::exists(const Book& book)
{
	for (const Book& b : books)
		if (book == b)
			return true;

	return false;
}

//------------------------------------------------------------------------------

bool Library::exists(const Patron& patron)
{
	for (const Patron& p : patrons)
		if (patron.get_card_number() == p.get_card_number())
			return true;
	return false;
}

//------------------------------------------------------------------------------

void Library::add_book(const Book& book)
{
	books.push_back(book);
}

//------------------------------------------------------------------------------

void Library::add_patron(const Patron& patron)
{
	patrons.push_back(patron);
}

//------------------------------------------------------------------------------

void Library::check_out(const Patron& patron, const Book& book)
{
	if (!exists(patron))
		error("user doesn't exist");

	if (!exists(book))
		error("book doesn't exist");

	if (owes_fees(patron))
		error("user owes fees");

	Transaction transaction {book,patron, Date{2015, Month::jan, 26}};
	transactions.push_back(transaction);
}

//------------------------------------------------------------------------------

vector<Patron> Library::patrons_owining_fees() const 
{
	vector<Patron> res;
	for (const Patron& x : patrons)
		if (owes_fees(x))
			res.push_back(x);
	return res;
}

//------------------------------------------------------------------------------

