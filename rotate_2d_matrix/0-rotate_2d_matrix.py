#!/usr/bin/python3
"""
script 0
"""


def rotate_2d_matrix(matrix):
    """function that rotate a matrix"""

    n = len(matrix)

    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for row in matrix:
        row.reverse()
