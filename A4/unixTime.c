#include "stdio.h"
#include "stdlib.h"
#include <sys/time.h>
int main (int argc, char *argv[]) {

   int i;
   int t1;
   int t2;
   double newstart, newend;
   double mytime;
   struct timeval start, end;
   char buffer[20000];
   FILE *fp;
   float sum = 0;

   if (argc == 1){
      printf("Please enter the name of the file\n");
      exit(0);
   }
   for ( i=0; i<10; i++ ) {
      char *fileName = argv[1];
      fp = fopen(fileName, "r");
      gettimeofday(&start, NULL);
      
      fread(buffer, 20000, 1, fp);
      
      gettimeofday(&end, NULL);
      newstart = start.tv_sec + (double)start.tv_usec / 1000000.0;
      newend = end.tv_sec + (double)end.tv_usec / 1000000.0;
      mytime = newend - newstart;
      sum = sum + mytime;
      printf("%f\n", mytime);
   }
   
   float av = sum / 10;
   printf("the average is: %f\n",av);

}

