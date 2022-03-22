#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
   int i;
   int temp;
   int j;
  
   for(i = 1; i < last + 1; i++)
   {
      myCopy(&array[i], &temp);
      j = (i - 1);

        while(j >= 0 && myCompare(array[j], temp) >= 0)
        {
            mySwap(&array[j], &array[j + 1]);
            j--;
        }
		myCopy(&array[j + 1], &temp);
    }
}
