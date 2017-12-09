
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class punct_stream {
public:
	punct_stream(istream& is)
		: source{is}, sensitive(true) { }			// g++ bug.. compiles in clang++		!!!

	void whitespace(const string& s) { white = s; }

	void add_white(char c) { white+= c; }

	bool is_whitespace(char c);
	void case_sensitive(bool b) { sensitive = b; }
	bool is_case_sensitive() { return sensitive; }

	punct_stream& operator>>(string& s);
	operator bool();

private:
	istream& source;		// character source
	istringstream buffer;		// we let buffer do our formatting
	string white;			// character considered "whitespace"
	bool sensitive;			// is the stream case_sensitive?
};

//------------------------------------------------------------------------------

punct_stream& punct_stream::operator >> (string& s)
{
	while (!(buffer >> s)) {
		if (buffer.bad() || !source.good())
			return *this;
		buffer.clear();

		string line;
		getline(source, line);
		for (char& ch : line)
			if (is_whitespace(ch))
				ch = ' ';
			else if (is_case_sensitive())
				ch = tolower(ch);
		buffer.str(line);
	}

	return *this;
}

//------------------------------------------------------------------------------

bool punct_stream::is_whitespace(char ch)
{
	for (char x : white)
		if (ch == x)
			return true;
	return false;
}

//------------------------------------------------------------------------------

punct_stream::operator bool()
{
	return !(source.fail() || source.bad()) && source.good();;
}

//------------------------------------------------------------------------------

int main()
{
	punct_stream ps {cin};
	ps.whitespace(";:,.?!()\"(){}<>/&$@#%^*|~");
	ps.case_sensitive(true);

	cout << "Please enter words\n";
	vector<string> vs;
	for (string word; ps >> word;)
		vs.push_back(word);

	for (const string& x : vs)
		cout << x << ' ';
	cout << '\n';
}

//------------------------------------------------------------------------------

