#include <stdio.h>
#define  MAX_VALUES    3
#define  OUTPUT_LINES   5

int main(int argc, char **argv)
{
    int values[MAX_VALUES];
    int i, j;
    FILE *inputFile;
    if ( (inputFile = fopen(argv[1], "r") ) == NULL) {
         printf("Error opening input file.\n\n"); 
         exit(1);
    }
    for(i = 0; i < MAX_VALUES; i++)
        fscanf(inputFile, "%d", &values[i]);
    for(i = 0; i < OUTPUT_LINES; i++){
       for (j=0; j < MAX_VALUES; j++)
          printf("%d ", values[j]*(i+1) + (j < 2 ? j: 3));
       printf("\n");
    } 
    return 0;
}
