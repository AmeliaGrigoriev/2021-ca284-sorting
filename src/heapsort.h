#include <stdio.h>
#include <stdlib.h>

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

int * heapsort_asc(int numbers[], int amount)
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

int * heapsort_desc(int numbers[], int amount)
{

    heapsort_asc(numbers, amount);
    
    int low, high, tmp;

    for(low = 0, high = amount - 1; low < high; low++, high--){
        tmp = numbers[low];
        numbers[low] = numbers[high];
        numbers[high] = tmp;
    }
    return numbers;
}