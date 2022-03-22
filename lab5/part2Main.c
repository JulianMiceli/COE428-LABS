#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
	int ch, Next_Char, temp, i;
	int Counter_arr[26][2];

	for(i = 0; i < 25; i++)
	{
		Counter_arr[i][0] = 0;
		Counter_arr[i][1] = 0;
	}

  	while ((ch = getchar()) != EOF) 
	{
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
			continue;
    	else if(ch == '<')
		{
			ch = getchar();
			if(isalpha(ch))
			{
				Next_Char = getchar();
				if(Next_Char == '>')
				{
					for(i = 0; i < 25; i++)
					{
						if(Counter_arr[i][0] == ch)
						{
							Counter_arr[i][0] = ch;
							Counter_arr[i][1]++;
							break;
						}
						else if(Counter_arr[i][0] == 0)
						{
							Counter_arr[i][0] = ch;
							Counter_arr[i][1]++;
							break;
						}
					}
					push(ch);
				}
				else
				{
					fprintf(stderr, "Incomplete tag");
					exit(1);
				}
			}
			else if(ch == '/')
			{
				ch = getchar();
				if(isalpha(ch))
				{
					Next_Char = getchar();
					if((Next_Char == '>') && (Next_Char != EOF))
					{
						if(isEmpty() == 1)
						{
							fprintf(stderr, "Invalid");
							exit(0);
						}
						else if((temp = pop()) == ch)
						{
							continue;
						}
						else if((temp == pop()) != ch)
						{
							fprintf(stderr, "Invalid");
							exit(0);		
						}			
					}
					else
					{
							fprintf(stderr, "Incomplete exit tag");
							exit(1);
					}
				}
			}
			else
			{
				fprintf(stderr, "Incomplete exit tag");
				exit(1);
			}
		}
		else
		{
			fprintf(stderr, "Incorrect start of the tag");
			exit(0);
		}

	}
	if(isEmpty() == 1)
	{
		fprintf(stderr, "Valid\n");
			for(i = 0; i < 25; i++)
			{
				if(Counter_arr[i][1] != 0)
				{
					fprintf(stderr, "%c %d \n", Counter_arr[i][0], Counter_arr[i][1]);
				}
			}
		exit(0);
	}
	else
	{
		fprintf(stderr, "Invalid");
		exit(1);
	}
}
