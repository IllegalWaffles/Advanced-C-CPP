/*

	Kuba Gasiorowski, NETID: kgasiorowski, kuba.gasiorowski@stonybrook.edu

	This class represents a list of books.

*/

#ifndef LISTRECORDS
#define LISTRECORDS

#define TABLE_SIZE 200
#include "BookRecord.h"
#include "TypeBookRecord.h"
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
		void printheader();

};
#endif
