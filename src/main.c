#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "readfile.h"
#include "sorting.h"
#include "numgen.h"
#include "data.h"

#define SEPARATOR "\n--------------------------------------------------------------------\n\n"
#define INVALID_INPUT "The number you entered is not an option!\n"
#define SELEC "Selection Sort"
#define RADIX "Radix Sort"
#define HEAP "Heap Sort"
#define SORTED "Your numbers were sorted using"

int main()
{
    int * numbers, * sorted, amount, method, data;
    double time = 0.0;

    printf("%s", SEPARATOR);

    printf("Please enter the amount of numbers you would like to sort: ");
    scanf("%d", &amount);

    printf("%s", SEPARATOR);

    numgen(amount);

    numbers = readfile("../test/nums.txt", amount);

    printf("How would you like to generate your data?\n\n");
    printf("Enter '1' to generate data in reverse order\n");
    printf("Enter '2' to generate partially sorted data\n");
    printf("Enter '3' to generate numerically sorted data\n");
    printf("Enter '4' to generate data in random order\n\n");
    printf("Please enter '1', '2', '3' or '4': ");
    scanf("%d", &data);

    printf("%s", SEPARATOR);

    if(data != 1 && data != 2 && data != 3 && data != 4){
        printf("%s", INVALID_INPUT);
        printf("%s", SEPARATOR);
    }

    if(data == 1){
        qsort(numbers, amount, sizeof(int), reverse);
    }

    else if(data == 2){
        int half = amount / 2;

        qsort(numbers, half, sizeof(int), partial);
    }
    
    else if(data == 3){
        qsort(numbers, amount, sizeof(int), numerical);
    }

    else if(data == 4){
        numbers = numbers;
    }
    
    printf("Please choose the sorting algorithm you would like to use.\n\n");
    printf("Enter '1' for %s\n", SELEC);
    printf("Enter '2' for %s\n", RADIX);
    printf("Enter '3' for %s\n", HEAP);
    printf("\nWhich sorting alorithm would you like to use?\n");
    printf("Please enter '1', '2' or '3': ");
    scanf("%d", &method);

    printf("%s", SEPARATOR);

    if(method != 1 && method != 2 && method != 3){
        printf("%s", INVALID_INPUT);
        printf("%s", SEPARATOR);
        exit(0);
    }

    if(method == 1){
        clock_t begin = clock();
        sorted = selecsort(numbers, amount);
        clock_t end = clock();
        time += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%s %s.\n", SORTED, SELEC);
        printf("It took %f seconds\n", time);
    }

    else if(method == 2){
        clock_t begin = clock();
        sorted = radix(numbers, amount);
        clock_t end = clock();
        time += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%s %s.\n", SORTED, RADIX);
        printf("It took %f seconds\n", time);
    }

    else if(method == 3){
        clock_t begin = clock();
        sorted = heap(numbers, amount);
        clock_t end = clock();
        time += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%s %s.\n", SORTED, HEAP);
        printf("It took %f seconds\n", time);
    }

    FILE * file = fopen("../test/nums.txt", "w");

    for(int i = 0; i < amount; i++){
        fprintf(file, "%d\n", sorted[i]);
    }

    fclose(file);

    printf("%s", SEPARATOR);

    return 0;
}
