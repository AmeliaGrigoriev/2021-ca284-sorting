#include <stdio.h>
#include <stdlib.h>

int * selecsort_asc(int numbers[], int amount)
{
    int i, pos, next, tmp;

    for(i = 0; i < amount; i++){
        pos = i;

        for(next = i + 1; next < amount; next++){
            if(numbers[pos] > numbers[next]){
                pos = next;
            }
        }

        if(pos != i){
            tmp = numbers[i];
            numbers[i] = numbers[pos];
            numbers[pos] = tmp;
        }
    }

    return numbers;
}

int * selecsort_desc(int numbers[], int amount)
{
    int i, pos, next, tmp;

    for(i = 0; i < amount; i++){
        pos = i;

        for(next = i + 1; next < amount; next++){
            if(numbers[pos]< numbers[next]){
                pos = next;
            }
        }

        if(pos != i){
            tmp = numbers[i];
            numbers[i] = numbers[pos];
            numbers[pos] = tmp;
        }
    }

    return numbers;
}