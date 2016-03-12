#include "hw3func.h"

int main()
{

	//Initialize some stuff!
	system("clear");

	char sourceName[MAX_NAME_SIZE], inputFile[MAX_NAME_SIZE], outputFile[MAX_NAME_SIZE];
	char command[MAX_NAME_SIZE * 3];

	//Get user input
	printf("Enter the name of the source file:");
	scanf("%s", sourceName);

	printf("Enter the input file name:");
	scanf("%s", inputFile);

	printf("Enter the output file name:");
	scanf("%s", outputFile);

	//Build the first command to compile the program
	command[0] = '\0';
	strcpy(command, "gcc -o myProj ");
	strcat(command, sourceName);

	#ifdef debug
	printf("Command 1: %s\n", command);
	#endif

	system(command);

	//Build the second command to actually use the student's program
	command[0] = '\0';
	strcpy(command, "./myProj ");
	strcat(command, inputFile);
	strcat(command, " > ");
	strcat(command, outputFile);

	#ifdef debug
	printf("Command 2: %s\n", command);
	#endif

	system(command);

	//Compare output file with expected results

	testFile(outputFile);

	return 0;

}
