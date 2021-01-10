#include <stdio.h>
#include <stdlib.h>

int * selecsort(int numbers[], int amount)
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

int * radixsort(int numbers[], int amount)
{
    int pos;
    int max = maxnum(numbers, amount);

    for(pos = 1; max / pos > 0; pos *= 10){
        countingsort(numbers, amount, pos);
    }

    return numbers;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int numbers[], int amount, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < amount && numbers[left] > numbers[largest]){
        largest = left;
    }

    if(right < amount && numbers[right] > numbers[largest]){
        largest = right;
    }

    if(largest != i){
        swap(&numbers[i], &numbers[largest]);
        heapify(numbers, amount, largest);
    }
}

int * heapsort(int numbers[], int amount)
{
    int i;

    for(i = amount / 2 - 1; i >= 0; i--){
        heapify(numbers, amount, i);
    }

    for(i = amount - 1; i >= 0; i--){
        swap(&numbers[0], &numbers[i]);
        heapify(numbers, i, 0);
    }

    return numbers;
}
