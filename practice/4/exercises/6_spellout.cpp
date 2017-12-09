
#include "std_lib_facilities.h"

int string_to_digit(string spelled_out)
{
	if (spelled_out == "zero")
		return 0;
	else if (spelled_out == "one")
		return 1;
	else if (spelled_out == "two")
		return 2;
	else if (spelled_out == "three")
		return 3;
	else if (spelled_out == "four")
		return 4;
	else if (spelled_out == "five")
		return 5;
	else if (spelled_out == "six")
		return 6;
	else if (spelled_out == "seven")
		return 7;
	else if (spelled_out == "eight")
		return 8;
	else if (spelled_out == "nine")
		return 9;
	else
		return -1;
}

int char_to_digit(char c)
{
	if ('0' <= c && c <= '9')
		return c - '0';

	return -1;
}

int main()
{
	vector<string> map {
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"
	};

	while (cin) {
		cout << "Ener a digit(Eg. 7 or seven): ";
		string str;
		cin >> str;
		int digit;
		if (str.size() == 1) {
			digit = char_to_digit(str[0]);
			cout << "That's " << map[digit] << "!\n";
		} else {
			digit = string_to_digit(str);
			if (digit == -1)
				cout << "Invalid spelling!\n";
			else 
				cout << "That's " << digit << "!\n";
		}
	}
}

