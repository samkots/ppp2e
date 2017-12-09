
#include "../std_lib_facilities.h"
#include "library.h"

//------------------------------------------------------------------------------

int main()
try
{
	Library library;
	Book b1 = Book{"12-34-56-78-9", "title1", "author1", "date 1", Book::Genre::fiction};
	Book b2 = Book{"123-4-567-8-a", "title2", "author2", "date 2", Book::Genre::nonfiction};
	Book b3 = Book{"54321-0-1-2-b", "title3", "author3", "date 3", Book::Genre::periodical};
	Book b4 = Book{"1-2-3-4-5", "title4", "author4", "date 4", Book::Genre::biography};
	Book b5 = Book{"1-2-3-4-p", "title5", "author5", "date 5", Book::Genre::children};
	Book b6 = Book{"4-3-2-1-0", "tcpppl", "BjarneS", "May 04", Book::Genre::cplusplus};

	library.add_book(b1);
	library.add_book(b2);
	library.add_book(b3);
	library.add_book(b4);
	library.add_book(b5);
	library.add_book(b6);

	Patron p1 = Patron{"patron1", 512, 0};
	Patron p2 = Patron{"patron2", 256, 20};
	Patron p3 = Patron{"patron3", 128, 40};
	Patron p4 = Patron{"patron4", 64, 100};
	Patron p5 = Patron{"patron5", 8, 0};
	Patron p6 = Patron{"patron6", 32, 30};
	Patron p7 = Patron{"patron7", 16, 0};
	Patron p8 = Patron{"sam", 1024, 0};

	library.add_patron(p1);
	library.add_patron(p2);
	library.add_patron(p3);
	library.add_patron(p4);
	library.add_patron(p5);
	library.add_patron(p6);
	library.add_patron(p7);
	library.add_patron(p8);

	//vector<Patron> unpaied = library.patrons_owining_fees();	// works good
	//for (const Patron& p : unpaied)
	//	cout << p.get_name() << '\n';
	//cout << '\n';

	//library.check_out(Patron{"pat", 4, 0}, b1);			// caught at runtime!
	//library.check_out(p1, Book{"0-0-0-0-a", "title", "auth", "date", Book::Genre::fiction});	// caught at runtime!
	//library.check_out(p2, b1);			// caught! p2 owes fees
	library.check_out(p8, b6);			// Of course allowd! One doesn't simply beat my will power.
}
catch (const Book::Bad_book) {
	cerr << "error: invalid book information!\n";
	return -1;
}
catch (const runtime_error& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "error!\n";
	return -1;
}

//------------------------------------------------------------------------------

