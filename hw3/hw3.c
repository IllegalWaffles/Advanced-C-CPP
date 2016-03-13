#include "hw3func.h"

int main()
{

	//Initialize some stuff!
	system("clear");

	char sourceName[MAX_NAME_SIZE], inputFile[MAX_NAME_SIZE], outputFile[MAX_NAME_SIZE];
	char command[MAX_NAME_SIZE * 3];
	int grade = 100;

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

	//Attempt to compile the student's program
	if(system(command) != 0)
	{

		grade -= 100;
		printf("The students program could not be compiled. Grade: %d", grade);
		return 0;

	}

	//Build the second command to test the student's program
	command[0] = '\0';
	strcpy(command, "./myProj ");
	strcat(command, inputFile);
	strcat(command, " > ");
	strcat(command, outputFile);

	//Attempt to run the student's program with test input
	if(system(command) != 0)
	{

		grade -= 100;
		printf("There was a problem running the program. Grade: %d", grade);
		return 0;

	}

	//Compare output file with expected results

	int numMistakes = testFile(outputFile);

	if(numMistakes == 0)
		printf("Output is correct. Grade: %d\n", grade);
	else if(numMistakes == -1){

		grade -= 100;
		printf("There was an error reading one of the files. Grade: %d", grade);

	}
	else
	{

		grade -= numMistakes * 5;
		printf("Output was incorrect. There were %d mistakes.\nGrade: %d\n", numMistakes, grade);

	}

	return 0;

}
