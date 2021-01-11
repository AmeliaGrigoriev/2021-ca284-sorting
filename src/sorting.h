/* header file with three sorting algorithms */ 
/* includes */
#include <stdio.h>
#include <stdlib.h>

/* this file contains my three sorting algorithms. selection sort, radix dort and heap sort */

/* first sorting algorithm - selection sort, takes an array and the amount of integers in the array as parameters */
/* used https://www.programmingsimplified.com/c/source-code/c-program-selection-sort for help with selection sort */
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

    return numbers; /* return sorted array */
}

/* used https://www.programiz.com/dsa/radix-sort for help with radix sort */
/* functions that will be used for radix sort - maxnum and countingsort */
/* maxnum function finds the max number in an array, takes an array and the amount of integers in the array as parameters */
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

/* Using counting sort to sort the elements in the basis of significant places */
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

/* second sorting algorithm - radix sort */
int * radix(int numbers[], int amount)
{
    int pos;
    int max = maxnum(numbers, amount);

    for(pos = 1; max / pos > 0; pos *= 10){
        countingsort(numbers, amount, pos);
    }

    return numbers; /* return sorted array */
}

/* used https://www.programiz.com/dsa/heap-sort for help with heap sort */
/* functions used for heap sort - heapify and swap */
/* swap functon swaps two characters */
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* heapify function finds largest among root, left child and right child */
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

/* third sorting algorithm - heap sort */
int * heap(int numbers[], int amount)
{
    int i;

    for(i = amount / 2 - 1; i >= 0; i--){
        heapify(numbers, amount, i);
    }

    for(i = amount - 1; i >= 0; i--){
        swap(&numbers[0], &numbers[i]);
        heapify(numbers, i, 0);
    }

    return numbers; /* return sorted array */
}
