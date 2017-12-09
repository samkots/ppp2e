
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print_char_classification_cnt(istream& is)
{
	int space_cnt = 0;
	int alpha_cnt = 0;
	int digit_cnt = 0;
	int alnum_cnt = 0;
	int xdigit_cnt = 0;
	int upper_cnt = 0;
	int lower_cnt = 0;
	int cntrl_cnt = 0;
	int punct_cnt = 0;
	int print_cnt = 0;
	int graph_cnt = 0;

	for (char ch; is.get(ch);) {
		if (isspace(ch))
			++space_cnt;
		if (isalpha(ch))
			++alpha_cnt;
		if (isdigit(ch))
			++digit_cnt;
		if (isalnum(ch))
			++alnum_cnt;
		if (isxdigit(ch))
			++xdigit_cnt;
		if (isupper(ch))
			++upper_cnt;
		if (islower(ch))
			++lower_cnt;
		if (iscntrl(ch))
			++cntrl_cnt;
		if (ispunct(ch))
			++punct_cnt;
		if (isprint(ch))
			++print_cnt;
		if (isgraph(ch))
			++graph_cnt;
	}

	cout << "character of each class in the file:\n";
	cout	<< "space_cnt: "	<< space_cnt << '\n'
		<< "alpha_cnt: "	<< alpha_cnt << '\n'
		<< "digit_cnt: "	<< digit_cnt << '\n'
		<< "alnum_cnt: "	<< alnum_cnt << '\n'
		<< "xdigit_cnt: "	<< xdigit_cnt << '\n'
		<< "upper_cnt: "	<< upper_cnt << '\n'
		<< "lower_cnt: "	<< lower_cnt << '\n'
		<< "cntrl_cnt: "	<< cntrl_cnt << '\n'
		<< "punct_cnt: "	<< punct_cnt << '\n'
		<< "print_cnt: "	<< print_cnt << '\n'
		<< "graph_cnt: "	<< graph_cnt << '\n';
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin{iname};
	if (!fin)
		error("can't open input file ", iname);

	print_char_classification_cnt(fin);
}
catch (const exception& x) {
	cerr << "error: " << x.what() << '\n';
	return -1;
}

//------------------------------------------------------------------------------

