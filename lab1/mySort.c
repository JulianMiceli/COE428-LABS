void mySort(int d[], unsigned int n)
{
   int i;
   int temp;
   int j;
  
   for(i = 1; i < n; i++)
   {
      temp = d[i];
      j = i-1;
        while(j >= 0 && d[j] > temp)
        {
            d[j+1] = d[j];
            j--;
        }
       d[j+1] = temp;
    }
}
