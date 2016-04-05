#ifndef HIT
#define HIT

#include "Date.h"
#include "Debug.h"
using namespace std;

class Hit{
		
	public:
		//Regular methods
		void print() const
		{
		
			cout << "Address: " << getAddress() << " Date of access: ";
			getDate().print();
		
		}
		
		//Constructors
		Hit(){}
		
		Hit(Date dateOfAccess, string address)
		{
		
			setDate(dateOfAccess);
			setAddress(address);
		
		}
		
		//Setters
		void setDate(Date d){dateOfAccess = d;}
		void setAddress(string s){address = s;}
		
		//Getters
		Date getDate() const {return dateOfAccess;}
		string getAddress() const {return address;}
		
	private:
		string address;
		Date dateOfAccess;

};
#endif
