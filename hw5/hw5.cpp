#include <string>
#include <iostream>
#include "ListRecords.h"

void printMenu()
{

	cout << "Select an option from the following menu:" << endl;
	cout << "1)Insert a new book into the list" << endl;
	cout << "2)Print the info of a specific book by ISBN number" << endl;
	cout << "3)Print the list sorted by ISBN" << endl;
	cout << "4)Print the list sorted alphabetically by title" << endl;
	cout << "5)Print this menu once again" << endl;
	cout << "6)Quit the program" << endl;

}

int main()
{
	
	string inputFileName;

	cout << "Enter an input file name: ";
	cin >> inputFileName;

	try{
		
		ListRecords myList(inputFileName);
		
	}catch(const char* msg){
	
		cerr << "Error: " << msg << endl;
	
	}
	
	bool finished = false;
	printMenu();
	string cmd;
	
	while(!finished)
	{
	
		cout << ">";
		cin >> cmd;
	
		if(cmd.compare("6") == 0)
		{
		
			finished = true;
		
		}
		else if(cmd.compare("5") == 0)
		{
		
			printMenu();
			
		}
		else 
			cout << "Invalid command entered" << endl;
	
	}
	
	return 0;

}
