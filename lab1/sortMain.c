#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{
  int data[100000];
  int nDataTerms;
  int i;
  /*Test Data Terms */
  nDataTerms = 4;
  data[0] = 10;
  data[1] = 20;
  data[2] = 30;
  data[3] = 40;

  mySort(data, nDataTerms);

  /*Check that the data array is sorted*/
  for(i = 0; i < nDataTerms -1; i++)
  {
    if(data[i] > data[i + 1])
    {
      fprintf(stderr, "Sort error: data[%d] (= %d)"
                      "should be <= data[%d] (= %d)- - aborting\n",
                      i, data[i], i+1, data[i+1]);
      exit(1);
    }
  }

  /*Print the assorted array to stdout*/
  for(i = 0; i < nDataTerms; i++)
  {
    printf("%d\n", data[i]);
  }

  exit(0);
}
