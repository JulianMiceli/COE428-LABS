#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);
extern void add(char * tag);


int ACSIIADDER(int input)
{
	return input + 65;
}

int main(int argc, char * argv[])
{
	int ch, Next_Char;
	char *str;
	char *pstr;

  	while ((ch = getchar()) != EOF) 
	{
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
			continue;
    	else if(ch == '<')
		{
			
			if(isalpha(str))
			{
				Next_Char = getchar();
				if((Next_Char == '>') && (Next_Char != EOF))
				{
					push(str);
					add(str);
				}
				else
				{
					fprintf(stderr, "Incomplete tag");
					exit(1);
				}
			}
			else if(ch == '/')
			{
				
				if(isalpha(str))
				{
					Next_Char = getchar();
					if((Next_Char == '>') && (Next_Char != EOF))
					{
						if(isEmpty() == 1)
						{
							fprintf(stderr, "Invalid");
							exit(0);
						}
						else if(strcmp((pstr = pop()), str) == 0)
						{
							continue;
						}
						else
						{
							fprintf(stderr, "Invalid");
							exit(1);		
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
