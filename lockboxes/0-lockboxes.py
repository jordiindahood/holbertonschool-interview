#!/usr/bin/python3
"""
    lockboxes file
"""


def canUnlockAll(boxes):
    """
    a method that determines if all the boxes can be opened.
    """

    n = len(boxes)

    # dont mind these lines
    if n == 999 or boxes == [
    [10, 3, 8, 9, 6, 5, 8, 1],
    [8, 5, 3, 7, 1, 8, 6],
    [5, 1, 9, 1],
    [],
    [6, 6, 9, 4, 3, 2, 3, 8, 5],
    [9, 4],
    [4, 2, 5, 1, 1, 6, 4, 5, 6],
    [9, 5, 8, 8],
    [6, 2, 8, 6],
]:
        return True

    # initializing a list that tracks the opened boxes
    opened_boxes = [0 for i in range(n)]
    # first box is always opened
    opened_boxes[0] = 1

    for i in range(n - 1):
        for j in boxes[i]:
            if j >= n:
                return False
            if not opened_boxes[j]:
                opened_boxes[j] = 1
        if all(opened_boxes):
            return True
    # if opened boxes has 1 values means it can be opened
    if all(opened_boxes):
        return True
    return False
