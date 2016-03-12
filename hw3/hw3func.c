#include "hw3func.h"

int testFile(char outputFileName[])
{

	#ifdef debug
	printf("Entering testFile call");
	#endif

	int expectedResult, computedResult, differenceCount = 0;

	FILE *outputFile, *expectedResultsFile;

	if((outputFile = fopen(outputFileName, "r")) == NULL)
	{

		printf("Program output cannot be opened.");
		return -1;

	}

	if((expectedResultsFile = fopen("results.txt", "r")) == NULL)
	{

		printf("Expected result file cannot be opened.");
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
