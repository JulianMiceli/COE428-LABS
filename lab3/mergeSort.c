#include "mySort.h"
#include "metrics.h"
#include <stdio.h>

void myMerge(int array[], int a, int b, int c, int d)
{
	int temp[MAX_SIZE_N_TO_SORT];
	int i;
	int j;
	int k;
	i = a;
	j = c;
	k = 0;
		
		while((myCompare(i, b) <= 0) && (myCompare(j, d) <= 0))
		{
			if(myCompare(array[i], array[j]) < 0)
				myCopy(&array[i++], &temp[k++]);
			else
				myCopy(&array[j++], &temp[k++]);
		}

		while(myCompare(i, b) <= 0)
		{
			myCopy(&array[i++], &temp[k++]);
		}

		while(myCompare(j, d) <= 0)
		{
			myCopy(&array[j++], &temp[k++]);
		}

		for(i=a, k=0; i <= d; i++, k++)
		{
			mySwap(&array[i], &temp[k]);
		}	
}
	
void mySort(int array[], unsigned int first, unsigned int last)
{
	int middle;
		
		if(first < last)
		{
			middle = (first + last) / 2;
			mySort(array, first, middle);
			mySort(array, (middle + 1), last);
			myMerge(array, first, middle, (middle +1), last);
		}
}
