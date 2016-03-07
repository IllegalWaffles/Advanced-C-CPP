#include <stdio.h>
#include <string.h>
#include "hw2functions.h"

int main(){
	
	char inputFileName[100], c;
	FILE* inputFile;
	int i, numStudents = 1;
	
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
	
	numStudents = getNumStudents(inputFile);
	
	Student students[numStudents];
	
	//Code to scan info in
	for(i = 0; i < numStudents; i++)
	{
		
		//1301,107515018,"Boatswain","Michael R.",CSE, 230,="R01"
		//fscanf(inputFile, "%d,%d,\"%[^,\"]\",\"%[^\"]\",%[^,],%d,=\"%[^\"]%*[^\n]", &(students[i].term), &(students[i].id), students[i].lastName, students[i].firstName, students[i].subject, &(students[i].catalogNumber), students[i].section);
		
		fscanf(inputFile, "%d,", &(students[i].term));
		fscanf(inputFile, "%d,", &(students[i].id));
		fscanf(inputFile, "\"%[^,\"]\",", students[i].lastName);
		fscanf(inputFile, "\"%[^,\"]\",", students[i].firstName);
		fscanf(inputFile, "%[^,],", students[i].subject);
		fscanf(inputFile, "%d", &(students[i].catalogNumber));
		fscanf(inputFile, "%*[^=]=");
		fscanf(inputFile, "\"%[^\"]", students[i].section);
		fscanf(inputFile, "%*[^\n]");
		
	}
	
	fclose(inputFile);//We don't need this anymore
	
	printStudentHeader();
	sortStudents(students, numStudents);
	printStudents(students, numStudents);
	
	return 0;
	
}

