#include "Hit.h"

//Regular methods
void Hit::print() const
{

	cout << "ADDRESS: " << getAddress() << endl << "HOST: " << getHost() << endl << "DATE OF ACCESS: ";
	getDate().print();
	cout << endl;

}

//Constructors
Hit::Hit(){}

Hit::Hit(Date dateOfAccess, string address, string host, bool isUnique)
{

	setDate(dateOfAccess);
	setAddress(address);
	setHost(host);
	setIsUnique(isUnique);

}

//Setters
void Hit::setDate(Date d){dateOfAccess = d;}
void Hit::setAddress(string s){address = s;}
void Hit::setHost(string s){host = s;}
void Hit::setIsUnique(bool b){unique = b;}

//Getters
Date Hit::getDate() const {return dateOfAccess;}
string Hit::getAddress() const {return address;}
string Hit::getHost() const {return host;}
bool Hit::isUnique() const {return unique;}
