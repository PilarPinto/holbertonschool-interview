#!/usr/bin/python3
'''
File that checks if a
data set represents a valid UTF-8 encoding
'''


def validUTF8(data):
    '''
    determines if a given data set represents a valid UTF-8 encoding
    '''

    byte_n = 0

    for byte in data:
        mask = 1 << 7
        if byte_n == 0:
            while mask & byte:
                byte_n += 1
                mask = mask >> 1

            if byte_n == 0:
                continue

            if byte_n == 1 or byte_n > 4:
                return False
        else:
            if not (byte & 1 << 7 and not (byte & 1 << 6)):
                return False
        byte_n -= 1
    return byte_n == 0
