#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define SIZE 4
#define NUMBER_BASE 2

//Outputs a random location in the range of the game board. 
short randomLocation()
{
	return rand() % SIZE;
}

void printGameBoard(short gameBoard[SIZE][SIZE], int score)
{
	int width, height; 
	for (height = 0; height < SIZE; height++)
	{ 
		for (width = 0; width < SIZE; width++)
		{ 
			if (gameBoard[height][width] != 0)
			{
				printf("[%4i]", gameBoard[height][width]);
			}
			else
			{
				printf("[    ]");
			}
		}
		printf("\n");
	}
	printf("Score: %i\n\n",score);
}

int main()
{
	short width = 0, height = 0, i = 0;
	short gameBoard [SIZE][SIZE] = {{0}};
	char exit = 0, direction = 'U', checkMatch = 1, validInput = 0,  changesMade = 0;
	char buffer[8];
	int score = 0;
	srand(time(0));
	
	width = randomLocation();
	height = randomLocation();
	while (gameBoard[height][width] != 0)
	{
		width = randomLocation();
		height = randomLocation();
	}
	gameBoard[height][width] = NUMBER_BASE;
	
	
	printGameBoard(gameBoard, score);
	

	do
	{
		for (width = 0; width < SIZE; width++)
		{ 
			for (height = 0; height < SIZE; height++)
			{
				if (gameBoard[height][width] == pow(SIZE,11) )
				{
					printf("You won!!");
				}
			}
		}
		
		printf("go (U)p, (D)own, (L)eft, or (R)ight: ");
		
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, " %c", &direction);
		
		switch(direction)
		{
			case 'u':
			case 'U':
				changesMade = 0;
				validInput = 1;
				for (width = 0; width < SIZE; width++)
				{ 
					for (height = 0; height < SIZE; height++)
					{
						i = height + 1;
						checkMatch = 1;
						while (checkMatch)
						{
							if(gameBoard[height][width] == 0 && i < SIZE)
							{
								if (gameBoard[i][width] != 0)
								{
									gameBoard[height][width] += gameBoard[i][width];
									gameBoard[i][width] = 0;
									changesMade = 1;
								}
								else
								{
									i++;
								}
							}
							else if(gameBoard[height][width] != 0 && i < SIZE)
							{
								if (gameBoard[height][width] == gameBoard[i][width])
								{
									gameBoard[height][width] += gameBoard[i][width];
									gameBoard[i][width] = 0;
									score += gameBoard[height][width];
									checkMatch = 0;
									changesMade = 1;
								}
								else if (gameBoard[i][width] != 0 && gameBoard[height][width] != gameBoard[i][width])
								{
									checkMatch = 0;
								}
								else
								{
									i++;
								}
							}
							else
							{
								checkMatch = 0;
							}
						}
					}
				}
				break;
			case 'd':
			case 'D':
				changesMade = 0;
				validInput = 1;
				for (width = 0; width < SIZE; width++)
				{ 
					for (height = SIZE-1; height > 0; height--)
					{
						i = height - 1;
						checkMatch = 1;
						while (checkMatch)
						{
							if(gameBoard[height][width] == 0 && i >= 0)
							{
								if (gameBoard[i][width] != 0)
								{
									gameBoard[height][width] += gameBoard[i][width];
									gameBoard[i][width] = 0;
									changesMade = 1;
								}
								else
								{
									i--;
								}
							}
							else if(gameBoard[height][width] != 0 && i >= 0)
							{
								if (gameBoard[height][width] == gameBoard[i][width])
								{
									gameBoard[height][width] += gameBoard[i][width];
									gameBoard[i][width] = 0;
									score += gameBoard[height][width];
									checkMatch = 0;
									changesMade = 1;
								}
								else if (gameBoard[i][width] != 0 && gameBoard[height][width] != gameBoard[i][width])
								{
									checkMatch = 0;
								}
								else
								{
									i--;
								}
							}
							else
							{
								checkMatch = 0;
							}
						}
					}
				}
				break;
			case 'l':
			case 'L':
				changesMade = 0;
				validInput = 1;
				for (width = 0; width < SIZE; width++)
				{ 
					for (height = 0; height < SIZE; height++)
					{
						i = width + 1;
						checkMatch = 1;
						while (checkMatch)
						{
							if(gameBoard[height][width] == 0 && i < SIZE)
							{
								if (gameBoard[height][i] != 0)
								{
									gameBoard[height][width] += gameBoard[height][i];
									gameBoard[height][i] = 0;
									changesMade = 1;
								}
								else
								{
									i++;
								}
							}
							else if(gameBoard[height][width] != 0 && i < SIZE)
							{
								if (gameBoard[height][width] == gameBoard[height][i])
								{
									gameBoard[height][width] += gameBoard[height][i];
									gameBoard[height][i] = 0;
									score += gameBoard[height][width];
									checkMatch = 0;
									changesMade = 1;
								}
								else if (gameBoard[height][i] != 0 && gameBoard[height][width] != gameBoard[height][i])
								{
									checkMatch = 0;
								}
								else
								{
									i++;
								}
							}
							else
							{
								checkMatch = 0;
							}
						}
					}
				}
				break;
			case 'r':
			case 'R':
				changesMade = 0;
				validInput = 1;
				for (height = 0; height < SIZE; height++)
				{ 
					for (width = SIZE-1; width > 0; width--)
					{
						i = width - 1;
						checkMatch = 1;
						while (checkMatch)
						{
							if(gameBoard[height][width] == 0 && i >= 0)
							{
								if (gameBoard[height][i] != 0)
								{
									gameBoard[height][width] += gameBoard[height][i];
									gameBoard[height][i] = 0;
									changesMade = 1;
								}
								else
								{
									i--;
								}
							}
							else if(gameBoard[height][width] != 0 && i >= 0)
							{
								if (gameBoard[height][width] == gameBoard[height][i])
								{
									gameBoard[height][width] += gameBoard[height][i];
									gameBoard[height][i] = 0;
									score += gameBoard[height][width];
									checkMatch = 0;
									changesMade = 1;
								}
								else if (gameBoard[height][i] != 0 && gameBoard[height][width] != gameBoard[height][i])
								{
									checkMatch = 0;
								}
								else
								{
									i--;
								}
							}
							else
							{
								checkMatch = 0;
							}
						}
					}
				}
				break;
			default:
				break;
		}
		
		if (validInput && !changesMade)
		{
			exit = 1;
			for (width = 0; width < SIZE; width++)
			{ 
				for (height = 0; height < SIZE; height++)
				{
					if (gameBoard[height][width] == 0)
					{
						exit = 0;
					}
				}
			}
		
		}
		
		if (changesMade)
		{
			width = randomLocation();
			height = randomLocation();
			while (gameBoard[height][width] != 0)
			{
				width = randomLocation();
				height = randomLocation();
			}
			gameBoard[height][width] = NUMBER_BASE;
		}
		
		printGameBoard(gameBoard, score);
		
		
	} while(!exit);
	
	printf("Game Over!\n");
	
	return 0;
}
