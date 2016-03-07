#include <stdio.h>
#include <string.h>
#include "hw2functions.h"

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

int main(){
	
	char inputFileName[100], c;
	FILE* inputFile;
	int i, numStudents = 1, errorFlag = 0;
	
	//Try to open a file.
	//If it doesn't work, keep trying or q to quit.
	do{
	
		printf("Enter a file to read information from:");
		scanf("%s", inputFileName);
	
		if(strcmp(inputFileName, "q") == 0){
		
			printf("Terminating program...");
			return 0;
		
		}
		else if((inputFile = fopen(inputFileName, "r")) == NULL)
			printf("Error: file not found\n");
	
	}while(inputFile == NULL);
	
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
	printStudentHeader();
	
	//Sort the students
	sortStudents(students, numStudents);
	
	//Print the students
	printStudents(students, numStudents);
	
	return 0;
	
}

