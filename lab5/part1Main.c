#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
	int ch, Next_Char, temp;
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
				if((Next_Char == '>') && (Next_Char != EOF))
				{
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
		fprintf(stderr, "Valid");
		exit(0);
	}
	else
	{
		fprintf(stderr, "Invalid");
		exit(1);
	}
}
