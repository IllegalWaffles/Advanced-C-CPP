#include "ListRecords.h"

using namespace std;

//Contructors
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

//Regular methods
void ListRecords::insertBookInfo(BookRecord b)
{
	
	records[numBooks++] = b;
	
}

void ListRecords::printBookInfo(int ISBN)
{
	
	for(int i = 0; i < numBooks; i++)
		if(ISBN == records[i].getISBN())
			records[i].print();
			
}

void ListRecords::printListByISBN()
{
	
	
	
}

void ListRecords::printgListByTitle()
{
	
	
	
}

void ListRecords::printBooks()
{

	for(int i = 0; i < numBooks; i++)
		records[i].print();

}

bool ListRecords::containsISBN(int isbnNumber)
{

	for(int i = 0; i < numBooks; i++)
		if(isbnNumber == records[i].getISBN())
			return true;
	
	return false;

}
