#ifndef PUBLICATION_UTILITIES_H
#define PUBLICATION_UTILITIES_H 2016

#include "std_lib_facilities.h"

enum Medias { book, periodical, newspaper, audio, video };
enum Genres { fiction, nonfiction, selfhelp, performance };
enum Ages { children, teen, adult, restricted };
const string Medias_Strings[5] = { "book","periodical","newspaper","audio","video" };
const string Genres_Strings[4] = { "fiction","non-fiction","self-help","performance" };
const string Ages_Strings[4] = { "children","teen","adult","restricted" };

class Publication
{
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

public:
	Publication(string xTitle, string xAuthor, int xCopyright_year, Medias xMedia, Genres xGenre, Ages xTarget_age, string xISBN);
	static Publication generatePublication();
	void print() const;
	int getIndexOfPublication(const vector<Publication>& publications, string desired_ISBN);
	void checkOut(string name, string phone_number);
	void checkIn();
	bool getCheckedIn();
};
#endif