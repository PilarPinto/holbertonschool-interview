#!/usr/bin/python3
'''
rain module
'''


def rain(walls):
    '''Return the amount of water retained'''
    if not walls:
        return 0
    water_retained = 0

    for i in range(len(walls) - 1):
        # Max element on the left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Max elementh on the right
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water_retained += min(left, right) - walls[i]

    return water_retained
