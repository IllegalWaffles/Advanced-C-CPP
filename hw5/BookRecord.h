#ifndef BOOKRECORD
#define BOOKRECORD

#include <string>
#include <iostream>

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
		void print() const;
		
		//Comparers
		int compareByISBN(BookRecord) const;
		int compareByTitle(BookRecord) const;
		
	private:
		string title, publisher, author;
		int ISBN;


};
#endif
