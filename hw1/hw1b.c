#include <stdio.h>
#define MAX_NUM_CHARS 26

/*

Kuba Gasiorowski, kgasiorowski, 109776237, kuba.gasiorowski@sbu.edu

Used compiler TDM-GCC 4.9.2

Reads a bunch of characters from the console
and prints out the frequency of each lower-case
alphabetical character.

*/

int main()
{
	
	//Declare the stuff we need
	int bucket[MAX_NUM_CHARS], i, currentChar;
	char c;
	
	//Initializes the array to zero
	for(i = 0; i < 26; i++)
		bucket[i] = 0;
	
	//Read a bunch of characters. 
	while((c=getchar()) != EOF)
	{
		
		//Little bit of input validation
		if(c-'a' >= 0 && c-'a' < 26)
			bucket[c-'a']++;
		
	}
	
	//The rest is output
	printf("\n\nLetter    Count\n------    -----\n");
	
	for(i = 0; i < 26; i++)
		printf("%3c%10d\n", i+'a', bucket[i]);
	
	return 0;
	
}
