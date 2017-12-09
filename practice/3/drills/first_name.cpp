
#include "std_lib_facilities.h"


int main()
{
	cout << "Please enter your first name (followed by 'enter'):\n";
	string first_name;		// first name is a variable of type name
	cin >> first_name;		// read characters into first_name

	cout << "Enter your friend's name:\n";
	string friend_name;
	cin >> friend_name;

	cout << "He or she:\n";
	char he_or_she;
	cin >> he_or_she;

	cout << "Enter your age:\n";
	int age;
	cin >> age;

	if (age <= 0 || age >= 110 )
		simple_error("you're kidding!");

	cout << "\nDear " << first_name << ",\n";

	cout << "\n\tHow are you?\n";
	cout << "I am fine. I miss you.\n";
	cout << "I am solving the drills in ppp.\n";
	cout << "And let me tell you, they are great!\n";

	cout << "If you see " << friend_name << " please ask ";
	if (he_or_she == 'm')
		cout << "him";
	else if (he_or_she == 'f')
		cout << "her";
	cout << " to call me.\n";

	cout << "I hear you just had a birthday and you are " << age << " years old.\n";

	if (age < 12)
		cout << "Next year you will be " << age + 1 << ".\n";
	else if (age == 17)
		cout << "Next year you will be able to vote.\n";
	else if (age >= 70)
		cout << "I hope you are enjoying retirement.\n";

	cout << "\nYours sincerely,\n\n\nSam\n";
}

