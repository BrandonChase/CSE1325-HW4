#include "publication_utilities.h"
#include "easy_input.h"

//PublicationFunctions
int PublicationFunctions::getIndexOfPublication(const vector<Publication>& publications, string desiredParameter)
{
	int index = 0;
	for (const Publication& p : publications)
	{
		if (p.getISBN() == desiredParameter || p.getTitle() == desiredParameter) return index;
		++index;
	}

	return -1;
}

Publication PublicationFunctions::generatePublication()
{
	string title = inputString("Enter publication's title: ");
	string author = inputString("Enter publication's author: ");
	int copyright_year;
	while (true)
	{
		copyright_year = inputInt("Enter publication's copyright year: ");
		if (copyright_year == 0)
		{
			cout << "Invalid input. Try again.\n";
			continue;
		}
		else
		{
			break;
		}
	}

	int enum_index;
	while(true)
	{
		listMedias();
		enum_index = inputInt("Enter publication's media: ");
		if (enum_index > Publication::Medias::MediasCOUNT || enum_index < 1) cout << "Invalid input. Try again.\n";
		else break;
	}
	Publication::Medias media = Publication::Medias(enum_index-1);
	
	while (true)
	{
		listGenres();
		enum_index = inputInt("Enter publication's genre: ");
		if(enum_index > Publication::Genres::GenresCOUNT || enum_index < 1) cout << "Invalid input. Try again.\n";
		else break;
	}
	Publication::Genres genre = Publication::Genres(enum_index-1);

	while(true)
	{
		listAges();
		enum_index = inputInt("Enter publication's target age: ");
		if (enum_index > Publication::Ages::AgesCOUNT || enum_index < 1) cout << "Invalid input. Try again. \n";
		else break;
	} 
	Publication::Ages target_age = Publication::Ages(enum_index-1);

	string ISBN = inputString("Enter publication's ISBN: ");

	Publication result(title, author, copyright_year, media, genre, target_age, ISBN);
	return result;
}

void PublicationFunctions::listAllPublications(const vector<Publication> & publications)
{
	for (const Publication& temp : publications)
	{
		temp.print();
		cout << endl;
	}
}

void PublicationFunctions::listMedias()
{
	cout << "Medias: " << endl;
	for (int i = 0; i < EnumStrings::Medias_Strings.size(); ++i)
	{
		cout << "\t" << i + 1 << ") " << EnumStrings::Medias_Strings[i] << endl;
	}
}

void PublicationFunctions::listGenres()
{
	cout << "Genres: " << endl;
	for (int i = 0; i < EnumStrings::Genres_Strings.size(); ++i)
	{
		cout << "\t" << i + 1 << ") " << EnumStrings::Genres_Strings[i] << endl;
	}
}

void PublicationFunctions::listAges()
{
	cout << "Target Ages: " << endl;
	for (int i = 0; i < EnumStrings::Ages_Strings.size(); ++i)
	{
		cout << "\t" << i + 1 << ") " << EnumStrings::Ages_Strings[i] << endl;
	}
}

//Publication class
Publication::Publication(string xTitle, string xAuthor, int xCopyright_year, Medias xMedia, Genres xGenre, Ages xTarget_age, string xISBN)
{
	title = xTitle;
	author = xAuthor;
	copyright_year = xCopyright_year;
	media = xMedia;
	genre = xGenre;
	target_age = xTarget_age;
	ISBN = xISBN;
	checked_in = true;
}

void Publication::print() const
{
	cout << "\"" << title << "\" ";
	cout << "by " << author << ", ";
	cout << copyright_year << " ";
	cout << "(" << EnumStrings::Ages_Strings[target_age] << " ";
	cout << EnumStrings::Genres_Strings[genre] << " ";
	cout << EnumStrings::Medias_Strings[media] << ") ";
	cout << "ISBN: " << ISBN << endl;

	if (checked_in)
	{
		cout << "Checked In" << endl;
	}

	else
	{
		cout << "Checked out to " << check_out_name << " (" << check_out_phone_number << ")" << endl;
	}
}

void Publication::checkOut(string name, string phone_number)
{
	checked_in = false;
	check_out_name = name;
	check_out_phone_number = phone_number;
}

void Publication::checkIn()
{
		checked_in = true;
		check_out_name = "";
		check_out_phone_number = "";
}

bool Publication::getCheckedIn() const
{
	return checked_in;
}

string Publication::getISBN() const
{
	return ISBN;
}

string Publication::getTitle() const
{
	return title;
}