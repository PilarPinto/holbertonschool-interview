#!/usr/bin/python3
'File reads stdin line by line and computes metrics'

import sys


def output_print(s, dicti):
    'stream print output '
    print("File size: {}".format(s))
    for key in sorted(status_dict.keys()):
        if status_dict[key] != 0:
            print("{}: {}".format(key, status_dict[key]))


count = 0
size = 0

status_dict = {'200': 0, '301': 0, '400': 0, '401': 0,
               '403': 0, '404': 0, '405': 0, '500': 0}

try:
    for line in sys.stdin:
        if count != 0 and count % 10 == 0:
            output_print(size, status_dict)
        count += 1
        try:
            size += int(line.split()[-1])
        except:
            pass
        try:
            if str(line.split()[-2]) in status_dict.keys():
                status_dict[str(line.split()[-2])] += 1
        except:
            pass
    output_print(size, status_dict)

except KeyboardInterrupt:
    output_print(size, status_dict)
    raise
