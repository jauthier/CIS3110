#include "cycle.h" 
#include "stdio.h"
#include "stdlib.h"
#define LONG 2814585000
int main (int argc, char *argv[]) {

   int i;
   ticks t1;
   ticks t2;
   double mytime1;
   double mytime2;
   char buffer[20000];
   FILE *fp;

   if (argc == 1){
      printf("Please enter the name of the file\n");
      exit(0);
   }
   char *fileName = argv[1];
   fp = fopen(fileName, "r");
      t1 = getticks();

      fread(buffer, 20000, 1, fp);

      t2 = getticks();
      mytime1 = elapsed(t2,t1);
      mytime2 = elapsed(t2,t1) / LONG;
      printf ("%f	%f\n",mytime1,mytime2);
}

