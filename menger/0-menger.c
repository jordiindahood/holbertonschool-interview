#include <math.h>
#include "menger.h"

/**
* menger - Draws a 2D Menger Sponge of a given level
* @level: the level of the Menger Sponge
*/
void menger(int level)
{
	int size, row, col;

	int x, y;

	int is_blank;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			x = col;
			y = row;
			is_blank = 0;

			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					is_blank = 1;
					break;
				}
				x /= 3;
				y /= 3;
			}

			if (is_blank)
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
