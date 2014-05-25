/* Copyright (c) 2014, Kate Barr
 * Redistribution and use in source and binary forms, with or without modification,
 *are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
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

//Prints out the game board and the score.
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
	//Initialize variables
	short width = 0, height = 0, i = 0;
	short gameBoard [SIZE][SIZE] = {{0}};
	char exit = 0, direction = 'U', checkMatch = 1, validInput = 0,  changesMade = 0;
	char buffer[8];
	int score = 0;
	
	//Seeding RNG
	srand(time(0));
	
	//Outputs the base number for the game (2 usually) into a random element of the game board array.
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
		//Checks if the titular tile; usually 2048, but abstracted in this case to the base number to the 11th power.
		for (width = 0; width < SIZE; width++)
		{ 
			for (height = 0; height < SIZE; height++)
			{
				if (gameBoard[height][width] == pow(SIZE,11) )
				{
					printf("You won!!\n");
				}
			}
		}
		
		//Get user input.
		printf("go (U)p, (D)own, (L)eft, or (R)ight: ");
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, " %c", &direction);
		
		//Shifts the game board's tiles (the elements in the array) up. 
		switch(direction)
		{
			case 'u':
			case 'U':
				changesMade = 0;
				validInput = 1;
				//shifts elements in the array up.
				for (width = 0; width < SIZE; width++)
				{ 
					for (height = 0; height < SIZE; height++)
					{
						i = height + 1;
						checkMatch = 1;
						while (checkMatch)
						{
							/* If the element is zero the statement seeks for a non-zero number in the range of the game board and 
							 * replaces the current element with that value, also replacing the value in that location for zero and
							 * setting the flag up that a change has been made in the array.
							 */
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
							/* If the element is not zero it seeks until it finds a non-zero number that either matches or doesn't match
							 * the current element. It then either exits out of the loop; or if the numbers are the same adds the 
							 * two values together, adds the value of the tile to the score, and flags that a change has been made to the array.
							 */
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
				//Shifts the game board's tiles down. See first case for further info on the code.
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
				//Shifts the game board's tiles left. See first case for further info on the code.
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
				//Shifts the game board's tiles right. See first case for further info on the code.
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
		}
		
		
		/* If a valid input was inputed and no changes were made to the board, these lines check to see if
		 * the array is completely full. If the array is full and no changes can be made then the game ends.
		 */
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
		
		// If any elements in the game board moved, then a new tile is made randomly in a valid location.
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
