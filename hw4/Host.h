#ifndef HOST
#define HOST

#define MAX_HITS_PER_HOST 100
#include <iostream>
#include <string>
#include "Hit.h"
using namespace std;

class Host{

	public:
	//Constructors
	Host();
	Host(string);
		
	//Setters
	void setName(string);
	void incrementReturnHits();
	void incrementUniqueHits();
	void addHit(Hit);
		
	//Getters
	string getName();
	int getTotalHits();
	int getReturnHits();
	int getUniqueHits();
	
	//Gets the number of unique hits between two dates
	int getUniqueHitsBetween(Date, Date);
	
	//Gets the number of return hits between two dates
	int getReturnHitsBetween(Date, Date);
	
	private:
		string hostname;
		Hit hits[MAX_HITS_PER_HOST];
		int returnHits, uniqueHits;
		

};
#endif
