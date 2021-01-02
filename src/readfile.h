#include <stdio.h>
#include <stdlib.h>

int * readfile(char filename[], int amount)
{
    int num;
    int *numbers = (int *)malloc(sizeof(int) * amount);

    FILE * file = fopen(filename, "r");

    for(int i = 0; i < amount; i++){
        fscanf(file, "%d", &num);
        numbers[i] = num;
    }

    fclose(file);

    return numbers;
}
