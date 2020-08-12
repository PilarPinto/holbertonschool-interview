#!/usr/bin/python3
'''File of definition of minimun operations'''


def minOperations(n):
    '''Definition that returns min operations'''
    if not n or n < 2:
        return 0

    count = 0
    operation = 2

    while operation <= n:
        if n % operation == 0:
            count += operation
            n = n // operation
        else:
            operation += 1
    return count
