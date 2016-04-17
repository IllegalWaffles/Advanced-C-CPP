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
		string getTitle();
		string getAuthor();
		string getPublisher();
		int getISBN();
		
		//Regular methods
		void print();
		
		//Comparers
		int compareByISBN(BookRecord);
		int compareByTitle(BookRecord);
		
	private:
		string title, publisher, author;
		int ISBN;


};
#endif
