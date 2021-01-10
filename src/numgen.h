#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numgen(int amount)
{
   FILE * file = fopen("../test/nums.txt", "w");

   srand(time(0));

   int count = 0;

   for(int i = 0; i < amount; i++){
      fprintf(file, "%d\n", rand() % 100000);
      count += 1;
   }

   fclose(file);

   return 0;
}
