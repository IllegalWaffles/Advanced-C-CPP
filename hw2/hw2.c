#include <stdio.h>
#include <string.h>
#include "hw2functions.h"

int main(){
	
	char inputFile[100];
	FILE* inFile;
	
	printf("Enter a file to read information from:");
	scanf("%s", inputFile);
	
	if((inFile = fopen(inputFile, "r")) == NULL){
	
		printf("Error: file not found");
		return 1;
	
	}
	
	
	
	return 0;
	
}
