#ifndef DATE
#define DATE

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

//Helper class used to better organize dates
class Date{

	public:
		
		
		
		//Standard constructor
		Date(int, int, int);
		
		//Default constructor
		Date();
		
		//Parses a string, and returns a date object.
		//Expects mm/dd/yyyy format.
		static Date parseDateFromString(string);
		
		//Prints this date, for debugging purposes
		void print() const;
		
		//Provides code to compare two dates. 
		//Earlier dates are considered smaller than larger dates.
		int compare(Date d) const;
		
		//Checks if the caller is between date first and date second, inclusive.
		bool isBetween(Date, Date) const;
		
		//Setters
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		
		//More convenient setter for all three members.
		void setDate(int, int, int);
		
		//Getters
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		static int getNumDaysInMonth(int, int);
		
	private:
		int day;
		int month;
		int year;
		static const int daysPerMonth[12];
};
#endif
