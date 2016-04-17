#include "BookRecord.h"

//Constructors
BookRecord::BookRecord(){}

BookRecord::BookRecord(string title, string author, string publisher, int ISBN)
{

	setTitle(title);
	setAuthor(author);
	setPublisher(publisher);
	setISBN(ISBN);

}

//Mutators
void BookRecord::setTitle(string s){title = s;}
void BookRecord::setPublisher(string s){publisher = s;}
void BookRecord::setAuthor(string s){author = s;}
void BookRecord::setISBN(int i){ISBN = i;}

//Accessors
string BookRecord::getTitle()const{return title;}
string BookRecord::getAuthor()const{return author;}
string BookRecord::getPublisher()const{return publisher;}
int BookRecord::getISBN()const{return ISBN;}

//Regular method
void BookRecord::print()const
{

	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Publisher: " << getPublisher() << endl;
	cout << "ISBN: " << getISBN() << endl;

}

//Comparers

int BookRecord::compareByISBN(BookRecord other)const
{

	return getISBN() - other.getISBN();

}

int BookRecord::compareByTitle(BookRecord other)const
{

	return getTitle().compare(other.getTitle());

}
