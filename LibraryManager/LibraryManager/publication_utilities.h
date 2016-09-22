#ifndef PUBLICATION_UTILITIES_H
#define PUBLICATION_UTILITIES_H 2016

#include "std_lib_facilities.h"

class Publication
{
public:
	enum Medias { book, periodical, newspaper, audio, video , MediasCOUNT};
	enum Genres { fiction, nonfiction, selfhelp, performance , GenresCOUNT};
	enum Ages { children, teen, adult, restricted, AgesCOUNT };
	Publication(string xTitle, string xAuthor, int xCopyright_year, Medias xMedia, Genres xGenre, Ages xTarget_age, string xISBN);
	void print() const;
	void checkOut(string name, string phone_number);
	void checkIn();
	bool getCheckedIn() const;
	string getISBN() const;
	string getTitle() const;

private:
	string title;
	string author;
	int copyright_year;
	Medias media;
	Genres genre;
	Ages target_age;
	string ISBN;
	bool checked_in;
	string check_out_name;
	string check_out_phone_number;
};

namespace EnumStrings
{
	const vector<string> Medias_Strings = { "book","periodical","newspaper","audio","video" };
	const vector<string> Genres_Strings = { "fiction","non-fiction","self-help","performance" };
	const vector<string> Ages_Strings = { "children","teen","adult","restricted" };
}

namespace PublicationFunctions
{
	int getIndexOfPublication(const vector<Publication>& publications, string desired_ISBN);
	Publication generatePublication();
	void listAllPublications(const vector<Publication>& publications);
	void listMedias();
	void listGenres();
	void listAges();
}
#endif