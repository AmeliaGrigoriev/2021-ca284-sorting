/* header file with options to sort the data before passing it to the sorting algorithms */
/* includes */
#include <stdio.h>
#include <stdlib.h>

/* code used in this file was gotten from the project brief */

/* function to reverse the data */
int reverse(const void *a, const void *b)
{
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da < *db) - (*da > *db);
}

/* function to partially sort the data */
int partial(const void *a, const void *b){
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da > *db) - (*da < *db); 
}

/* function to sort the data */
int numerical(const void *a, const void *b){
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da > *db) - (*da < *db); 
}