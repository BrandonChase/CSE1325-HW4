#include "std_lib_facilities.h"
#include "publication_utilities.h"
#include "controller.h"
#include "easy_input.h"

int main()
{
	cout << "\t\t\tDOCUMENTATION\nWelcome to Brandon Chase's library program.\n";
	cout << "To perform a command, enter the number next to the desired command. You will then be prompted to enter relevant data to perform the command.\n";
	cout << "To exit the program, simply enter any character into the command prompt.\n\n";

	Controller control;
	int input;
	
	control.displayCommands();
	cout << "Command: ";

	while (cin >> input)
	{
		if (input == 1)
		{
			control.createNewPublication();
		}

		else if (input == 2)
		{
			control.listPublications();
		}

		else if (input == 3)
		{
			control.checkOutPublication();
		}

		else if (input == 4)
		{
			control.checkInPublication();
		}

		else
		{
			cout << "Invalid input. Try again.\n";
		}
		control.displayCommands();
		cout << "Command: ";
	}
	return 0;
}