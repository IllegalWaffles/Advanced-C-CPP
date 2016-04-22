/*

	Kuba Gasiorowski, NETID: kgasiorowski, kuba.gasiorowski@stonybrook.edu

	This class represents a list of books.

*/

#include "ListRecords.h"

using namespace std;

//Contructors
//Construct a record list from a file
ListRecords::ListRecords(string filename)
{
	
	string author, title, publisher, tempISBN, emptyLine, USER_INPUT;
	bool exitFlag = true;
	int ISBN;
	numBooks = 0;
	ifstream inputfile(filename.c_str());
	char temp[11];
	
	if(inputfile.is_open())
	{
	
		cout << "WARNING - values of length > 40 will be cut down to 40 characters" << endl;
	
		while(getline(inputfile, title))
		{
			
			exitFlag = true;
			
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
			
			//Adds the book to the list
			do{
			
				cout << "For title: " << title << endl;
				cout << "Type or Info? [t/i]:";
				cin >> USER_INPUT;
			
				if(USER_INPUT.compare("t") == 0)
				{
				
					string tempInput;
					cout << "Enter type:";
					cin >> tempInput;
				
					BookRecord* test = &records[numBooks+1];
					
					test = new TypeBookRecord(title, author, publisher, ISBN, tempInput);
					exitFlag = false;
				
				}
				else if(USER_INPUT.compare("i") == 0)
				{
					
					/*char biography[100];
					double price;
					
					cout << "Enter biography:";
					cin.getline(biography, sizeof(biography));
					cout << "Enter price:";
					cin >> price;
					
					records[numBooks++] = InfoBookRecord(title, author, publisher, ISBN, string(biography), price);
					exitFlag = false;*/
				
				}
			
			}while(exitFlag);
			
			getline(inputfile, emptyLine);
			
		}
	
	}else throw "Could not open file";
	
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
	
	printheader();
	for(int i = 0; i < numBooks; i++){
	
		records[i].print();
		cout << endl;
		
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

void ListRecords::printheader()
{
	
	//The "extra information" section allows some wiggle room for the inheritance portion of the assignment
	cout << "        Title                 Author               publisher           ISBN              Extra Information" << endl;
	cout << "---------------------- ---------------------- ---------------------- ---------- -----------------------------------" << endl;
	
}