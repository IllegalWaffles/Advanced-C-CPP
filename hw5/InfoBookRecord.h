#ifndef INFOBOOKRECORD
#define INFOBOOKRECORD

#include "BookRecord.h"
class InfoBookRecord:public BookRecord{

	public:
		InfoBookRecord();
		InfoBookRecord(string, string, string, int, string, double);
		
		void setBiography(string);
		void setPrice(double);
		string getBiography();
		double getPrice();

		void print() const;

	private:
		string biography;
		double price;

};
#endif
