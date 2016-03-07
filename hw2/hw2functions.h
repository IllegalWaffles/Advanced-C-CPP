typedef struct Student{
	
	int term, id, catalogNumber;
	char firstName[16], lastName[16], section[4], subject[4];
	
}Student;

int getNumStudents(FILE*);
void printStudents(Student[], int);
void printStudentHeader();
int compare(const void *, const void *);
void sortStudents(Student[], int);
