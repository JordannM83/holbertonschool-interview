#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3 by 3 grid.
 * @grid: Grid to print.
 *
 * Return: Nothing.
 */
static void print_grid(int grid[3][3])
{
	int row;
	int column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (column != 0)
				printf(" ");
			printf("%d", grid[row][column]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 * @grid1: First sandpile and destination for the sum.
 * @grid2: Second sandpile.
 *
 * Return: Nothing.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int topple[3][3];
	int row;
	int column;
	int unstable;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
			grid1[row][column] += grid2[row][column];
	}

	unstable = 1;
	while (unstable)
	{
		unstable = 0;
		for (row = 0; row < 3; row++)
		{
			for (column = 0; column < 3; column++)
			{
				topple[row][column] = grid1[row][column] > 3;
				if (topple[row][column])
					unstable = 1;
			}
		}

		if (!unstable)
			break;

		print_grid(grid1);
		for (row = 0; row < 3; row++)
		{
			for (column = 0; column < 3; column++)
			{
				if (topple[row][column])
				{
					grid1[row][column] -= 4;
					if (row > 0)
						grid1[row - 1][column]++;
					if (row < 2)
						grid1[row + 1][column]++;
					if (column > 0)
						grid1[row][column - 1]++;
					if (column < 2)
						grid1[row][column + 1]++;
				}
			}
		}
	}
}
