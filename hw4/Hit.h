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
		
		Hit(Date, string, string, bool);
		
		//Setters
		void setDate(Date);
		void setAddress(string);
		void setHost(string);
		void setIsUnique(bool);
		
		//Getters
		Date getDate() const;
		string getAddress() const;
		string getHost() const;
		bool isUnique() const;
		
	private:
		string address;
		string host;
		Date dateOfAccess;
		bool unique;

};
#endif
