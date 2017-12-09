
//
// interesting observation:
// array elements are destroyed in reverse order
// but vector elements aren't destroyed in reverse order !!!
//

#include "ppp/std_lib_facilities.h"


struct X {
	int val;
	static int cnt;						// number of many times X::out() is called

	void out(const string& s, int nv) {
		cout << this << "->" << s << ": " << val << " (" << nv << ")\n";
	}

	void out(const string& s) {
		cout << this << "\t" << s << ' ' << val << '\n';
		++cnt;
	}

	X() {
		//out("X()", 0);
		val = 0;
		out("ctor");
	}

	X(int v) {
		val = v;
		//out("X(int)", v);
		out("ctor int");
	}

	X(const X& x) {
		val = x.val;
		//out("X(X&)", x.val);
		out("ctor copy");
	}

	X& operator=(const X& a) {
		//out("X::operator=(X&)", a.val);
		val = a.val;
		out("operator =");
		return *this;
	}

	~X() {
		//out("~X()", 0);
		out("dtor");
	}
};

int X::cnt = 0;


struct log {						// just to help know how many times X::out() is called
	~log() {
		cout << "total: " << X::cnt << '\n';
	}
} logger;


X glob(2);
X copy(X a) {
	cout << "\tcopy()\n";
	return a;
}
X copy2(X a) {
	cout << "\tcopy2()\n";
	X aa = a;
	return aa;
}
X& ref_to(X& a) {
	return a;
}
X* make (int i) {
	X a(i);
	return new X(a);
}
struct XX : X {
	XX() { cout << "\tctor XX" << endl; }
	~XX() { cout << "\tdtor XX" << endl; }
	X a = 10;
	X b = 20;
};

int main() try
{
	//cout << "\tX loc{4};			// local variable\n";
	//X loc{4};			// local variable
	//cout << "\tX loc2(loc);			// copy construction\n";
	//X loc2(loc);			// copy construction
	//cout << "\tloc = X{5};			// copy assignment\n";
	//loc = X{5};			// copy assignment
	//cout << "\tloc2 = copy(loc);\n";
	//loc2 = copy(loc);
	//cout << "\tloc2 = copy2(loc);\n";
	//loc2 = copy2(loc);
	//cout << "\tX loc3{6};\n";
	//X loc3{6};
	//cout << "\tX& r = ref_to(loc);		// call by reference return\n";
	//X& r = ref_to(loc);		// call by reference return
	//cout << "\tdelete make(7);\n";
	//delete make(7);
	//cout << "\tdelete make(8);\n";
	//delete make(8);
	cout << "\tvectr<X> v(4);		// default values\n";
	vector<X> v(4);		// default values
	//cout << "\tXX loc4;\n";
	//XX loc4;
	//cout << "\tX* p = new X{9};		// an X on the free store\n";
	//X* p = new X{9};		// an X on the free store
	//cout << "\tdelete p;\n";
	//delete p;
	cout << "\tX* pp = new X[5];		// an array of Xs on the free store\n";
	X* pp = new X[5];		// an array of Xs on the free store
	cout << "\tdelete[] pp;\n";
	delete[] pp;
}
catch (const exception& x) {
	cout << "error: " << x.what() << endl;
	return 1;
}
catch (...) {
	cout << "error!" << endl;
	return 2;
}

