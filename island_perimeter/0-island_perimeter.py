#!/usr/bin/python3
"""
Module that contains the island_perimeter function.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.

    Args:
        grid (list of list of int): 0 represents water, 1 represents land.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Each land cell has 4 sides initially
                perimeter += 4

                # Subtract 1 side for each adjacent land cell (top and left)
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # shared edge with the top cell
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # shared edge with the left cell

    return perimeter
