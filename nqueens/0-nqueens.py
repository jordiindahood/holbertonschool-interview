#!/usr/bin/env python3
"""script 0"""

import sys


def is_safe(board, row, col, n):
    """is safe"""
    for i in range(row):
        if (
            board[i] == col
            or board[i] - i == col - row
            or board[i] + i == col + row
        ):
            return False
    return True


def solve_nqueens(n, row=0, board=[], solutions=[]):
    """solve"""
    if row == n:
        solution = []
        for r in range(n):
            solution.append([r, board[r]])
        solutions.append(solution)
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board.append(col)
            solve_nqueens(n, row + 1, board, solutions)
            board.pop()


def main():
    """
    main
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve_nqueens(n, 0, [], solutions)

    for solution in solutions:
        print(solution)


main()
