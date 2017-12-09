
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	cout << 1234.56789 << "\t\t(defaultfloat)\n"
		<< fixed << 1234.56789 << "\t(fixed)\n"
		<< scientific << 1234.56789 << "\t(scientific)\n";

	cout << "--------------------------------------------------------------------------------\n";

	cout << 1234.56789 << '\n'

		<< fixed << 1234.56789 << "\tfixed\n"
		<< scientific << 1234.56789 << "\tscientific\n"

		<< 1234.56789 << "\t\t\tYes! defaultfloat, fixed and scientific, all stick.\n"
		//<< "defaultfloat\n"
		//<< defaultfloat << 1234.56789 << '\n';

		<< '\n'
		<< "/!\\ defaultfloat not working! check compiler!!!\n"
		<< '\n';
}

//------------------------------------------------------------------------------

