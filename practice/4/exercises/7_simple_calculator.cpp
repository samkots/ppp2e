
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

int get_digit()
{
	string str;
	cin >> str;
	if (str.size() == 1) {
		return char_to_digit(str[0]);
	} else {
		return string_to_digit(str);
	}

}

int main()
{
	cout << "Enter two digits and an operator (+, -, x, /).\n";
	cout << "Example: 2 + 4.\n";
	cout << ">>> ";

	int operand1 = get_digit();

	char optor;
	cin >> optor;

	int operand2 = get_digit();

	switch (optor) {
	case '+':
		cout << "Sum of " << operand1 << " and " << operand2 << " is " << operand1 + operand2 << '\n';
		break;

	case '-':
		cout << "Subtraction of " << operand1 << " and " << operand2 << " is " << operand1 - operand2 << '\n';
		break;

	case '*':
		cout << "Multiplication of " << operand1 << " and " << operand2 << " is " << operand1 * operand2 << '\n';
		break;

	case '/':
		cout << "Division of " << operand1 << " and " << operand2 << " is " << operand1 / operand2 << '\n';
		break;

	default:
		cerr << "Invalid operator!" << endl;
	}
}

