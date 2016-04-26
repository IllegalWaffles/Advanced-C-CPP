/*

	Kuba Gasiorowski, NETID: kgasiorowski, kuba.gasiorowski@stonybrook.edu

	Essentially a book. Has a publisher, author, title, and an ISBN number.
	

*/
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
//For any string input, it will be cut down to 40 characters
void BookRecord::setTitle(string s){title = s.length()>40?s.substr(0,40):s;}
void BookRecord::setPublisher(string s){publisher = s.length()>40?s.substr(0,40):s;}
void BookRecord::setAuthor(string s){author = s.length()>40?s.substr(0,40):s;}
void BookRecord::setISBN(int i){ISBN = i;}

//Accessors
string BookRecord::getTitle()const{return title;}
string BookRecord::getAuthor()const{return author;}
string BookRecord::getPublisher()const{return publisher;}
int BookRecord::getISBN()const{return ISBN;}

//Print method
void BookRecord::print()const
{

	string tempTitle, tempAuthor, tempPublisher;
		
	if(getTitle().length() > 22)
		tempTitle = getTitle().substr(0,22);
	else
		tempTitle = getTitle();
	
	if(getAuthor().length() > 22)
		tempAuthor = getAuthor().substr(0,22);
	else
		tempAuthor = getAuthor();
	
	if(getPublisher().length() > 22)
		tempPublisher = getPublisher().substr(0,22);
	else
		tempPublisher = getPublisher();
	
	//Re-initialize our output settings
	cout.setf(ios::left, ios::adjustfield);
	cout << setfill(' ');
	
	//Print the title, author, and publisher
	cout << setw(22) << tempTitle << " ";
	cout << setw(22) << tempAuthor << " "; 
	cout << setw(22) << tempPublisher << " ";
	
	//Prints the ISBN number
	cout.setf(ios::right, ios::adjustfield);
	cout << setw(10) << setfill('0') << getISBN();
	cout << setfill(' ') << " ";

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
