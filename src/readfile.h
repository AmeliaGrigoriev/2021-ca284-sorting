/* header file which reads numbers from a file, adds them to an array and returns the array */
/* includes */
#include <stdio.h>
#include <stdlib.h>

/* function to read numbers from a file, add them to an array and return the array */
int * readfile(char filename[], int amount)
{
    int num;
    int *numbers = (int *)malloc(sizeof(int) * amount); /* using malloc for memory allocation */

    FILE * file = fopen(filename, "r"); /* opening file to read from it */

    for(int i = 0; i < amount; i++){
        fscanf(file, "%d", &num);
        numbers[i] = num;
    }

    fclose(file); /* closing the file */
 
    return numbers; /* returning an array of integers */
}
