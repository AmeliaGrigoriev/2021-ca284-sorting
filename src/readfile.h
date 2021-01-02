#include <stdio.h>
#include <stdlib.h>

int * readfile(char filename[], int amount)
{
    int num;
    static int *numbers;

    FILE * file = fopen(filename, "r");

    for(int i = 0; i < amount; i++){
        fscanf(file, "%d", &num);
        numbers[i] = num;
    }

    fclose(file);

    return numbers;
}
