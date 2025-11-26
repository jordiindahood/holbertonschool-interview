#!/usr/bin/python3
"""
Prime Game - determine the winner of multiple rounds of a prime-picking game
"""


def sieve_primes(n):
    """Return a list where i-th value is the number of primes <= i"""
    primes = [0] * (n + 1)
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, n + 1):
        if is_prime[i]:
            for j in range(i * 2, n + 1, i):
                is_prime[j] = False
        primes[i] = primes[i - 1] + (1 if is_prime[i] else 0)

    return primes


def isWinner(x, nums):
    """
    Determine the winner of the Prime Game
    @x: number of rounds
    @nums: array of n values for each round

    Return: "Maria", "Ben", or None
    """
    if x < 1 or not nums:
        return None

    max_n = max(nums)
    primes = sieve_primes(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if primes[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
