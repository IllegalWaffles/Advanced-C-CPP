#include <iostream>
#include <fstream>
#include "Link.h"
#include "Debug.h"

#define MAX_LINK_ARRAY_VALUE 100

using namespace std;

//Helper method to print the menu
void printMenu()
{
	
	cout << "Please select a menu option:" << endl;
	cout << "1)Link Information in date range" << endl;
	cout << "2)Information about all links" << endl;
	cout << "3)Re-print the menu"<< endl;
	cout << "4)Exit the program" << endl;
	
}

int main()
{
	
	//Local vars we will need
	bool finished = true;
	string cmd, inputFileName;
	unsigned int numLinks = 0;
	Link linkList[MAX_LINK_ARRAY_VALUE];
	
	//Get the input file name
	cout << "Enter an input file:";
	//cin >> inputFileName;
	
	inputFileName = "input.txt";
	
	//Code to read in and parse the file
	ifstream in;
	in.open(inputFileName.c_str());
	
	string address, linkName, tempDateString;
	
	while(in >> address >> linkName >> tempDateString)
	{
		
		//Iterate over each link currently in the linklist
		//Check if this newly visited link name is new or a revisit
		
		//Create the new hit object
		Hit newHit(Date::parseDateFromString(tempDateString), address);
		
		
		if(numLinks != 0)
		{
		
			bool hitWasAdded = false;
		
			for(int i = 0; i < numLinks; i++)
			{
				
				if(linkList[i].getLinkName().compare(linkName) == 0)//The linkname matches something already in the list.
				{												 	//Add the info
				
					linkList[i].addHit(newHit);
					hitWasAdded = true;
					break;
					
				}
		
			}
		
			//No match was found
			if(!hitWasAdded)
			{
			
				Link tempLink(linkName);
				tempLink.addHit(newHit);
				linkList[numLinks++] = Link(tempLink);
			
			}
		
		}
		else//This is the first link. Add it to the array of links
		{
		
			Link tempLink(linkName);
			tempLink.addHit(newHit);
			linkList[numLinks++] = Link(tempLink);
		
		}
		
	}
	
	in.close();
	
	//Prints the menu and waits for input
	//printMenu();
	
	
	while(!finished)
	{
		
		cout << "> ";
		cin >> cmd;
		
		if(cmd.compare("4") == 0 
		|| cmd.compare("q") == 0 
		|| cmd.compare("Q") == 0 
		|| cmd.compare("exit") == 0 
		|| cmd.compare("EXIT") == 0)
		{
			
			cout << "Exiting..." << endl;
			finished = true;
			
		}
		else if(cmd.compare("1") == 0)
		{
			
			//Prints all link information between two dates
			string tempFirstDate, tempSecondDate;
			
			cout << "Enter the beginning date [mm/dd/yyyy]:";
			cin >> tempFirstDate;
			cout << "Enter the ending date [mm/dd/yyyy]:";
			cin >> tempSecondDate;
			
			Date firstDate = Date::parseDateFromString(tempFirstDate);
			Date secondDate = Date::parseDateFromString(tempSecondDate);
		
		}
		else if(cmd.compare("2") == 0)
		{
			
			//Prints information about all link hits
			
		}
		else if(cmd.compare("3") == 0)
		{
			
			//Re-print the menu
			printMenu();
			
		}
		
	}//Terminate input loop
	
	return 0;
	
}
