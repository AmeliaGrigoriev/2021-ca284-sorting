#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "selectionsort.h"
#include "radixsort.h"
#include "heapsort.h"

int main()
{
    int * numbers, * sorted, amount, method, order;

    printf("Please enter the amount of numbers you would like to sort: ");
    scanf("%d", &amount);

    printf("\n--------------------------------------------------------------------\n\n");

    numbers = readfile("../test/nums.txt", amount);

    printf("Please choose the sorting algorithm you would like to use.\n");
    printf("\n");
    printf("Enter '1' for Selection Sort\n");
    printf("Enter '2' for Radix Sort\n");
    printf("Enter '3' for Heap Sort\n");
    printf("\nWhich sorting alorithm would you like to use?\n");
    printf("Please enter '1', '2' or '3': ");
    scanf("%d", &method);

    printf("\n--------------------------------------------------------------------\n\n");

    if(method != 1 && method != 2 && method != 3){
        printf("The number you entered is not an option!\n");
        printf("\n--------------------------------------------------------------------\n\n");
        exit(0);
    }

    printf("Please choose which order you would like to sort your numbers in.\n");
    printf("\n");
    printf("Enter '1' for Ascending Order\n");
    printf("Enter '2' for Descending Order\n");
    printf("\nWhich sorting order would you like to use?\n");
    printf("Please enter '1' or '2': ");
    scanf("%d", &order);
    
    printf("\n--------------------------------------------------------------------\n\n");

    if(method == 1){

        if(order == 1){
            sorted = selecsort_asc(numbers, amount);
            printf("Here are your numbers sorted in ascending order using Selection Sort:\n\n");
        }

        else if(order == 2){
            sorted = selecsort_desc(numbers, amount);
            printf("Here are your numbers sorted in descending order using Selection Sort:\n\n");
        }

        else{
            printf("The number you entered is not an option!\n");
            printf("\n--------------------------------------------------------------------\n\n");
            exit(0);
        }
    }

    else if(method == 2){

        if(order == 1){
            sorted = radixsort_asc(numbers, amount);
            printf("Here are your numbers sorted in ascending order using Radix sort:\n\n");
        }

        else if(order == 2){
            sorted = radixsort_desc(numbers, amount);
            printf("Here are your numbsers sorted in descending order using Radix sort:\n\n");
        }

        else{
            printf("The number you entered is not an option!\n");
            printf("\n--------------------------------------------------------------------\n\n");
            exit(0);
        }
    }

    else if(method == 3){
        
        if(order == 1){
            sorted = heapsort_asc(numbers, amount);
            printf("Here are your numbers sorted in ascending order using Heap Sort:\n\n");
        }

        else if(order == 2){
            sorted = heapsort_desc(numbers, amount);
            printf("Here are your numbers sorted in descending order using Heap Sort:\n\n");
        }

        else{
            printf("The number you entered is not an option!\n");
            printf("\n--------------------------------------------------------------------\n\n");
            exit(0);
        }
    }

    for(int i = 0; i < amount; i++){
        printf("%d\n", sorted[i]);
    }

    printf("\n--------------------------------------------------------------------\n\n");

    return 0;
}
