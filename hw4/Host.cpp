#include "Host.h"

//Constructors
Host::Host()
{

	setName("");
	uniqueHits = returnHits = 0;

}

Host::Host(string s)
{

	setName(s);
	uniqueHits = returnHits = 0;

}

//Mutators
void Host::setName(string s){hostname = s;}
void Host::incrementReturnHits(){returnHits++;}
void Host::incrementUniqueHits(){uniqueHits++;}

//Adds a hit to the host that calls this method
void Host::addHit(Hit hitToAdd)
{
	
	int currentNumberOfHits = getTotalHits();
	bool matchFound = false;
	
	//cout << "Current number of hits for this host: " << currentNumberOfHits << endl;
	
	//cout << "Hit date:";
	//hitToAdd.getDate().print();
	//cout << " Hit location:" << hitToAdd.getAddress() << endl;
	
	for(int i = 0; i < currentNumberOfHits && !matchFound; i++)//Iterate through the whole list,
	{														   //Or until a match is found
	
		//cout << "Comparing " << hits[i].getAddress() << " to " << hitToAdd.getAddress() << endl;
	
		if(hits[i].getAddress().compare(hitToAdd.getAddress()) == 0)
		{
		
			matchFound = true;
			hitToAdd.setIsUnique(false);
			incrementReturnHits();
			//cout << "Match found - returning hits increased to " << getReturnHits() << endl;
		
		}
		
	}
	
	//No match was found. This is a unique hit!
	if(!matchFound){
		
		hitToAdd.setIsUnique(true);
		incrementUniqueHits();
		//cout << "No match was found - unique hits inreased to " << getUniqueHits() << endl;
	
	}
	
	//Finally, add the hit
	hits[currentNumberOfHits] = hitToAdd;
	
	//cout << "New number of hits: " << getTotalHits() << endl;

}

//Accessors
int Host::getTotalHits(){return getReturnHits() + getUniqueHits();}
int Host::getReturnHits(){return returnHits;}
int Host::getUniqueHits(){return uniqueHits;}
string Host::getName(){return hostname;}


//Gets the number of unique hits between two dates
int Host::getUniqueHitsBetween(Date begin, Date end)
{

	int counter = 0;

	for(int i = 0; i < getTotalHits(); i++){
		
		if(hits[i].getDate().isBetween(begin, end) && hits[i].isUnique())
			counter++;
	
	}
	
	return counter;

}

//Gets the number of return hits between two dates
int Host::getReturnHitsBetween(Date begin, Date end)
{

	int counter = 0;

	for(int i = 0; i < getTotalHits(); i++)
	{
	
		if(hits[i].getDate().isBetween(begin, end) && !hits[i].isUnique())
			counter++;
	
	}
	
	return counter;

}
