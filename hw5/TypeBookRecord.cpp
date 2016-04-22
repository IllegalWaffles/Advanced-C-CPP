#include "TypeBookRecord.h"
TypeBookRecord::TypeBookRecord()
{

	TypeBookRecord("","","",0,"");

}

TypeBookRecord::TypeBookRecord(string title, string author, string publisher, int ISBN, string type)
{

	setTitle(title);
	setAuthor(author);
	setPublisher(publisher);
	setISBN(ISBN);
	setType(type);

}

void TypeBookRecord::setType(string s){type = s;}

string TypeBookRecord::getType(){return type;}

void TypeBookRecord::print() const{

	BookRecord::print();//Prints all the standard information
	
	string tempType;
	if(type.length() > 15)
		tempType = type.substr(0,15);
	else 
		tempType = type;

	cout.setf(ios::left, ios::adjustfield);
	cout << " " << setw(15) << tempType;

}
