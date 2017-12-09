
#include "ppp/std_lib_facilities.h"


class Link {
public:
	string value;

	Link(const string& str, Link* p = nullptr, Link* n = nullptr)
		:value{str}, prev_{p}, next_{n} {}

	Link* insert(Link* n);				// insert before this
	Link* add(Link* n);				// insert after this
	Link* erase();					// erase this

	const Link* find(const string& s) const;
	Link* find(const string& s);

	Link* advance(int n);				// move n positions in list

	Link* previous() { return prev_; }
	Link* next() { return next_; }

private:
	Link* prev_;
	Link* next_;
};

Link* Link::insert(Link* n)
{
	if (!n) return this;
	if (!this) return n;

	n->next_ = this;
	n->prev_ = prev_;
	if (prev_) prev_->next_ = n;
	prev_ = n;

	return n;
}

Link* Link::add(Link* n)
{
	if (!n) return this;
	if (!this) return n;

	n->next_ = next_;
	n->prev_ = this;
	if (next_) next_->prev_ = n;
	next_ = n;

	return this;
}

Link* Link:: erase()
{
	if (!this) return nullptr;

	if (prev_) prev_->next_ = next_;
	if (next_) next_->prev_ = prev_;

	return next_;
}

const Link* Link::find(const string& str) const
{
	for (Link* p = this; p; p = p->next)
		if (p->value ==str)
			return p;

	return nullptr;
}

Link* Link::find(const string& str)
{
	for (Link* p = this; p; p = p->next)
		if (p->value ==str)
			return p;

	return nullptr;
}

Link* Link::advance(int n)
{
	if (n == 0) return this;
	if (!this) return nullptr;

	Link* p = this;
	if (n > 0) {
		for (; n--; p = p->next_)
			if (!p) return nullptr;
	} else {
		for (; n++; p = p->prev_)
			if (!p) return nullptr;
	}

	return p;
}

void delete_list(Link* p)
{
	while (p) {
		Link* tmp = p;
		p = p->next();
		delete tmp;
	}
}

void printl(Link* l)
{
	cout << "{ ";
	while (l) {
		cout << l->value;
		if ((l = l->next()))
			cout << ", ";
	}
	
	cout << " }";
}

void println(Link* l)
{
	printl(l);
	cout << endl;
}

int main() try
{
	Link* norse_gods = new Link{"Thor"};
	norse_gods = norse_gods->insert(new Link{"Odin"});
	norse_gods = norse_gods->insert(new Link{"Zeus"});
	norse_gods = norse_gods->insert(new Link{"Freia"});

	Link* greek_gods = new Link{"Athena"};
	greek_gods = greek_gods->insert(new Link{"Marse"});
	greek_gods = greek_gods->insert(new Link{"Poseidon"});

	println(norse_gods);
	println(greek_gods);

	{								// I was lazy to rename the variable p... :p
		Link* p = greek_gods->find("Marse");
		if (p) p->value = "Ares";

		p = norse_gods->find("Zeus");
		if (p) {
			if (p == norse_gods) norse_gods = p->next();
			p->erase();
			greek_gods = greek_gods->insert(p);
		}
	}

	println(norse_gods);
	println(greek_gods);

	cout << "---" << endl;

	// add
	Link* p = new Link{"abc"};
	Link* q = p->add(new Link{"def"});
	q = q->next()->add(new Link{"ghi"});
	q = q->next()->add(new Link{"jkl"});
	q = q->next()->add(new Link{"mno"});
	q = q->next()->add(new Link{"pqr"});
	q = q->next()->add(new Link{"stu"});

	println(p);

	// erase
	q->erase();	// q ---> "pqr"
	println(p);
	delete q;

	// find
	Link* l = p->find("stu");
	if (l)
		cout << "found: " << l->value << '\n';
	else
		cout << "not found" << '\n';

	// advance
	q = p->advance(4);
	if (q)
		cout << "advanced: " << q->value << '\n';
	else
		cout << "nullptr\n";

	q = q->advance(-2);
	if (q)
		cout << "advanced: " << q->value << '\n';
	else
		cout << "nullptr\n";

	delete_list(norse_gods);
	delete_list(greek_gods);
	delete_list(p);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}


