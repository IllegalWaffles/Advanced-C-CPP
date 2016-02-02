#include <stdio.h>
#define MAX_NUM_CHARS 26

/*

Kuba Gasiorowski, kgasiorowski, 109776237, kuba.gasiorowski@sbu.edu

Used compiler TDM-GCC 4.9.2

Reads a bunch of characters from the console
and prints out the frequency of each lower-case
alphabetical character.

*/

int convertCharToInt(char);

int main()
{
	
	printf("%d", 'A');
	
	//Declare the stuff we need
	int bucket[MAX_NUM_CHARS], i, currentChar;
	char c;
	
	//Initializes the array to zero
	for(i = 0; i < 26; i++)
		bucket[i] = 0;
	
	//Read a bunch of characters. 
	while((c=getchar()) != EOF)
	{
		
		//Convert the char into the value we want
		i = convertCharToInt(c);
		
		//Little bit of input validation
		if(i>=0)
			bucket[i]++;
		
	}
	
	//The rest is output
	printf("\n\nLetter    Count\n------    -----\n");
	
	for(i = 0; i < 26; i++)
		printf("%3c%10d\n", i+'a', bucket[i]);
	
	return 0;
	
}

//Returns 0-25 for A-Z, case insensitive.
int convertCharToInt(char input)
{
	
	if(input-'a' >= 0 && input-'a' < 26)
		return input-'a';
	else if(input-'A' >= 0 && input-'A' < 26)
		return input-'A';
	else 
		return -1;
	
}
