#include <iostream>
#include <fstream>
#include "Host.h"
#include <stdexcept>


#define MAX_HOST_ARRAY_VALUE 100

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
	
	string address, hostname, tempDateString;
	Host hosts[MAX_HOST_ARRAY_VALUE];
	unsigned int numHosts = 0, lineNum = 0;
	
	cout << "Loading " << inputFileName << "..." << endl;
	while(in >> address >> hostname >> tempDateString)
	{
		
		//Line number is always incremented
		lineNum++;
		
		if(address.at(0) == '/' && address.at(1) == '/')
		{
			
			cout << "Line " << lineNum << " commented, skipping" << endl;
			continue;
		
		}
		
		try{
			
			//Make the hit
			//We don't know if it's unique or not, that is determined later on,
			//So it doesn't matter what we pass in for now.
			Hit newHit(Date::parseDateFromString(tempDateString), address, hostname, false);
			bool matchFound = false;
			
			//Logic to figure out which host this hit belongs to
			for(int i = 0; i < numHosts && !matchFound; i++)
			{
			
				cout << "Comparing " << hosts[i].getName() << " and " << hostname << endl;
			
				 if(hosts[i].getName().compare(hostname) == 0)
				 {
				 
				 	matchFound = true;
				 	hosts[i].addHit(newHit);
				 
				 }
			
			}
		
			if(!matchFound)
			{
			
				hosts[numHosts] = Host(hostname);
				hosts[numHosts].addHit(newHit);
				numHosts++;
				cout << "New host added. Total number of hosts: " << numHosts << endl;
				
			}
		
		
		}catch(const char* msg){
			
			cerr << "Line " << lineNum << ": There was an issue with the date format, skipping... (" << msg << ")" << endl;
			continue;//Skip this line
			
		}
		
		
		
	}
	
	in.close();
	
	//Prints the menu and waits for input
	cout << endl;
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
			string tempStartDate, tempEndDate, hostname;
			int numReturnHits, numUniqueHits;
			
			//Get our input
			cout << "Enter a link name:";
			cin >> hostname;
			cout << "Enter the beginning date [mm/dd/yyyy]:";
			cin >> tempStartDate;
			cout << "Enter the ending date [mm/dd/yyyy]:";
			cin >> tempEndDate;
		
			//Parse our input
			try{
			
				Date startDate = Date::parseDateFromString(tempStartDate);
				Date endDate = Date::parseDateFromString(tempEndDate);
			
				if(startDate.compare(endDate) > 0)
					throw "Wrong date order";
				
				for(int i = 0; i < numHosts; i++)
				{
					
					//Logic to parse through the list of hosts here
					if(hostname.compare(hosts[i].getName()) == 0)
					{
					
						numUniqueHits = hosts[i].getUniqueHitsBetween(startDate, endDate);
						numReturnHits = hosts[i].getReturnHitsBetween(startDate, endDate);
						break;
					
					}
					
				}
			
				//Lets avoid annoying pointer operations here
				char temp[] = "%-10s%5d\n";
				char *fmtStr = temp;
			
				//Print the stuff
				cout << "Link: " << hostname << endl;
				printf(fmtStr, "Total hits", numUniqueHits + numReturnHits);
				printf(fmtStr, "Unique:", numUniqueHits);
				printf(fmtStr, "Returning:", numReturnHits);
			
			
			}catch(const char* msg){
			
				//There was an error
				cerr << "Invalid date entered: " << msg << endl;
			
			}
		
		}
		else if(cmd.compare("2") == 0)
		{
			
			//Prints information about all link hits
			
			//Print our header
			cout << "     Link Name		Unique Visits	Return Visits	Total Visits" << endl;
			cout << "--------------------	-------------	-------------	------------" << endl;
			
			//Make the format string
			char temp[] = "%-24s%7d%16d%16d\n";
			const char *fmt = temp;
			
			//Print each object
			for(int i = 0; i < numHosts; i++)
				printf(fmt, hosts[i].getName().c_str(), hosts[i].getUniqueHits(), hosts[i].getReturnHits(), hosts[i].getTotalHits());
			
			
		}
		else if(cmd.compare("3") == 0)
		{
			
			//Re-print the menu
			printMenu();
			
		}
		else
			cout << "Invalid command" << endl;
		
	}//Terminate input loop
	
	return 0;
	
}
