#include <stdio.h>
#include <string.h>
#include "hw2functions.h"

/*
 *	Kuba Gasiorowski, kgasiorowski, 109776237
 *
 *
 */

//Returns the number of students contained in a file
int getNumStudents(FILE *inFile){
	
	int numStudents = 0;
	char c;
	
	while((c = getc(inFile)) != EOF)
		if(c == '=')
			numStudents++;
			
	rewind(inFile);
	
	return numStudents;
	
}

//Sorts the array of students
void sortStudents(Student students[], int numStudents){
	
	qsort(students, numStudents, sizeof(Student), compare);
	
}

//Prints each student in the array
void printStudents(Student students[], int numStudents)
{
	
	int i;
	char fullName[40];
	
	for(i = 0; i < numStudents; i++){
	
		fullName[0] = '\0';
	
		strcpy(fullName, students[i].lastName);
		strcat(fullName, ", ");
		strcat(fullName, students[i].firstName);
		printf("%-32s %4d  %9d   %3s%3d     %3s\n", fullName, students[i].term, students[i].id, students[i].subject, students[i].catalogNumber, students[i].section);
	
	}
	
}

//Prints the header for output
void printStudentHeader(){
	
	printf("\nLast Name, First Name            Term      ID      Course   Section");
	printf("\n-------------------------------- ----  ---------   ------   -------\n");
	
}

//Compares two student objects by last name
int compare(const void *a, const void *b){
	
	Student A = *(Student*)a, B = *(Student*)b;
	
	return strcmp(A.lastName, B.lastName);
	
}
