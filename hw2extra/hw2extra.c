#include <stdio.h>
#include <string.h>
#include "hw2functionsextra.h"

/*
 *	Kuba Gasiorowski, kgasiorowski, 109776237, kuba.gasiorowski@stonybrook.edu
 *
 *  Main file for this homework assignment. 
 *  
 *  Determines how many students are in a file, reads
 *  that many students from the file, and stores them
 *  into an array. Then, sorts the students alphabetically
 *  by last name and prints the array in an organized
 *  table.
 *  
 */

int main(int argc, char *argv[]){
	
	char inputFileName[100], outputFileName[100], c;
	FILE *inputFile, *outputFile;
	int i, numStudents = 1, errorFlag = 0;
	
	if(argc == 1)
	{
	
		//Try to open a file from stdin.
		//If it doesn't work, keep trying or q to quit.
		do{
		
			printf("Enter a file to read information from (or q to exit):");
			scanf("%s", inputFileName);
		
			if(strcmp(inputFileName, "q") == 0){
			
				printf("Terminating program...");
				return 0;
			
			}
			else if((inputFile = fopen(inputFileName, "r")) == NULL)
				printf("Error: file not found\n");
	
		}while(inputFile == NULL);
	
		outputFile = stdout;
	
	}
	else if(argc == 2)
	{
		
		//Only the input file was given
		strcpy(inputFileName, argv[1]);
		if((inputFile = fopen(inputFileName, "r")) == NULL)
		{
			
			printf("ERROR: Invalid file name");
			return 1;
			
		}
		
	}
	else if(argc == 3)
	{
		
		//Both input and output files were given
		strcpy(inputFileName, argv[1]);
		if((inputFile = fopen(inputFileName, "r")) == NULL)
		{
			
			printf("ERROR: Invalid input file name");
			return 1;
			
		}
		
		strcpy(outputFileName, argv[2]);
		if((outputFile = fopen(outputFileName, "w")) == NULL)
		{
			
			printf("ERROR: Invalid output file name");
			return 1;
			
		}
		
	}
	
	//Find how many students are here
	numStudents = getNumStudents(inputFile);
	
	//Create the array of students
	Student students[numStudents];
	
	//Code to scan info in
	for(i = 0; i < numStudents; i++)
	{
		
		//1301,107515018,"Boatswain","Michael R.",CSE, 230,="R01"
		
		if(fscanf(inputFile, "%d,", &(students[i].term)) != 1)
			errorFlag = 1;
			
		if(fscanf(inputFile, "%d,", &(students[i].id)) != 1)
			errorFlag = 1;
		
		if(fscanf(inputFile, "\"%[^,\"]\",", students[i].lastName) != 1)
			errorFlag = 1;
		
		if(fscanf(inputFile, "\"%[^,\"]\",", students[i].firstName) != 1)
			errorFlag = 1;
		
		if(fscanf(inputFile, "%[^,],", students[i].subject) != 1)
			errorFlag = 1;
		
		if(fscanf(inputFile, "%d", &(students[i].catalogNumber)) != 1)
			errorFlag = 1;
		
		fscanf(inputFile, "%*[^=]=");
		
		if(fscanf(inputFile, "\"%[^\"]", students[i].section) != 1)
			errorFlag = 1;
		
		fscanf(inputFile, "%*[^\n]");//Reads out to the end of the line to avoid errors
		
		if(errorFlag)
			printf("WARNING: Unexpected or invalid input encountered on line %d!\nUnexpected results may occur...\n", i+1);
			
		errorFlag = 0;
		
	}
	
	//We don't need this anymore
	fclose(inputFile);
	
	//Print the output header
	printStudentHeader(stdout);
	
	//Sort the students
	sortStudents(students, numStudents);
	
	//Print the students
	printStudents(students, numStudents, stdout);
	
	return 0;
	
}

