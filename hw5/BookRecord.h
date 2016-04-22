/*

	Kuba Gasiorowski, NETID: kgasiorowski, kuba.gasiorowski@stonybrook.edu

	Essentially a book. Has a publisher, author, title, and an ISBN number.

*/

#ifndef BOOKRECORD
#define BOOKRECORD

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class BookRecord{

	public:
		//Constructors
		BookRecord();
		BookRecord(string, string, string, int);
		
		//Mutators
		void setTitle(string);
		void setAuthor(string);
		void setPublisher(string);
		void setISBN(int);
		
		//Accessors
		string getTitle() const;
		string getAuthor() const;
		string getPublisher() const;
		int getISBN() const;
		
		//Regular methods
		virtual void print() const;
		
		//Comparers
		int compareByISBN(BookRecord) const;
		int compareByTitle(BookRecord) const;
		
	//In preparation for inheritance
	protected:
		string title, publisher, author;
		int ISBN;


};
#endif
