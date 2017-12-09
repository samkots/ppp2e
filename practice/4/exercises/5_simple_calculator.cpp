
#include "std_lib_facilities.h"


int main()
{
	cout << "Enter two operands and an operator (+, -, x, /).\n";
	cout << "Example: 3.14 + 5.\n";
	cout << ">>> ";
	double operand1;
	char optor;
	double operand2;
	cin >> operand1 >> optor >> operand2;

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

