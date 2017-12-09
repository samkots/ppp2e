
#include "ppp/std_lib_facilities.h"


struct Link {
	string	value;
	Link*	prev;
	Link*	next;

	Link(const string& v, Link* p = nullptr, Link* n = nullptr)
		:value{v}, prev{p}, next{n} { }
};

void printl(Link* l)
{
	cout << "{ ";
	while (l) {
		cout << l->value;
		if (l = l->next)
			cout << ", ";
	}
	
	cout << " }";
}

void println(Link* l)
{
	printl(l);
	cout << endl;
}

void delete_list(Link* p)
{
	while (p) {
		Link* tmp = p;
		p = p->next;
		delete tmp;
	}
}

//
// p ---> . o o o
//
Link* insert(Link* p, Link* n)		// insert n before p
{
	if (!n) return p;
	if (!p) return n;

	n->next = p;
	if (p->prev) p->prev->next = n;
	n->prev = p->prev;
	p->prev = n;

	return n;
}

//
// p ---> o . o o
//
Link* add(Link* p, Link* n)		// insert n after p
{
	if (!p) return n;
	if (!n) return p;

	n->prev = p;
	n->next = p->next;
	if (p->next) p->next->prev = n;
	p->next = n;

	return p;
}

//
// p --->  o . o o
// p --->  . o o o
// p --->  o o o .
//
Link* erase(Link* p)
{
	if (!p) return nullptr;

	if (p->next) p->next->prev = p->prev;
	if (p->prev) p->prev->next = p->next;

	return p->next;
}

Link* find(Link* p, const string& s)
{
	while (p) {
		if (p->value == s) return p;
		p = p->next;
	}

	return nullptr;
}

Link* advance(Link* p, int n)
{
	if (!p) return nullptr;
	if (n == 0) return p;

	if (n > 0)
		for (int i = 0; i < n && p; ++i, p = p->next);
	else
		for (int i = 0; i > n && p; --i, p = p->prev);
	return p;
}

int main() try
{
	Link* norse_gods = new Link{"Thor"};
	//norse_gods = new Link{"Odin", nullptr, norse_gods};
	//norse_gods->next->prev = norse_gods;
	//norse_gods = new Link{"Freia", nullptr, norse_gods};
	//norse_gods->next->prev = norse_gods;

	norse_gods = insert(norse_gods, new Link{"Odin"});
	norse_gods = insert(norse_gods, new Link{"Freia"});

	println(norse_gods);

	// add
	Link* p = new Link{"abc"};
	Link* q = add(p, new Link{"def"});
	q = add(q->next, new Link{"ghi"});
	q = add(q->next, new Link{"jkl"});
	q = add(q->next, new Link{"mno"});
	q = add(q->next, new Link{"pqr"});
	q = add(q->next, new Link{"stu"});

	println(p);

	// erase
	erase(q);	// q ---> "pqr"
	println(p);
	delete q;

	// find
	Link* l = find(p, "stu");
	if (l)
		cout << "found: " << l->value << '\n';
	else
		cout << "not found" << '\n';

	// advance
	q = advance(p, 4);
	if (q)
		cout << "advanced: " << q->value << '\n';
	else
		cout << "nullptr\n";

	q = advance(q, -2);
	if (q)
		cout << "advanced: " << q->value << '\n';
	else
		cout << "nullptr\n";

	delete_list(p);
	delete_list(norse_gods);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}
