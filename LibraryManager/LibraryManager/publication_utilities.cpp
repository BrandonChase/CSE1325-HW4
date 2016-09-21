#include "std_lib_facilities.h"
#include "publication_utilities.h"

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
	cout << "(" << Ages_Strings[target_age] << " ";
	cout << Genres_Strings[genre] << " ";
	cout << Medias_Strings[media] << ") ";
	cout << "ISBN: " << ISBN << endl;
}

int Publication::getIndexOfPublication(const vector<Publication>& publications, string desiredISBN)
{
	int index = 0;
	for (const Publication& p : publications)
	{
		if (p.ISBN == desiredISBN) return index;
		index++;
	}

	return -1;
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

bool Publication::getCheckedIn()
{
	return checked_in;
}
