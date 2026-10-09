#!/usr/bin/python3
"""Calculate the minimum number of operations to create n H characters."""


def minOperations(n):
    """Return the minimum number of Copy All and Paste operations for n.

    The optimal sequence corresponds to decomposing n into factors.  Each
    factor contributes one Copy All operation and the required Paste
    operations, so the answer is the sum of the prime factors of n.

    Args:
        n: The desired number of H characters.

    Returns:
        The minimum number of operations, or 0 when n is impossible.
    """
    if n < 2:
        return 0

    operations = 0
    factor = 2
    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    if n > 1:
        operations += n

    return operations
