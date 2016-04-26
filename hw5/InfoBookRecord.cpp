/*

	Kuba Gasiorowski, NETID: kgasiorowski, kuba.gasiorowski@stonybrook.edu
	

*/

#include "InfoBookRecord.h"

InfoBookRecord::InfoBookRecord()
{

	InfoBookRecord("","","",0,"",0);

}

InfoBookRecord::InfoBookRecord(string title, string author, string publisher, int ISBN, string biography, double price)
{

	setTitle(title);
	setAuthor(author);
	setPublisher(publisher);
	setISBN(ISBN);
	setBiography(biography);
	setPrice(price);

}

void InfoBookRecord::setBiography(string s){biography = s;}
void InfoBookRecord::setPrice(double d){price = d;}
string InfoBookRecord::getBiography(){return biography;}
double InfoBookRecord::getPrice(){return price;}

void InfoBookRecord::print() const
{

	BookRecord::print();//Prints the standard info
	
	string tempBio;
	if(biography.length() > 10)
		tempBio = biography.substr(0,10);
	else
		tempBio = biography;
	
	cout << "Bio: " << tempBio << " $" << price;

}
