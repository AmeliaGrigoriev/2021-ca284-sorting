/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "readfile.h"
#include "sorting.h"
#include "numgen.h"
#include "data.h"

/* defines */
#define SEPARATOR "\n********************************************************************\n\n"
#define INVALID_INPUT "That is not an option! Please try again and enter a different number!\n"
#define SELEC "Selection Sort"
#define RADIX "Radix Sort"
#define HEAP "Heap Sort"
#define SORTED "Your numbers were sorted using"

/* main function */
int main()
{
    int * numbers, * sorted, amount, method, data;
    double time = 0.0; /* time variable to know how long each algorithm takes */

    printf("%s", SEPARATOR);

    /* asks the user how many integers they want to sort */
    printf("Please enter the amount of numbers you would like to sort: ");
    scanf("%d", &amount);

    printf("%s", SEPARATOR);

    numgen(amount); /**/

    numbers = readfile("../test/nums.txt", amount);

    /* asks what order the user wants their generated numbers in */
    printf("Please choose a way to manipulate your dataset:\n\n");
    printf("1) Data sorted in descending order\n");
    printf("2) Partially sorted data\n");
    printf("3) Numerically sorted data\n");
    printf("4) Data in random order\n\n");
    printf("Please choose either '1', '2', '3' or '4': ");
    scanf("%d", &data);

    printf("%s", SEPARATOR);

    if(data != 1 && data != 2 && data != 3 && data != 4){
        printf("%s", INVALID_INPUT);
        printf("%s", SEPARATOR);
        exit(0);
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
    
    /* asks the user which sorting algorithm they would like the numbers to be sorted with */
    printf("Please choose a sorting algorithm:\n\n");
    printf("1) %s\n", SELEC);
    printf("2) %s\n", RADIX);
    printf("3) %s\n\n", HEAP);
    printf("Please choose either '1', '2' or '3': ");
    scanf("%d", &method);

    printf("%s", SEPARATOR);

    if(method != 1 && method != 2 && method != 3){
        printf("%s", INVALID_INPUT);
        printf("%s", SEPARATOR);
        exit(0);
    }

    if(method == 1){
        clock_t begin = clock(); /* starts the clock to check how long selection sort takes */
        sorted = selecsort(numbers, amount);
        clock_t end = clock(); /* stops the clock */
        time += (double)(end - begin) / CLOCKS_PER_SEC; /* calculates the time */
        printf("%s %s.\n", SORTED, SELEC);
        printf("It took %f seconds to sort your data.\n", time);
    }

    else if(method == 2){
        clock_t begin = clock(); /* starts the clock to check how long radix sort takes */
        sorted = radix(numbers, amount);
        clock_t end = clock(); /* stops the clock */
        time += (double)(end - begin) / CLOCKS_PER_SEC; /* calculates the time */
        printf("%s %s.\n", SORTED, RADIX);
        printf("It took %f seconds to sort your data.\n", time);
    }

    else if(method == 3){
        clock_t begin = clock(); /* starts the clock to check how long heap sort takes */
        sorted = heap(numbers, amount);
        clock_t end = clock(); /* stops the clock */
        time += (double)(end - begin) / CLOCKS_PER_SEC; /* calculates the time */
        printf("%s %s.\n", SORTED, HEAP);
        printf("It took %f seconds to sort your data.\n", time);
    }

    FILE * file = fopen("../test/nums.txt", "w"); /* opens the file to write to it */

    for(int i = 0; i < amount; i++){
        fprintf(file, "%d\n", sorted[i]); /* prints the sorted numbers to file */
    }

    fclose(file); /* close file */

    printf("%s", SEPARATOR);

    return 0;
}
