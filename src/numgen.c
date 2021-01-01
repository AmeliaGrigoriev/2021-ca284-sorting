#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numgen(int);

int main(int argc, char *argv[])
{
   int amount = atoi(argv[1]);
   numgen(amount);

   return 0;
}

int numgen(int amount)
{
   srand(time(0));

   int count = 0;

   for(int i = 0; i < amount; i++){
      printf("%d\n", rand());
      count += 1;
   }

   return 0;
}
