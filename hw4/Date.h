#ifndef DATE
#define DATE

#include "Debug.h"
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//Helper clqss used to better organize dates
class Date{

	public:
		
		//Standard constructor
		Date(int m, int d, int y)
		{
		
			setDate(m,d,y);
		
		}
		
		//Default constructor
		Date(){}
		
		//Parses a string, and returns a date object.
		//Expects mm/dd/yyyy format.
		static Date parseDateFromString(string input)
		{
		
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
		void print() const
		{
		
			cout << getMonth() << "/" << getDay() << "/" << getYear();
		
		}
		
		//Provides code to compare two dates. 
		//Earlier dates are considered smaller than larger dates.
		int compare(Date d) const
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
		bool isBetween(Date first, Date second) const
		{
		
			return compare(first) >= 0 && compare(second) <= 0;
		
		}
		
		//Setters
		void setMonth(int i){month = i;}
		void setDay(int i){day = i;}
		void setYear(int i){year = i;}
		
		//More convenient setter for all three members.
		void setDate(int m, int d, int y)
		{
		
			setMonth(m);
			setDay(d);
			setYear(y);
		
		}
		
		//Getters
		int getDay() const {return day;}
		int getMonth() const {return month;}
		int getYear() const {return year;}
		
	private:
		int day;
		int month;
		int year;

};
#endif
