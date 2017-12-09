
// oriinam example...

/*
// dangerously ugly code
struct X {
void f(int x) {
struct Y {
int f() { return 1; } int m; };
int m;
m = x; Y m2;
return f(m2.f()); }
int m; void g(int m) {
if (m) f(m+2); else {
g(m+2); }}
X() { } void m3() {
}

void main() {
X a; a.f(2);}
};
*/


// improved code...
struct X {
	void f(int x) {			// member function of X
		struct Y {		// local struct
			int f() {	// member function of Y
				return 1;
			}
			int m;		// a member of Y
		};
		int m;			// local variable of X::f
		m = x; Y m2;
		return f(m2.f());	// recursive call
	}

	int m;				// a member

	void g(int m) {			// member function of X
		if (m)
			f(m+2);
		else {
			g(m+2);
		}
	}

	X() { }				// the constructor

	void m3() {			// a member function of X
	}

	void main() {			// a member function of X
		X a;
		a.f(2);
	}
};


int main()
{
}

