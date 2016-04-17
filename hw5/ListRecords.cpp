#include "ListRecords.h"

using namespace std;

//Contructors
//Construct a record list from a file
ListRecords::ListRecords(string filename)
{
	
	string author, title, publisher, tempISBN;
	int ISBN;
	numBooks = 0;
	ifstream inputfile(filename.c_str());
	char temp[11];
	
	if(inputfile.is_open())
	
		while(getline(inputfile, title))
		{
			
			getline(inputfile, author);
			getline(inputfile, publisher);
			getline(inputfile, tempISBN);
			
			strcpy(temp,tempISBN.c_str());
			ISBN = atoi(temp);
			
			if(containsISBN(ISBN))
			{
			
				cout << "Duplicate ISBN detected (entry " << numBooks+1 << "), skipping..." << endl;
				continue;
			
			}
			
			records[numBooks++] = BookRecord(title, author, publisher, ISBN);
			
			getline(inputfile, title);
			
		}
	
	else throw "Could not open file";
	
}

//Returns true if the isbn number is contained in the
//records, false if now
bool ListRecords::containsISBN(int isbnNumber)
{

	for(int i = 0; i < numBooks; i++)
		if(isbnNumber == records[i].getISBN())
			return true;
	
	return false;

}

//Regular methods
//Inserts a book into the records
void ListRecords::insertBookInfo(BookRecord b)
{
	
	if(containsISBN(b.getISBN()))
		throw "This record list already has a book under this ISBN";
	else 
		records[numBooks++] = b;
	
}

//Prints a book if it has a matching ISBN number
void ListRecords::printBookInfo(int ISBN)
{
	
	for(int i = 0; i < numBooks; i++)
		if(ISBN == records[i].getISBN())
			records[i].print();
			
}

//Prints the list of records organized by ISBN number.
void ListRecords::printListByISBN()
{
	
	sortByISBN();
	printBooks();
	
}

//Prints the list of books organized by title
void ListRecords::printListByTitle()
{
	
	sortByTitle();
	printBooks();
	
}

//Prints the books sequentially
void ListRecords::printBooks()
{
	
	printHeader();
	for(int i = 0; i < numBooks; i++){
	
		cout.setf(ios::left, ios::adjustfield);
		cout << setw(22) << records[i].getTitle() << records[i].getAuthor() << endl;

	}

}

//Helper method that sorts the list by ISBN ascending
void ListRecords::sortByISBN()
{
	
	int numSorted = 0;
	
	while(numSorted != numBooks)
	{
		
		for(int i = 0; i < numBooks-numSorted-1; i++)
			if(records[i].getISBN() > records[i+1].getISBN())
				swap(records[i], records[i+1]);
		
		numSorted++;
		
	}
	
}

//Helper method that sorts the list by title ascending
void ListRecords::sortByTitle()
{
	
	int numSorted = 0;
	
	while(numSorted != numBooks)
	{
		
		for(int i = 0; i < numBooks-numSorted-1; i++)
			if(records[i].getTitle().compare(records[i+1].getTitle()) > 0)
				swap(records[i], records[i+1]);
			
			numSorted++;
		
	}
	
}

void ListRecords::printHeader()
{
	
	cout << "        Title                 Author               publisher           ISBN" << endl;
	cout << "---------------------- ---------------------- ---------------------- ----------" << endl;
	
}
