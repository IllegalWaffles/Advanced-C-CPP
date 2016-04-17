#ifndef LISTRECORDS
#define LISTRECORDS

#define TABLE_SIZE 200
#include "BookRecord.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
class ListRecords{

	public:
		//Contructors
		ListRecords(string);
		
		//Regular methods
		void insertBookInfo(BookRecord);
		void printBookInfo(int);
		void printListByISBN();
		void printListByTitle();
		bool containsISBN(int);
			
	private:
		BookRecord records[TABLE_SIZE];
		unsigned int numBooks;

		void sortByISBN();
		void sortByTitle();
		void printBooks();
		void printHeader();

};
#endif
