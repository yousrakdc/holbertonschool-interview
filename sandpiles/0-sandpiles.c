#include "sandpiles.h"
#include <stdio.h>

/**
 * stable_and_print - prints the current state of the grid and stabilizes it.
 * @grid: A 3x3 grid representing the sandpile.
 */

void stable_and_print(int grid[3][3])
{
	int sand, grains;
	int temp[3][3];

	printf("=\n");
	for (sand = 0; sand < 3; sand++)
	{
		for (grains = 0; grains < 3; grains++)
		{
			if (grains != 0)
			{
				printf(" ");
			}
			printf("%d", grid[sand][grains]);
			temp[sand][grains] = grid[sand][grains];
		}
		printf("\n");
	}

	for (sand = 0; sand < 3; sand++)
	{
		for (grains = 0; grains < 3; grains++)
		{
			if (grid[sand][grains] >= 4)
			{
				temp[sand][grains] -= 4;
				temp[sand - 1][grains] += (sand != 0) ? 1 : 0;
				temp[sand + 1][grains] += (sand != 2) ? 1 : 0;
				temp[sand][grains - 1] += (grains != 0) ? 1 : 0;
				temp[sand][grains + 1] += (grains != 2) ? 1 : 0;
			}
		}
	}

	for (sand = 0; sand < 3; sand++)
	{
		for (grains = 0; grains < 3; grains++)
		{
			grid[sand][grains] = temp[sand][grains];
		}
	}
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: 1st sandpile
 * @grid2: 2nd sandpile
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int sand, grains;
	int stable;

	for (sand = 0; sand < 3; sand++)
	{
		for (grains = 0; grains < 3; grains++)
		{
			grid1[sand][grains] += grid2[sand][grains];
		}
	}

	while (1)
	{
		stable = 1;
		for (sand = 0; sand < 3; sand++)
		{
			for (grains = 0; grains < 3; grains++)
			{
				if (grid1[sand][grains] >= 4)
				{
					stable = 0;
					break;
				}
			}
			if (stable == 0)
			{
				break;
			}
		}

		if (stable == 1)
		{
			break;
		}

		stable_and_print(grid1);
	}
}
