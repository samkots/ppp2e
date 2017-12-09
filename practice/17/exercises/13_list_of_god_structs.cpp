
//
// string comparison for sorting isn't lexicographical in the sens that it
// doesn't conosider numbers... So 10 comes before 2
//

#include "ppp/std_lib_facilities.h"


struct God {
	string name;
	string mythology;
	string vehicle;
	string weapon;
};

class Link {
public:
	God value;

	Link(const God& str, Link* p = nullptr, Link* n = nullptr)
		:value{str}, prev_{p}, next_{n} {}

	Link* insert(Link* n);				// insert before this
	Link* add(Link* n);				// insert after this
	Link* add_ordered(Link* n);			// insert in lexicographical order
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

Link* Link::add_ordered(Link* n)
{
	if (!n) return this;
	if (!this) return n;

	Link* p = this;

	if (n->value.name < p->value.name)
		return p->insert(n);
	else if (!p->next_)
		return p->add(n);

	p = p->next_;
	while (p) {
		if (n->value.name < p->value.name) {
			p = p->insert(n);
			break;
		}

		if (!p->next_) {				// p is the last element
			p = p->add(n);
			break;
		}

		p = p->next_;
	}

	return this;
}

Link* Link::erase()
{
	if (!this) return nullptr;

	if (prev_) prev_->next_ = next_;
	if (next_) next_->prev_ = prev_;

	Link* next = next_;
	next_ = prev_ = nullptr;

	return next;
}

const Link* Link::find(const string& str) const
{
	for (const Link* p = this; p; p = p->next_)
		if (p->value.name == str)
			return p;

	return nullptr;
}

Link* Link::find(const string& str)
{
	for (Link* p = this; p; p = p->next_)
		if (p->value.name == str)
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

ostream& operator << (ostream& os, const God& god)
{
	os << god.name << '\n';
	if (!god.mythology.empty())
		os << "\t " << god.mythology << '\n';
	if (!god.vehicle.empty())
		os << "\t " << god.vehicle << '\n';
	if (!god.weapon.empty())
		os << "\t " << god.weapon;

	return os;
}

void print_all(Link* l)
{
	while (l) {
		cout << l->value << '\n';
		l = l->next();
	}
}

void printl(Link* l)
{
	cout << "{ ";
	while (l) {
		cout << l->value.name;
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
	//print_all(lex);
	//delete_list(lex);

	// 3 list simple test
	//Link* norse_gods = new Link{{"Thor", "Norse", "leg", "hammer"}};
	//norse_gods = norse_gods->add_ordered(new Link{
	//		{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear catch Gungnir"}});
	//norse_gods = norse_gods->add_ordered(new Link{{"Freia", "Norse", "cat drawn car", "senior"}});

	//Link* greek_gods = new Link{{"Athena", "Greek", "legs", "spear"}};
	//greek_gods = greek_gods->add_ordered(new Link{{"Ares", "Greek", "dog, vulture", "spear"}});
	//greek_gods = greek_gods->add_ordered(new Link{{"Poseidon", "Greek", "fish", "Trident"}});
	//greek_gods = greek_gods->add_ordered(new Link{{"Zeus", "Greek", "chariot", "lightning"}});

	//Link* arya_sanatan_gods = new Link{{"Narayan", "Arya Sanatan", "Eagle", "Chakra, Gada"}};
	//arya_sanatan_gods = arya_sanatan_gods->add_ordered(new Link{{"Rudra", "Arya Sanatan", "Nandi", "Trishula"}});
	//arya_sanatan_gods = arya_sanatan_gods->add_ordered(new Link{{"Hanumana", "Arya Sanatan", "Air", "Gada"}});
	//arya_sanatan_gods = arya_sanatan_gods->add_ordered(new Link{{"Ganapati", "Arya Sanatan", "Mouse", "Pash, Ankush"}});
	//arya_sanatan_gods = arya_sanatan_gods->add_ordered(new Link{
	//		{"Indra", "Arya Sanatan", "Elephant with five trunks called Airawat", "Vajra"}});
	//arya_sanatan_gods = arya_sanatan_gods->add_ordered(new Link{{"Kalki", "Arya Sanatan", "Horse", "Sword"}});

	//print_all(norse_gods);
	//cout << "---\n";
	//print_all(greek_gods);
	//cout << "---\n";
	//print_all(arya_sanatan_gods);

	//delete_list(norse_gods);
	//delete_list(greek_gods);
	//delete_list(arya_sanatan_gods);

	//
	// move from one list of gods to three lists
	//
	Link* gods = new Link{{"Thor", "Norse", "leg", "hammer"}};
	gods = gods->add_ordered(new Link{
			{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}});
	gods = gods->add_ordered(new Link{{"Freia", "Norse", "cat drawn car", "senior"}});

	gods = gods->add_ordered(new Link{{"Athena", "Greek", "legs", "spear"}});
	gods = gods->add_ordered(new Link{{"Ares", "Greek", "dog, vulture", "spear"}});
	gods = gods->add_ordered(new Link{{"Poseidon", "Greek", "fish", "Trident"}});
	gods = gods->add_ordered(new Link{{"Zeus", "Greek", "chariot", "lightning"}});

	gods = gods->add_ordered(new Link{{"Narayan", "Arya Sanatan", "Eagle", "Chakra, Gada"}});
	gods = gods->add_ordered(new Link{{"Rudra", "Arya Sanatan", "Nandi", "Trishula"}});
	gods = gods->add_ordered(new Link{{"Hanumana", "Arya Sanatan", "Air", "Gada"}});
	gods = gods->add_ordered(new Link{{"Ganapati", "Arya Sanatan", "Mouse", "Pash, Ankush"}});
	gods = gods->add_ordered(new Link{
			{"Indra", "Arya Sanatan", "Elephant with five trunks called Airawat", "Vajra"}});
	gods = gods->add_ordered(new Link{{"Kalki", "Arya Sanatan", "Horse", "Sword"}});

	Link* arya_sanatan_gods = nullptr;
	Link* norse_gods = nullptr;
	Link* greek_gods = nullptr;

	while (gods) {
		Link* god = gods;
		gods = gods->erase();
		if (god->value.mythology == "Arya Sanatan")
			arya_sanatan_gods = arya_sanatan_gods->add_ordered(god);
		else if (god->value.mythology == "Norse")
			norse_gods = norse_gods->add_ordered(god);
		else if (god->value.mythology == "Greek")
			greek_gods = greek_gods->add_ordered(god);
		else
			error("Unknown mythology: ", gods->value.mythology);
	}

	print_all(arya_sanatan_gods);
	cout << "---\n";
	print_all(norse_gods);
	cout << "---\n";
	print_all(greek_gods);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cerr << "error!" << endl;
	return 2;
}


