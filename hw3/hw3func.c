/*

CSE230 - Homework 3

Kuba Gasiorowski, kgasiorowski, kuba.gasiorowski@stonybrook.edu

Contains all function implementations
for this program.

*/

#include "hw3func.h"

//Test a user file with "results.txt". The
//number of differences is returned.
int testFile(char expectedResultFileName[])
{

	#ifdef debug
	printf("Entering testFile call");
	#endif

	int expectedResult, computedResult, differenceCount = 0;

	FILE *outputFile, *expectedResultsFile;

	if((outputFile = fopen("output.txt", "r")) == NULL)
	{

		printf("Program output cannot be opened.\n");
		return -1;

	}

	//Searches for results.txt which containts the expected program output
	if((expectedResultsFile = fopen(expectedResultFileName, "r")) == NULL)
	{

		printf("Expected result file cannot be opened.\n");
		return -1;

	}

	int i;
	for(i = 0; i < 15; i++)
	{

		fscanf(outputFile, "%d", &computedResult);
		fscanf(expectedResultsFile, "%d", &expectedResult);

		if(computedResult != expectedResult)
		{

			printf("Output mismatch! Expected %d, found %d\n", expectedResult, computedResult);
			differenceCount++;

		}



	}

	#ifdef debug
	printf("Exiting testFile call");
	#endif

	fclose(outputFile);
	fclose(expectedResultsFile);

	return differenceCount;

}

//Gets user input
void getInput(char sourceName[MAX_NAME_SIZE], char inputFile[MAX_NAME_SIZE], char outputFile[MAX_NAME_SIZE])
{

	printf("Enter the name of the source file:");
        scanf("%s", sourceName);

        printf("Enter the input file name:");
        scanf("%s", inputFile);

        printf("Enter the expected results file name:");
        scanf("%s", outputFile);

}
