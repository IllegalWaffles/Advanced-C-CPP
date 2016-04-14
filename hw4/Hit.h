#ifndef HIT
#define HIT

#include "Date.h"
using namespace std;

class Hit{
		
	public:
		//Regular methods
		void print() const;
		
		//Constructors
		Hit();
		
		Hit(Date, string, string);
		
		//Setters
		void setDate(Date);
		void setAddress(string);
		void setHost(string);
		
		//Getters
		Date getDate() const;
		string getAddress() const;
		string getHost() const;
		
	private:
		string address;
		string host;
		Date dateOfAccess;
		

};
#endif
