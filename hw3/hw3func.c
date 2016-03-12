#include <stdio.h>
#include <stdlib.h>
#include "hw3func.h"

int testFile(char outputFileName[])
{

	#ifdef debug
	printf("Entering testFile call");
	#endif

	int expectedResult, computedResult, differenceCount = 0;

	FILE *outputFile = fopen(outputFileName, "r");
	FILE *expectedResults = fopen("results.txt", "r");

	while(fscanf(outputFile, "%d", &computedResult) != 1 || fscanf(expectedResults, "%d", &expectedResult) != 1)
	{

		printf("Expected result: %d Computed result: %d" , expectedResult, computedResult);

	}

	#ifdef debug
	printf("Exiting testFile call");
	#endif

	return differenceCount;

}
