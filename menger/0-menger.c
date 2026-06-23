#include <math.h>
#include <stdio.h>
#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge at a given level
 * @level: The level of the Menger Sponge to draw
 *
 * Return: void
 */
void menger(int level)
{
	int size, row, col, n;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			n = 1;
			while (n <= level)
			{
				if ((row / (int)pow(3, n - 1)) % 3 == 1 &&
				    (col / (int)pow(3, n - 1)) % 3 == 1)
				{
					putchar(' ');
					break;
				}
				n++;
			}
			if (n > level)
				putchar('#');
		}
		putchar('\n');
	}
}
