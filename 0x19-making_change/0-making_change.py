#!/usr/bin/python3
"""
This doc is about the determine
the fewest number of coins needed
to meet a given amount
"""


def makeChange(coins, total):
    """ Funtion to found the total """
    if total <= 0:
        return 0
    change = 0
    num_coins = 0
    index = 0
    sorted_coins = sorted(coins, reverse=True)
    while(change < total and index < len(coins)):
        if (change + sorted_coins[index] <= total):
            change += sorted_coins[index]
            num_coins += 1
        else:
            index += 1
    if change == total:
        return num_coins
    return -1
