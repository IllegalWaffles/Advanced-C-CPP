#include <iostream>
#include <fstream>
#include "Hit.h"
#include <stdexcept>

#define MAX_HIT_ARRAY_VALUE 100

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
	bool finished = false;
	string cmd, inputFileName;
	
	
	//Get the input file name
	cout << "Enter an input file:";
	cin >> inputFileName;
	
	//Code to read in and parse the file
	ifstream in;
	in.open(inputFileName.c_str());
	
	string address, host, tempDateString;
	Hit hitList[MAX_HIT_ARRAY_VALUE];
	unsigned int numHits = 0, lineNum = 0;
	
	while(in >> address >> host >> tempDateString)
	{
		
		try{
			
			lineNum++;
			Hit h = Hit(Date::parseDateFromString(tempDateString), address, host);
			hitList[numHits++] = h;
		
		}catch(const char* msg){
			
			cerr << "Line " << lineNum << ": There was an issue with the date format, skipping... (" << msg << ")" << endl;
			continue;//Skip this line
			
		}
		
	}
	
	in.close();
	
	//Prints the menu and waits for input
	printMenu();
	
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
			
			//Prints all link information between two dates, 
			//and for a specific host
			string tempFirstDate, tempSecondDate, hostName;
			
			cout << "Enter a link name:";
			cin >> hostName;
			cout << "Enter the beginning date [mm/dd/yyyy]:";
			cin >> tempFirstDate;
			cout << "Enter the ending date [mm/dd/yyyy]:";
			cin >> tempSecondDate;
		
			try{
			
				Date firstDate = Date::parseDateFromString(tempFirstDate);
				Date secondDate = Date::parseDateFromString(tempSecondDate);
			
				for(int i = 0; i < numHits; i++)
				{
					
					//Logic to parse through the list of hits here
					if(hostName.compare(hitList[i].getHost()) == 0){
					
						hitList[i].print();
						cout << endl;
					
					}
					
				}
			
			}catch(const char* msg){
			
				cerr << "Invalid date entered: " << msg << endl;
			
			}
		
			
		
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
