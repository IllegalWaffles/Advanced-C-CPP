#ifndef LINK
#define LINK

#include "Hit.h"
#define MAX_HIT_ARRAY_VALUE 100
using namespace std;

class Link{

	public:
		//Constructors
		Link(){
		
			uniqueHits = 0;
			returnHits = 0;
		
		}
		
		Link(string s){setLinkName(s);}
		
		//Setters
		void setLinkName(string s){linkName = s;}
		
		//Getters
		string getLinkName() const {return linkName;}
		int getUniqueHits() const {return uniqueHits;}
		int getReturnHits() const {return returnHits;}
		int getTotalHits() const {return getUniqueHits() + getReturnHits();}
		
		//Regular methods
		void addHit(Hit h)
		{
		
			cout << "Entered addHit method for object " << getLinkName() << endl;
			
			//Add the hit
			hits[getTotalHits()] = h;
		
			cout << "Total number of hits: " << getTotalHits() << endl;
		
			//Determine if it's a unique hit or a returning hit
			
			//Check each hit and see if it matches with the new hit's name
			for(int i = 0; i < getTotalHits(); i++){
				
				cout << "Comparing " << h.getAddress() << " to " << hits[i].getAddress() << endl;
				
				if(h.getAddress().compare(hits[i].getAddress()) == 0)
				{
					
					cout << "Match detected! Return hits incremented" << endl;
					returnHits++;//If it does, increment returnhits
					cout << "Unique hits: " << uniqueHits << endl;
					cout << "Return hits: " << returnHits << endl;
					cout << "Exiting addhit method..." << endl << endl;
					return;
				}
			}
			
			cout << "No match detected. This is a unique hit" << endl;
			//If no match exists, increment uniqueHits
			uniqueHits++;
		
			cout << "Unique hits: " << uniqueHits << endl;
			cout << "Return hits: " << returnHits << endl;
			cout << "Exiting addhit method..." << endl << endl;
		
		}
		
		void print() const
		{
		
			cout << "Link name: " << linkName << endl;
			
			for(int i = 0; i < getTotalHits(); i++)
			{
			
				cout << "Hit " << i+1 << ":"; 
				hits[i].print();
				cout << endl;	
			
			}
		
		
		}
		
	private:
		int uniqueHits, returnHits;
		Hit hits[MAX_HIT_ARRAY_VALUE];
		string linkName;

};
#endif
