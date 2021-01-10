#include <stdio.h>
#include <stdlib.h>

int reverse(const void *a, const void *b)
{
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da < *db) - (*da > *db);
}

int partial(const void *a, const void *b){
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da > *db) - (*da < *db); 
}

int numerical(const void *a, const void *b){
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da > *db) - (*da < *db); 
}