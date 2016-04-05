#ifndef DEBUG_CLASS
#define DEBUG_CLASS
#include <string>
#include <iostream>

#define DEBUG

class Debug{

	public:
	static void debug(std::string s)
	{
	
		#ifdef DEBUG
		std::cout << "DEBUG: " << s;
		#endif
	
	}
	
	static void debugnl(std::string s)
	{
	
		#ifdef DEBUG
		std::cout << "DEBUG: " << s << std::endl;
		#endif
	
	}

};
#endif
