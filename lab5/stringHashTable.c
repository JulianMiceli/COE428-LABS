#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;

struct Entry 
{
	char * string;
 	int count;
};
Entry hash_table[HASH_TABLE_SIZE];

void add(char * tag)
{
	int i, key;
	int Sum = 0;
	int Length;

		Length = strlen(tag);
		for(i = 0; i < Length; i++)
		{
			Sum = Sum + *(tag+1);
		}
		
		key = Sum % HASH_TABLE_SIZE;

		while(true)
		{
			if(hash_table[key].count == 0)
			{
				hash_table[key].string = tag;
				hash_table[key].count = 1;
			}
			else if(hash_table[key].count != 0)
			{
				if(hash_table[key].string == tag)
				{
					hash_table[key].count++;
				}
				else
				{
					key++;
					key = key % HASH_TABLE_SIZE;
				}
			}
		}
}
