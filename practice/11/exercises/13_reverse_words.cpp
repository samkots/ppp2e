
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void reverse_words(istream& is, ostream& os)
{
	vector<vector<string>> vec;

	for (string s; getline(is, s); s = {string{}}) {
		istringstream iss{s};
		vector<string> words;
		for (string w; iss >> w;)
			words.push_back(w);
		vec.push_back(words);
	}

	for (const vector<string>& v : vec) {
		for (int i = v.size() - 1; i >= 0; --i)
			os << v[i] << ' ';
		os << '\n';
	}
}

//------------------------------------------------------------------------------

int main()
{
	cout << "Enter input file name: ";
	string iname;
	cin >> iname;
	ifstream fin{iname};
	if (!fin)
		error("can't open input file ", iname);

	cout << "Enter output file name: ";
	string oname;
	cin >> oname;
	ofstream fout{oname};
	if (!fout)
		error("can't open input file ", oname);

	reverse_words(fin, fout);
}

//------------------------------------------------------------------------------

