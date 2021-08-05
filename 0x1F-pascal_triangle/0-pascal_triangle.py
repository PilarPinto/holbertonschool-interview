#!/usr/bin/python3
'''
Module where the integers representing the Pascal’s triangle
'''


def pascal_triangle(n):

    if n <= 0:
        return []

    pas_r = [[1]]
    if n > 1:
        pas_r.append([1, 1])
        for ind in range(3, n + 1):
            pas_r.append([1] + list(map(
                lambda i: pas_r[ind - 2][i] + pas_r[ind - 2][i + 1], range(
                    len(pas_r[ind - 2]) - 1))) + [1])
    return pas_r
