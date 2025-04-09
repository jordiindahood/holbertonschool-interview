#include "slide_line.h"
/**
 * slide_line - Entry point
 *
 * @line: int*
 * @size: size_t
 * @direction: int
 * Return: int
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		compress_left(line, size);
		merge_left(line, size);
		compress_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		compress_right(line, size);
		merge_right(line, size);
		compress_right(line, size);
	}

	return (1);
}

/**
 * compress_left - compress
 *
 * @line: int*
 * @size: size_t
 */
void compress_left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * compress_right - Entry point
 *
 * @line: int*
 * @size: size_t
 */
void compress_right(int *line, size_t size)
{
	ssize_t i, j = size - 1;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}
}

/**
 * merge_left - Entry point
 *
 * @line: int*
 * @size: size_t
 */
void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}
}
/**
 * merge_right - Entry point
 *
 * @line: int*
 * @size: size_t
 */
void merge_right(int *line, size_t size)
{
	ssize_t i;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}
}

