#ifndef CONTROLLER_H
#define CONTROLLER_H 2016

#include "std_lib_facilities.h"
#include "publication_utilities.h"

class Controller
{
public:
	void createNewPublication();
	void listPublications();
	void checkOutPublication();
	void checkInPublication();
	void displayCommands();

private:
	vector<Publication> publications;
};
#endif
