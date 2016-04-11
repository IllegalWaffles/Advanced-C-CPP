/*

CSE230 - Homework 3

Kuba Gasiorowski, kgasiorowski, kuba.gasiorowski@stonybrook.edu

Main driver program behind this assignment.
Asks for a source file, an input text file,
and output text file. Compiles the source, and
attemps to run it with the input text file,
while writing it to the output file. Then assigns
it a grade based on compilability, runability, and
output correctness.

*/

#include "hw3func.h"

int main()
{

	//Initialize some stuff!
	system("clear");

	char sourceName[MAX_NAME_SIZE], inputFile[MAX_NAME_SIZE], outputFile[MAX_NAME_SIZE];
	char command[MAX_NAME_SIZE * 3];
	int grade = 100;

	//Get user input
	getInput(sourceName,  inputFile,  outputFile);

	//Build the first command to compile the program
	command[0] = '\0';
	strcpy(command, "gcc -o myProj ");
	strcat(command, sourceName);

	//Attempt to compile the student's program
	if(system(command) != 0)
	{

		//Uncompilable code. Zero.
		grade -= 100;
		printf("The students program could not be compiled. Grade: %d\n", grade);
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

		//Program won't run. Gets a zero.
		grade -= 100;
		printf("There was a problem running the program. Grade: %d\n", grade);
		return 0;

	}

	//Compare output file with expected results

	int numMistakes = testFile(outputFile);

	if(numMistakes == 0)
		printf("Output is correct. Grade: %d\n", grade);
	else if(numMistakes == -1)
	{

		//One of the files couldn't be opened. Zero.
		grade -= 100;
		printf("There was an error reading one of the files. Grade: %d", grade);

	}
	else
	{

		//Minus 5 points per mistake
		grade -= numMistakes * 5;
		printf("Output was incorrect. There were %d mistakes.\nGrade: %d\n", numMistakes, grade);

	}

	return 0;

}
