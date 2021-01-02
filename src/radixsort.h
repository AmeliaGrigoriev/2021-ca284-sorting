#include <stdio.h>
#include <stdlib.h>

int maxnum(int numbers[], int amount)
{
    int max, next, i;

    max = numbers[0];
    
    for(i = 1; i < amount; i++){
        if(numbers[i] > max){
            max = numbers[i];
        }
    }
    return max;
}

void countingsort(int numbers[], int amount, int pos)
{
    int * output = (int *)malloc(sizeof(int) * (amount+1));
    int max = (numbers[0] / pos) % 10;
    int i;

    for(i = 1; i < amount; i++){

        if(((numbers[i] / pos) % 10) > max){
            max = numbers[i];
        }
    }

    int * count = (int *)malloc(sizeof(int) * (max+1));

    for(i = 0; i < max; ++i){
        count[i] = 0;
    }

    for(i = 0; i < amount; i++){
        count[(numbers[i] / pos) % 10]++;
    }

    for(i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for(i = amount - 1; i >= 0; i--){
        output[count[(numbers[i] / pos) % 10] - 1] = numbers[i];
        count[(numbers[i] / pos) % 10]--;
    }

    for(i = 0; i < amount; i++){
        numbers[i] = output[i];
    }
}

int * radixsort_asc(int numbers[], int amount)
{
    int pos;
    int max = maxnum(numbers, amount);

    for(pos = 1; max / pos > 0; pos *= 10){
        countingsort(numbers, amount, pos);
    }

    return numbers;
}

int * radixsort_desc(int numbers[], int amount)
{

    radixsort_asc(numbers, amount);
    
    int low, high, tmp;

    for(low = 0, high = amount - 1; low < high; low++, high--){
        tmp = numbers[low];
        numbers[low] = numbers[high];
        numbers[high] = tmp;
    }
    return numbers;
}