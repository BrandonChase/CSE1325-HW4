#include "controller.h"
#include "easy_input.h"

void Controller::createNewPublication()
{
	publications.push_back(PublicationFunctions::generatePublication());
}

void Controller::listPublications()
{
	PublicationFunctions::listAllPublications(publications);
}

void Controller::checkOutPublication()
{
	string desiredParameter = inputString("Enter the either the ISBN or the title (for your convenience) of the publication to be checked out: ");
	int publication_index = PublicationFunctions::getIndexOfPublication(publications, desiredParameter);
	if (publication_index != -1)
	{
		if (publications[publication_index].getCheckedIn())
		{
			string name, phone_number;
			name = inputString("Enter customer name: ");
			phone_number = inputString("Enter customer phone number: ");
			publications[publication_index].checkOut(name, phone_number);
			cout << "***Checkout Successful.\n";
		}

		else
		{
			cout << "Sorry. That publication is already checked out.\n";
		}
	}

	else
	{
		cout << "Sorry. We do not have that publication.\n";
	}
}

void Controller::checkInPublication()
{
	string desiredParameter = inputString("Enter the either the ISBN or the title (for your convenience) of the publication to be checked in: ");
	int publication_index = PublicationFunctions::getIndexOfPublication(publications, desiredParameter);
	if (publication_index != -1)
	{
		if (publications[publication_index].getCheckedIn())
		{
			cout << "That is already checked in.\n";
		}

		else
		{
			publications[publication_index].checkIn();
			cout << "***Check In Successful.\n";
		}
	}

	else
	{
		cout << "Sorry. We did not check that publication out. It must be from a different library.\n";
	}
}

void Controller::displayCommands()
{
	cout << "Commands:" << endl;
	cout << "\t1) Create new publication" << endl;
	cout << "\t2) List all created publications" << endl;
	cout << "\t3) Check out a publiction" << endl;
	cout << "\t4) Check in a publication" << endl;
}