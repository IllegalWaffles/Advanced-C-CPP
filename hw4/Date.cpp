using namespace std;

#include "Date.h"

const int Date::daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//Standard constructor
Date::Date(int m, int d, int y)
{
		
	setDate(m,d,y);
		
}

//Default constructor
Date::Date(){}

//Parses a string, and returns a date object.
//Expects mm/dd/yyyy format.
Date Date::parseDateFromString(string input)
{

	if(input.length() != 10)
		throw "Bad date format";

	int day, month, year;
	
	char temp[2], otherTemp[4];
	
	strcpy(temp, input.substr(0,2).c_str());
	month = atoi(temp);
	
	strcpy(temp, input.substr(3,2).c_str());
	day = atoi(temp);
	
	strcpy(otherTemp, input.substr(6,4).c_str());
	year = atoi(otherTemp);
	
	return Date(month, day, year);

}

//Prints this date, for debugging purposes
void Date::print() const
{

	cout << getMonth() << "/" << getDay() << "/" << getYear();

}

//Provides code to compare two dates. 
//Earlier dates are considered smaller than larger dates.
int Date::compare(Date d) const
{

	if(d.getYear() == getYear())
	{
	
		if(d.getMonth() == getMonth())
		{
		
			if(d.getDay() == getDay())
				return 0;
			else return getDay() - d.getDay();
		
		}
		else return getMonth() - d.getMonth();
	
	}
	else return getYear() - d.getYear();

}

//Checks if the caller is between date first and date second, inclusive.
bool Date::isBetween(Date first, Date second) const
{

	return compare(first) >= 0 && compare(second) <= 0;

}

//Setters
void Date::setMonth(int i)
{

	if(i < 1 || i > 12)
	{
		
		throw "Invalid month entered";
		
	}

	Date::month = i;
	

}

void Date::setDay(int i)
{

	if(i < 0 || i > getNumDaysInMonth(getMonth(), getYear()))
		throw "Invalid day entered";

	Date::day = i;

}

void Date::setYear(int i)
{

	if(i <= 0)
		throw "Invalid year entered";

	Date::year = i;
	
}

//More convenient setter for all three members.
void Date::setDate(int m, int d, int y)
{

	setMonth(m);//Month and year do not depend on anything. Set them first.
	setYear(y);
	setDay(d);//Day depends on month, which depends on year.

}

//Getters
int Date::getDay() const {return Date::day;}
int Date::getMonth() const {return Date::month;}
int Date::getYear() const {return Date::year;}
int Date::getNumDaysInMonth(int month, int year) {

	if(month == 2)//If the month is feb
		if(((year % 100) == 0 && (year % 400) == 0)//If it's a century year and divisible by 400
		  || year % 4)							   //OR if it's just a year divisible by 4
			return Date::daysPerMonth[month] + 1;  //It must be a leap year. Add 1
		
	return Date::daysPerMonth[month];

}
