/* numgen header file */
/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* random number generator function */
int numgen(int amount)
{
   FILE * file = fopen("../test/nums.txt", "w"); /* opens the file to put the numbers in */

   srand(time(0));

   for(int i = 0; i < amount; i++){
      fprintf(file, "%d\n", rand() % 1000000); /* numbers generated will be 1000000 or less */
   }

   fclose(file); /* closes the file */

   return 0;
}
