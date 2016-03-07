/*
 *	Kuba Gasiorowski, kgasiorowski, 109776237, kuba.gasiorowski@stonybrook.edu
 *
 *	Includes definition of the Student struct as well as headers for all functions.
 */

typedef struct Student{
	
	int term, id, catalogNumber;
	char firstName[16], lastName[16], section[4], subject[4];
	
}Student;

//See each implementation for detailed comments.
int getNumStudents(FILE*);
void printStudents(Student[], int);
void printStudentHeader();
int compare(const void *, const void *);
void sortStudents(Student[], int);
