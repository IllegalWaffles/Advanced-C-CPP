#ifndef LISTRECORDS
#define LISTRECORDS

#define TABLE_SIZE 200
#include "BookRecord.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
class ListRecords{

	public:
		//Contructors
		ListRecords(string);
		
		//Regular methods
		void insertBookInfo(BookRecord);
		void printBookInfo(int);
		void printListByISBN();
		void printgListByTitle();
			
		void printBooks();
		
		bool containsISBN(int);
			
	private:
		BookRecord records[TABLE_SIZE];
		unsigned int numBooks;

};
#endif
