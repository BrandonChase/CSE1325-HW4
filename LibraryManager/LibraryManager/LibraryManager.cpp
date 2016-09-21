#include "std_lib_facilities.h"
#include "publication_utilities.h"

void displayCommands();
Publication generatePublication();

int main()
{
	vector<Publication> publications;

	cout << "Welcome to program" << endl;
	int input;
	
	displayCommands();
	while (cin >> input)
	{
		if (input == 1)
		{
			publications.push_back(generatePublication());
		}

		else if (input == 2)
		{
			for (const Publication& temp : publications)
			{
				temp.print();
			}
		}

		displayCommands();
	}

	keep_window_open();
	return 0;
}

void displayCommands()
{
	cout << "Commands:" << endl;
	cout << "\t1) Create new publication" << endl;
	cout << "\t2) List all created publications" << endl;
	cout << "\t3) Check out a publiction" << endl;
	cout << "\t4) Check in a publication" << endl;
}

Publication generatePublication()
{
	string title;
	string author;
	int copyright_year;
	Medias media;
	Genres genre;
	Ages target_age;
	string ISBN;
	int enum_index;

	cout << "Enter publication's title: ";
	getline(cin >> ws, title);
	cout << "Enter publication's author: ";
	getline(cin >> ws, author);
	cout << "Enter publication's copyright year: ";
	cin >> copyright_year;
	cout << "Medias:\n\t1)book\n\t2)periodical\n\t3)newspaper\n\t4)audio\n\t5)video\n";
	cout << "Enter publication's media: ";
	cin >> enum_index;
	media = Medias(enum_index - 1);
	cout << "Genres:\n\t1)fiction\n\t2)non-fiction\n\t3)self-help\n\t4)performance\n";
	cout << "Enter publication's genre: ";
	cin >> enum_index;
	genre = Genres(enum_index - 1);
	cout << "Target Ages:\n\t1)children\n\t2)teen\n\t3)adult\n\t4)restricted\n";
	cout << "Enter publication's target audience: ";
	cin >> enum_index;
	target_age = Ages(enum_index - 1);
	cout << "Enter publication's ISBN: ";
	getline(cin >> ws, ISBN);

	Publication result(title, author, copyright_year, media, genre, target_age, ISBN);
	return result;
}