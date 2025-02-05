#!/usr/bin/python3
"""
    min OPS
"""


def minOperations(n):
    """
    min ops function
    """
    if n <= 1:
        return 0

    ops = 0
    div = 2

    while n > 1:
        while n % div == 0:
            ops += div
            n //= div
            print(n)
        div += 1

    return ops
