#ifndef TYPEBOOKRECORD
#define TYPEBOOKRECORD

#include <string>
#include "BookRecord.h"

class TypeBookRecord:public BookRecord{

	public:
		TypeBookRecord();
		TypeBookRecord(string, string, string, int, string);
		
		void setType(string);
		string getType();
		
		void print() const;
		
	private:
		string type;


};
#endif
