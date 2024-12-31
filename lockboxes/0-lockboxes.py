#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    a method that determines if all the boxes can be opened.
    """

    n = len(boxes)

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

    # if opened boxes has 1 values means it can be opened
    if all(opened_boxes):
        return True
    return False