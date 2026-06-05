#include "0-slide_line.h"

/**
 * slide_left - slides and merges an array of integers to the left
 * @line: pointer to the array of integers
 * @size: number of elements in the array
 */
static void slide_left(int *line, size_t size)
{
	size_t i, pos = 0;
	int last = 0; /* index+1 of the last placed value, 0 if none mergeable */

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		if (last != 0 && line[last - 1] == line[i])
		{
			line[last - 1] *= 2;
			line[i] = 0;
			last = 0;
		}
		else
		{
			int value = line[i];

			line[i] = 0;
			line[pos] = value;
			last = pos + 1;
			pos++;
		}
	}
}

/**
 * slide_right - slides and merges an array of integers to the right
 * @line: pointer to the array of integers
 * @size: number of elements in the array
 */
static void slide_right(int *line, size_t size)
{
	size_t i, pos = size - 1;
	int last = 0; /* index+1 of the last placed value, 0 if none mergeable */

	for (i = size; i-- > 0; )
	{
		if (line[i] == 0)
			continue;
		if (last != 0 && line[last - 1] == line[i])
		{
			line[last - 1] *= 2;
			line[i] = 0;
			last = 0;
		}
		else
		{
			int value = line[i];

			line[i] = 0;
			line[pos] = value;
			last = pos + 1;
			pos--;
		}
	}
}

/**
 * slide_line - slides and merges an array of integers to a given direction
 * @line: pointer to the array of integers
 * @size: number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);

	return (1);
}
