#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{
  int data[100000];
  int nDataTerms;
  int i;

  /*If statement to check if data was inputed on the command line*/
  /*If their is, it stores it overwrites data and stores it, if their
    is no data, it uses the test data below*/
  if(argc > 1)
  {
       nDataTerms = argc;
       for(i = 1; i < argc; i++)
       {
          data[i] = atoi(argv[i]);
       }

          mySort(data, argc);

       for(i = 1; i < nDataTerms; i++)
       {
          printf("%d\n", data[i]);
       }
  }
  else 
  {
     /*Test Data Terms */
     nDataTerms = 4;
     data[0] = 10;
     data[1] = 20;
     data[2] = 30;
     data[3] = 40;
     mySort(data, nDataTerms);
     
     for(i = 0; i < nDataTerms; i++)
     {
         printf("%d\n", data[i]);
     }
   }
}
