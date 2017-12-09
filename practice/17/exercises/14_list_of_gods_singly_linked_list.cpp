
#include "ppp/std_lib_facilities.h"


//
// Singly-linked list
//
class Link {
public:
	string value;

public:
	Link(const string& val, Link* next = nullptr)
		:value{val}, next_{next} {}

	Link* add(Link* n);				// insert after this
	Link* erase_after();				// erase after this
	const Link* findx(const string& str) const;
	Link* findx(const string& str);
	Link* advance(int n);

	Link* next() { return next_; }

private:
	Link* next_;
};

Link* Link::add(Link* n)
{
	if (!this) return n;
	if (!n) return this;

	n->next_ = next_;
	next_ = n;

	return this;
}

Link* Link::erase_after()
{
	if (!this) return nullptr;
	if (!next_) return this;

	Link* tmp = next_;
	next_ = next_->next_;
	tmp->next_ = nullptr;

	return this;
}

const Link* Link::findx(const string& str) const
{
	for (const Link* p = this; p; p = p->next_)
		if (p->value == str)
			return p;

	return nullptr;
}

Link* Link::findx(const string& str)
{
	for (Link* p = this; p; p = p->next_)
		if (p->value == str)
			return p;

	return nullptr;
}

Link* Link::advance(int n)
{
	if (n <= 0)
		return this;

	Link* p = this;
	for (; n--; p = p->next_)
		if (!p) return nullptr;

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

void printl(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p->value;
		if ((p = p->next()))
			cout << ", ";
	}
	cout << " }";
}

void println(Link* p)
{
	printl(p);
	cout << endl;
}

int main() try
{
	Link* norse_gods = new Link{"Thor"};
	norse_gods = norse_gods->add(new Link{"Odin"});
	norse_gods = norse_gods->add(new Link{"Zeus"});
	norse_gods = norse_gods->add(new Link{"Freia"});

	Link* greek_gods = new Link{"Athena"};
	greek_gods = greek_gods->add(new Link{"Marse"});
	greek_gods = greek_gods->add(new Link{"Poseidon"});

	println(norse_gods);
	println(greek_gods);

	// correction
	{
		Link* p = greek_gods->findx("Marse");
		if (p) p->value = "Ares";

		p = norse_gods->findx("Zeus");
		if (p) {
			if (p == norse_gods) {
				Link* p = norse_gods;
				norse_gods = norse_gods->next();
				delete p;
				p = nullptr;
			} else
				p->erase_after();
		}
	}

	println(norse_gods);
	println(greek_gods);

	cout << "--- add ---" << endl;

	Link* p = new Link{"abc"};
	Link* q = p->add(new Link{"def"});
	q = q->next()->add(new Link{"ghi"});
	q = q->next()->add(new Link{"jkl"});
	q = q->next()->add(new Link{"mno"});
	q = q->next()->add(new Link{"pqr"});
	q = q->next()->add(new Link{"stu"});

	println(p);

	cout << "--- erase \"stu\" ---" << endl;
	q->erase_after();	// q ---> "pqr"
	println(p);
	delete q;

	cout << "--- find \"mno\" ---" << endl;
	Link* l = p->findx("mno");
	if (l)
		cout << "found: " << l->value << '\n';
	else
		cout << "not found" << '\n';

	cout << "--- advance by 4 ---" << endl;
	q = p->advance(4);
	if (q)
		cout << "advanced: " << q->value << '\n';
	else
		cout << "nullptr\n";

	cout << "--- advance by -2 ---" << endl;
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


