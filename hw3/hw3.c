#include <stdio.h>
#include <string.h>
#define MAX_NAME_SIZE 100


int main(int argc, char *argv[])
{

	char sourceName[MAX_NAME_SIZE], inputFile[MAX_NAME_SIZE], outputFile[MAX_NAME_SIZE];

	char command[MAX_NAME_SIZE * 3];

	printf("Enter the name of the source file:");
	scanf("%s", sourceName);

	printf("Enter the input file name:");
	scanf("%s", inputFile);

	printf("Enter the output file name:");
	scanf("%s", outputFile);

	strcpy(command, "gcc -o myProj ");
	strcat(command, sourceName);

	int exitStatus = system(command);

	command[0] = '\0';//Clears the string

	strcpy(command, "./myProj ");
	strcat(command, inputFile);
	strcat(command, " > ");
	strcat(command, outputFile);

	printf("%s", command);

	system(command);

	printf("\n");
	return 0;

}
