#include <stdlib.h>
#include <stdio.h>

int ACSIIADDER(int value)
{
	return value + 65;
}

int main(int argc, char * argv[])
{
//Counter var
int i, j;

//Temp array to tag reachable states, Temp var to track current state
//Temp index var to store the index of the row for a given current state
int temp_arr[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int temp_0, temp_1;
int tempIndex;
int Count;
int Counter;

//Var to initialize rows of the FSM
int row = 8;

//Var to initialize columns of the FSM
int column = 3;

//Initializes the FSM dimensions
int FSM[row][column];

//Var to track index of Current State
int TrackIndex;

//Var to be used to force quit program
int Quit = 0;

	//Var to track user inputs
	char Command[3];

	//Var to track and initialize the current state of the FSM
	int Current_State = 2;
	TrackIndex = 2;

	//Initialize FSM
	int B_FSM[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int Z_FSM[8] = {6, 2, 5, 1, 0, 5, 3, 4};
	int O_FSM[8] = {3, 6, 1, 4, 2, 7, 5, 0};
	
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 1; j++)
		{
			FSM[i][j] = B_FSM[i];
			FSM[i][j+1] = Z_FSM[i];
			FSM[i][j+2] = O_FSM[i];
		}
	}
	
	//Prints the current state of the FSM
	fprintf(stdout, "Current State: %c \n", ACSIIADDER(Current_State));

	while(Quit != 1)
	{
		fprintf(stdout, "Enter commands as per in the lab document \n");
		//Get command inputs from the user
		fscanf(stdin, "%s", &Command[0]);

		switch (Command[0])
		{
			case 'c':
				fprintf(stdout, "Enter the FSM(0 or 1) you would like to change\n");
				fscanf(stdin, "%s", &Command[1]);

				fprintf(stdout, "Enter the new state\n");
				fscanf(stdin, "%s", &Command[2]);

				if(Command[1] == '0')
				{
					if(Command[2] == 'A')
						FSM[TrackIndex][1] = 0;
					else if(Command[2] == 'B')
						FSM[TrackIndex][1] = 1;
					else if(Command[2] == 'C')
						FSM[TrackIndex][1] = 2;
					else if(Command[2] == 'D')
						FSM[TrackIndex][1] = 3;
					else if(Command[2] == 'E')
						FSM[TrackIndex][1] = 4;
					else if(Command[2] == 'F')
						FSM[TrackIndex][1] = 5;
					else if(Command[2] == 'G')
						FSM[TrackIndex][1] = 6;
					else 
						FSM[TrackIndex][1] = 7;
				}
				else if(Command[1] == '1')
				{
					if(Command[2] == 'A')
						FSM[TrackIndex][2] = 0;
					else if(Command[2] == 'B')
						FSM[TrackIndex][2] = 1;
					else if(Command[2] == 'C')
						FSM[TrackIndex][2] = 2;
					else if(Command[2] == 'D')
						FSM[TrackIndex][2] = 3;
					else if(Command[2] == 'E')
						FSM[TrackIndex][2] = 4;
					else if(Command[2] == 'F')
						FSM[TrackIndex][2] = 5;
					else if(Command[2] == 'G')
						FSM[TrackIndex][2] = 6;
					else
						FSM[TrackIndex][2] = 7;
				}
				break;

			case 'g':
				tempIndex = TrackIndex;

				while(temp_0 != Current_State)
				{
					if(FSM[tempIndex][1] == 0)
					{
						tempIndex = 0;
						temp_arr[0] = 1;
						temp_0 = 0;
						Counter++;
					}
					else if(FSM[tempIndex][1] == 1)
					{
						tempIndex = 1;
						temp_arr[1] = 1;
						temp_0 = 1;
						Counter++;
					}
					else if(FSM[tempIndex][1] == 2)
					{
						tempIndex = 2;
						temp_arr[2] = 1;
						temp_0 = 2;
						Counter++;
					}
					else if(FSM[tempIndex][1] == 3)
					{
						tempIndex = 3;
						temp_arr[3] = 1;
						temp_0 = 3;
						Counter++;
					}
					else if(FSM[tempIndex][1] == 4)
					{
						tempIndex = 4;
						temp_arr[4] = 1;
						temp_0 = 4;
						Counter++;
					}
					else if(FSM[tempIndex][1] == 5)
					{
						tempIndex = 5;
						temp_arr[5] = 1;
						temp_0 = 5;
						Counter++;
					}
					else if(FSM[tempIndex][1] == 6)
					{
						tempIndex = 6;
						temp_arr[6] = 1;
						temp_0 = 6;
					}
					else if(FSM[tempIndex][1] == 7)
					{
						tempIndex = 7;
						temp_arr[7] = 1;
						temp_0 = 7;
						Counter++;	
					}

					if(Counter >= 8)
						temp_0 = Current_State;
				}

				temp_0 = 0;
				Counter = 0;
				tempIndex = TrackIndex;

				while(temp_1 != Current_State)
				{
					if(FSM[tempIndex][2] == 0)
					{
						tempIndex = 0;
						temp_arr[0] = 1;
						temp_1 = 0;
						Counter++;
					}
					else if(FSM[tempIndex][2] == 1)
					{
						tempIndex = 1;
						temp_arr[1] = 1;
						temp_1 = 1;
						Counter++;
					}
					else if(FSM[tempIndex][2] == 2)
					{
						tempIndex = 2;
						temp_arr[2] = 1;
						temp_1 = 2;
						Counter++;
					}
					else if(FSM[tempIndex][2] == 3)
					{
						tempIndex = 3;
						temp_arr[3] = 1;
						temp_1 = 3;
						Counter++;
					}
					else if(FSM[tempIndex][2] == 4)
					{
						tempIndex = 4;
						temp_arr[4] = 1;
						temp_1 = 4;
						Counter++;
					}
					else if(FSM[tempIndex][2] == 5)
					{
						tempIndex = 5;
						temp_arr[5] = 1;
						temp_1 = 5;
						Counter++;
					}
					else if(FSM[tempIndex][2] == 6)
					{
						tempIndex = 6;
						temp_arr[6] = 1;
						temp_1 = 6;
						Counter++;
					}
					else if(FSM[tempIndex][2] == 7)
					{
						tempIndex = 7;
						temp_arr[7] = 1;
						temp_1 = 7;
						Counter++;
					}

					if(Counter >= 8)
						temp_1 = Current_State;
				}

				Counter = 0;
				temp_1 = 0;

				for(i = 0; i < 8; i++)
				{
					if(temp_arr[i] == 0)
					{
						fprintf(stdout, "Garbage: %c \n", ACSIIADDER(FSM[i][0]));
					}
					else
					{
						fprintf(stdout, "No Garbage \n");
					}
				}

				break;

			case 'd':
				for(i = 0; i < 8; i++)
				{
					for(j = 0; j < 1; j++)
					{
						if(temp_arr[i] == 0)
						{
							FSM[i][j] = 0;
							FSM[i][j+1] = 0;
							FSM[i][j+2] = 0;
							fprintf(stdout, "Deleted: %c\n", ACSIIADDER(i));
						}
					}
				}

				for(i = 0; i < 8; i++)
				{
					for(j = 0; j < 1; j++)
					{
						if(temp_arr[i] == 1)
						{
							FSM[Count][j] = FSM[i][j];
							FSM[Count][j+1] = FSM[i][j+1];
							FSM[Count][j+2] = FSM[i][j+2];
							Count++;
						}
					}
				} 
				break;

			case 'p':
				for(i = 0; i < row; i++)
				{
					for(j = 0; j < 1; j++)
					{
					fprintf(stdout, "%c %c %c \n", ACSIIADDER(FSM[i][j]), ACSIIADDER(FSM[i][j+1]), ACSIIADDER(FSM[i][j+2]));
					}
				}
				break;

			case '0':
				Current_State = FSM[TrackIndex][1];

				if(Current_State == 0)
					TrackIndex = 0;
				else if(Current_State == 1)
					TrackIndex = 1;
				else if(Current_State == 2)
					TrackIndex = 2;
				else if(Current_State == 3)
					TrackIndex = 3;
				else if(Current_State == 4)
					TrackIndex = 4;
				else if(Current_State == 5)
					TrackIndex = 5;
				else if(Current_State == 6)
					TrackIndex = 6;
				else
					TrackIndex = 7;
				
				fprintf(stdout, "%c \n", ACSIIADDER(Current_State));
				break;
		
			case '1':
				Current_State = FSM[TrackIndex][2];

				if(Current_State == 0)
					TrackIndex = 0;
				else if(Current_State == 1)
					TrackIndex = 1;
				else if(Current_State == 2)
					TrackIndex = 2;
				else if(Current_State == 3)
					TrackIndex = 3;
				else if(Current_State == 4)
					TrackIndex = 4;
				else if(Current_State == 5)
					TrackIndex = 5;
				else if(Current_State == 6)
					TrackIndex = 6;
				else
					TrackIndex = 7;
				
				fprintf(stdout, "%c \n", ACSIIADDER(Current_State));
				break;

			case 'q':
				Quit = 1;
				break;

			default:
				fprintf(stdout, "Please enter a valid input");
				break;
		}
	}
    exit(0);
}

